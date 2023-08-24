#include "CDoAction_Melee.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Components/CStateComponent.h"
#include "Components/CStatusComponent.h"

void ACDoAction_Melee::DoAction()
{
	Super::DoAction();
	CheckFalse(Datas.Num() > 0);

	//Succeed Combo
	if (bCanCombo == true)
	{
		bCanCombo = false;
		bSucceed = true;

		return;
	}

	//First Attack
	CheckFalse(StateComp->IsIdleMode());
	StateComp->SetActionMode();

	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRate, Datas[0].StartSection);
	Datas[0].bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();
}

void ACDoAction_Melee::Begin_DoAction()
{
	Super::Begin_DoAction();
	
	CheckFalse(bSucceed);
	bSucceed = false;
	
	ComboCount++;
	ComboCount = FMath::Clamp(ComboCount, 0, Datas.Num() - 1);

	OwnerCharacter->StopAnimMontage();
	OwnerCharacter->PlayAnimMontage(Datas[ComboCount].AnimMontage, Datas[ComboCount].PlayRate, Datas[ComboCount].StartSection);
	Datas[ComboCount].bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();
}

void ACDoAction_Melee::End_DoAction()
{
	Super::End_DoAction();

	OwnerCharacter->StopAnimMontage();
	ComboCount = 0;

	StateComp->SetIdleMode();
	StatusComp->SetMove();
}

void ACDoAction_Melee::OnAttachmentBeginOverlap(ACharacter* InAttacker, AActor* InCauser, ACharacter* InOtherCharacter)
{
	Super::OnAttachmentBeginOverlap(InAttacker, InCauser, InOtherCharacter);

	int32 hittedCharactersNum = HittedCharacters.Num();
	HittedCharacters.AddUnique(InOtherCharacter);

	//Todo. HitStop

	if (hittedCharactersNum < HittedCharacters.Num())
	{
		FDamageEvent damageEvent;

		InOtherCharacter->TakeDamage
		(
			Datas[ComboCount].Power,
			damageEvent,
			InAttacker->GetController(),
			InCauser
		);
	}
	
}

void ACDoAction_Melee::OnAttachmentEndOverlap(ACharacter* InAttacker, AActor* InCauser, ACharacter* InOtherCharacter)
{
	Super::OnAttachmentEndOverlap(InAttacker, InCauser, InOtherCharacter);
}
