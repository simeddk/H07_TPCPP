#include "CStateComponent.h"
#include "Global.h"

#define PRINT_DEBUG

UCStateComponent::UCStateComponent()
{

}


void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCStateComponent::SetIdleMode()
{
	ChangeType(EStateType::Idle);
}

void UCStateComponent::SetRollMode()
{
	ChangeType(EStateType::Roll);
}

void UCStateComponent::SetBackStepMode()
{
	ChangeType(EStateType::BackStep);
}

void UCStateComponent::ChangeType(EStateType InNewType)
{
	EStateType prev = Type;
	Type = InNewType;

#ifdef PRINT_DEBUG
	PrintType();
#endif

	if (OnStateTypeChanged.IsBound())
		OnStateTypeChanged.Broadcast(prev, InNewType);
}

void UCStateComponent::PrintType()
{
	FString typeStr;
	switch (Type)
	{
		case EStateType::Idle:		typeStr = "Idle";		break;
		case EStateType::Roll:		typeStr = "Roll";		break;
		case EStateType::BackStep:	typeStr = "BackStep";	break;
	}
	CLog::Log("CurrentState : " + typeStr);
}
