

#include "Actor/GMagicProjectile.h"

#include "Component/GAttributeComponent.h"
#include "Kismet/GameplayStatics.h"

AGMagicProjectile::AGMagicProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionProfileName("Projectile");
	SphereComp->OnComponentBeginOverlap.AddDynamic(this,&AGMagicProjectile::OnActorOverlap);
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EffectComp"));
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComp"));
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;
	MovementComp->ProjectileGravityScale = 0.f;
}
void AGMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		UGAttributeComponent* AttributeComp = Cast<UGAttributeComponent>(OtherActor->GetComponentByClass(UGAttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			AttributeComp->ApplyHealthChange(-20.0f);
		}
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),HitWorldParticle,GetActorLocation(),GetActorRotation(),FVector(1.0f,1.0f,1.0f),true,EPSCPoolMethod::None,true);
		Destroy();
	}
	
	//DrawDebugSphere(GetWorld(),Hit.ImpactPoint,30.0f,32,FColor::Red,false,2.0f);
}



void AGMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

