
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GCharacter.generated.h"

UCLASS()
class ROLEPLAYGAME_API AGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
