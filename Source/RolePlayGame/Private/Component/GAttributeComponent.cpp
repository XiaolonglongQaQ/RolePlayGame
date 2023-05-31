


#include "Component/GAttributeComponent.h"

UGAttributeComponent::UGAttributeComponent()
{
	Health = 100.0f;
}

bool UGAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;
	OnHealthChanged.Broadcast(nullptr,this,Health,Delta);
	return true;
}

