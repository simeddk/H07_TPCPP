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
		Equipment->AttachToComponent(InOwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
		Equipment->SetData(EquipmentData);
		Equipment->SetColor(EquipmentColor);
		Equipment->SetActorLabel(GetCustomLabelName(InOwnerCharacter, "Equipment"));
		UGameplayStatics::FinishSpawningActor(Equipment, transform);
	}
}

FString UCActionData::GetCustomLabelName(ACharacter* InOwnerCharacter, FString InMiddleName)
{
	FString labelName;
	labelName.Append(InOwnerCharacter->GetActorLabel());
	labelName.Append("_");
	labelName.Append(InMiddleName);
	labelName.Append("_");
	labelName.Append(GetName().Replace(L"DA_", L""));

	return labelName;
}
