// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/GInteractionComponent.h"

#include "Interface/GGameplayInterface.h"

// Sets default values for this component's properties
UGInteractionComponent::UGInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	AActor* MyOwner = GetOwner();
	
	FVector EyeLocayion;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocayion,EyeRotation);
	FVector End = EyeLocayion+(EyeRotation.Vector()*1000.0f);
	
	/*FHitResult Hit;
	bool bBlockingHit = GetWorld()->LineTraceSingleByObjectType(Hit,EyeLocayion,End,ObjectQueryParams);*/

	TArray<FHitResult> Hits;
	FCollisionShape Shape;
	float Radius = 30.f;
	Shape.SetSphere(Radius);
	bool bBlockingHit = GetWorld()->SweepMultiByObjectType(Hits,EyeLocayion,End,FQuat::Identity,ObjectQueryParams,Shape);

	FColor LineColor = bBlockingHit? FColor::Green : FColor::Red;
	DrawDebugLine(GetWorld(),EyeLocayion,End,LineColor,false,2.0f,0.f,2.0f);

	for(FHitResult Hit:Hits)
	{
		AActor* HitActor = Hit.GetActor();
		if (HitActor)
		{
			if (HitActor->Implements<UGGameplayInterface>())
			{
				APawn* MyPawn = Cast<APawn>(MyOwner);
				IGGameplayInterface::Execute_Interact(HitActor,MyPawn);

				DrawDebugSphere(GetWorld(),Hit.ImpactPoint,Radius,32,LineColor,false,2.0f);
				break;
			}
		}
	}
}

