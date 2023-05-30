
#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Component/GInteractionComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "GCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UGInteractionComponent;

UCLASS()
class ROLEPLAYGAME_API AGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGCharacter();
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void PrimaryAttack();
	void PrimaryInteract();
protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere)
	UGInteractionComponent* InteractionComp;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> Projectileclass;
	

};
