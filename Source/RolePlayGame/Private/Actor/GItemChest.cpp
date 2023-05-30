

#include "Actor/GItemChest.h"

void AGItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(TargetPitch,0.f,0.f));
}

AGItemChest::AGItemChest()
{
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	TargetPitch = 110.0f;
}
void AGItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}
void AGItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

