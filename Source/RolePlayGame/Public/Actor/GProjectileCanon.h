
#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "GProjectileCanon.generated.h"

class UArrowComponent;

UCLASS()
class ROLEPLAYGAME_API AGProjectileCanon : public AActor
{
	GENERATED_BODY()
	
public:	
	AGProjectileCanon();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	void SpawnProjectile_TimeElapsed();
protected:
	UPROPERTY(VisibleAnywhere)
	UArrowComponent* ArrowComp;
	UPROPERTY(EditAnywhere,Category="Attack")
	TSubclassOf<AActor> Projectileclass;

	FTimerHandle SpawnTimerHandle;

};
