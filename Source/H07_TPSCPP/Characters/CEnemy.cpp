#include "CEnemy.h"
#include "Global.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/WidgetComponent.h"
#include "Components/CActionComponent.h"
#include "Components/CMontageComponent.h"
#include "Components/CStatusComponent.h"
#include "Components/CStateComponent.h"
#include "Widgets/CNameWidget.h"
#include "Widgets/CHealthWidget.h"

ACEnemy::ACEnemy()
{
	//-------------------------------------------------------------------------
	//Create Scene Component
	//-------------------------------------------------------------------------
	CHelpers::CreateSceneComponent(this, &NameWidget, "NameWidget", GetMesh());
	CHelpers::CreateSceneComponent(this, &HealthWidget, "HealthWidget", GetMesh());

	//-------------------------------------------------------------------------
	//Create Actor Component
	//-------------------------------------------------------------------------
	CHelpers::CreateActorComponent(this, &Action, "Action");
	CHelpers::CreateActorComponent(this, &Montage, "Montage");
	CHelpers::CreateActorComponent(this, &Status, "Status");
	CHelpers::CreateActorComponent(this, &State, "State");

	//-------------------------------------------------------------------------
	//Component Settings
	//-------------------------------------------------------------------------
	// -> MeshComp
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	USkeletalMesh* meshAsset;
	CHelpers::GetAsset(&meshAsset, "/Game/Character/ZLorp/Mesh/ZLorp");
	GetMesh()->SetSkeletalMesh(meshAsset);

	TSubclassOf<UAnimInstance> animInstanceClass;
	CHelpers::GetClass(&animInstanceClass, "/Game/Enemies/ABP_CEnemy");
	GetMesh()->SetAnimInstanceClass(animInstanceClass);

	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0);
	GetCharacterMovement()->MaxWalkSpeed = Status->GetRunSpeed();

	//-> WidgetComp
	TSubclassOf<UCNameWidget> nameWidgetClass;
	CHelpers::GetClass<UCNameWidget>(&nameWidgetClass, "/Game/Widgets/WB_Name");
	NameWidget->SetWidgetClass(nameWidgetClass);
	NameWidget->SetRelativeLocation(FVector(0, 0, 240));
	NameWidget->SetDrawSize(FVector2D(240, 30));
	NameWidget->SetWidgetSpace(EWidgetSpace::Screen);

	TSubclassOf<UCHealthWidget> healthWidgetClass;
	CHelpers::GetClass<UCHealthWidget>(&healthWidgetClass, "/Game/Widgets/WB_Health");
	HealthWidget->SetWidgetClass(healthWidgetClass);
	HealthWidget->SetRelativeLocation(FVector(0, 0, 190));
	HealthWidget->SetDrawSize(FVector2D(120, 20));
	HealthWidget->SetWidgetSpace(EWidgetSpace::Screen);
}

void ACEnemy::BeginPlay()
{
	LowerBodyMaterial = UMaterialInstanceDynamic::Create(GetMesh()->GetMaterial(0), nullptr);
	UpperBodyMaterial = UMaterialInstanceDynamic::Create(GetMesh()->GetMaterial(1), nullptr);

	GetMesh()->SetMaterial(0, LowerBodyMaterial);
	GetMesh()->SetMaterial(1, UpperBodyMaterial);

	Super::BeginPlay();

	NameWidget->InitWidget();
	UCNameWidget* nameWidgetObject = Cast<UCNameWidget>(NameWidget->GetUserWidgetObject());
	if (!!nameWidgetObject)
		nameWidgetObject->SetNameText(GetController()->GetName(), GetName());
	
	HealthWidget->InitWidget();
	UCHealthWidget* healthWidgetObject = Cast<UCHealthWidget>(HealthWidget->GetUserWidgetObject());
	if (!!healthWidgetObject)
		healthWidgetObject->Update(Status->GetCurrentHealth(), Status->GetMaxHealth());
}

void ACEnemy::ChangeColor(FLinearColor InColor)
{
	LowerBodyMaterial->SetVectorParameterValue("Emissive", InColor);
	UpperBodyMaterial->SetVectorParameterValue("Emissive", InColor);
}

