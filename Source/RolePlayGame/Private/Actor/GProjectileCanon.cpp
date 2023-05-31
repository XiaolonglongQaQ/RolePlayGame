

#include "Actor/GProjectileCanon.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AGProjectileCanon::AGProjectileCanon()
{
	PrimaryActorTick.bCanEverTick = true;

	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComp"));
	RootComponent = ArrowComp;
	ArrowComp->bHiddenInGame = false;
}
void AGProjectileCanon::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle,this,&AGProjectileCanon::SpawnProjectile_TimeElapsed,2.0f,true);
	
}

void AGProjectileCanon::SpawnProjectile_TimeElapsed()
{
	if (ensure(Projectileclass))
	{
		FTransform SpawnTM = GetActorTransform();
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<AActor>(Projectileclass,SpawnTM,SpawnParameters);
	}

}

void AGProjectileCanon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* MyPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	FVector Start;
	FVector Target;
	FRotator NewRotation;
	if (MyPawn)
	{
		Start = GetActorLocation();
		Target = MyPawn->GetActorLocation();
		NewRotation = UKismetMathLibrary::FindLookAtRotation(Start,Target);
	}
	ArrowComp->SetWorldRotation(NewRotation);
}

