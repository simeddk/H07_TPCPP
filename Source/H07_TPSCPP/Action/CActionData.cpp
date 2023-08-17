#include "CActionData.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Action/CEquipment.h"

void UCActionData::BeginPlay(class ACharacter* InOwnerCharacter)
{
	FTransform transform;

	if (!!EquipmentClass)
	{
		Equipment = InOwnerCharacter->GetWorld()->SpawnActorDeferred<ACEquipment>(EquipmentClass, transform, InOwnerCharacter);
		//Todo. 설명 더하기...
		UGameplayStatics::FinishSpawningActor(Equipment, transform);
	}
}