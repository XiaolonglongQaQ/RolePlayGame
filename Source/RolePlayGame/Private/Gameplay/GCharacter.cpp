
#include "Gameplay/GCharacter.h"


AGCharacter::AGCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
}
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
}


void AGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&AGCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
}

