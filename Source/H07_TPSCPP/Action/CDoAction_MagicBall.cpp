#include "CDoAction_MagicBall.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Components/CStateComponent.h"
#include "Components/CStatusComponent.h"
#include "CAim.h"

void ACDoAction_MagicBall::BeginPlay()
{
	Super::BeginPlay();

	Aim = NewObject<UCAim>();
	Aim->BeginPlay(OwnerCharacter);
}

void ACDoAction_MagicBall::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	CheckNull(Aim);
	Aim->Tick(Deltatime);
}

void ACDoAction_MagicBall::DoAction()
{
	CheckFalse(Aim->IsAvaliable());
	CheckFalse(Aim->IsAiming());

	CheckFalse(StateComp->IsIdleMode());
	StateComp->SetActionMode();

	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRate, Datas[0].StartSection);
	Datas[0].bCanMove ? StatusComp->SetMove() : StatusComp->SetStop();
}

void ACDoAction_MagicBall::Begin_DoAction()
{
	//Todo. Spawn Projectile Class
}

void ACDoAction_MagicBall::End_DoAction()
{
	StateComp->SetIdleMode();
	StatusComp->SetMove();
}

void ACDoAction_MagicBall::OnAim()
{
	CheckNull(Aim);
	Aim->On();
}

void ACDoAction_MagicBall::OffAim()
{
	CheckNull(Aim);
	Aim->Off();
}
