
#include "Gameplay/GCharacter.h"


AGCharacter::AGCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void AGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

