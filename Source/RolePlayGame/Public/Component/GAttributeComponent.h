
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged,AActor*, InstigatorActor,UGAttributeComponent*, OwningComp,float, NewHealth,float, Delta);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROLEPLAYGAME_API UGAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGAttributeComponent();
	
	UFUNCTION(BlueprintCallable,Category="Attributes")
	bool ApplyHealthChange(float Delta);
public:
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
protected:


protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Attributes")
	float Health;
	


		
};
