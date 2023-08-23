#include "CDoAction_Melee.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Components/CStateComponent.h"
#include "Components/CStatusComponent.h"

void ACDoAction_Melee::DoAction()
{
	Super::DoAction();
	CheckFalse(Datas.Num() > 0);

	CheckFalse(StateComp->IsIdleMode());
	StateComp->SetActionMode();

	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRate, Datas[0].StartSection);
	Datas[0].bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();
}

void ACDoAction_Melee::Begin_DoAction()
{
	Super::Begin_DoAction();
	//Combo
	
}

void ACDoAction_Melee::End_DoAction()
{
	Super::End_DoAction();

	StateComp->SetIdleMode();
	StatusComp->SetMove();
}

void ACDoAction_Melee::OnAttachmentBeginOverlap(ACharacter* InAttacker, AActor* InCauser, ACharacter* InOtherCharacter)
{
	Super::OnAttachmentBeginOverlap(InAttacker, InCauser, InOtherCharacter);

	//Todo. 2323 대미지 주기....
	FString attacker = InAttacker->GetName();
	FString causer = InCauser->GetName();
	FString otherCharacter = InOtherCharacter->GetName();

	CLog::Print("OtherCharacter : " + otherCharacter);
	CLog::Print("Causer : " + causer);
	CLog::Print("Attacker : " + attacker);
}

void ACDoAction_Melee::OnAttachmentEndOverlap(ACharacter* InAttacker, AActor* InCauser, ACharacter* InOtherCharacter)
{
	Super::OnAttachmentEndOverlap(InAttacker, InCauser, InOtherCharacter);
}
