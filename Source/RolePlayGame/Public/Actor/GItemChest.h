// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/GGameplayInterface.h"
#include "GItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class ROLEPLAYGAME_API AGItemChest : public AActor,public IGGameplayInterface
{
	GENERATED_BODY()
	

public:	
	AGItemChest();
	virtual void Tick(float DeltaTime) override;
	void Interact_Implementation(APawn* InstigatorPawn);

public:
	UPROPERTY(EditAnywhere)
	float TargetPitch;
protected:
	virtual void BeginPlay() override;
protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;


};
