
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GGameplayInterface.generated.h"

UINTERFACE(MinimalAPI)
class UGGameplayInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ROLEPLAYGAME_API IGGameplayInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void Interact(APawn* InstigatorPawn);
};
