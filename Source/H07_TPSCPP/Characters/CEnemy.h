#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ICharacter.h"
#include "CEnemy.generated.h"

UCLASS()
class H07_TPSCPP_API ACEnemy : public ACharacter, public IICharacter
{
	GENERATED_BODY()

public:
	ACEnemy();

protected:
	virtual void BeginPlay() override;

public:
	virtual void ChangeColor(FLinearColor InColor) override;

private: //Scene Component
	UPROPERTY(VisibleDefaultsOnly)
		class UWidgetComponent* NameWidget;

	UPROPERTY(VisibleDefaultsOnly)
		class UWidgetComponent* HealthWidget;

private: //Actor Component
	UPROPERTY(VisibleDefaultsOnly)
		class UCActionComponent* Action;
	
	UPROPERTY(VisibleDefaultsOnly)
		class UCMontageComponent* Montage;
	
	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;
	
	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;

private:
	class UMaterialInstanceDynamic* LowerBodyMaterial;
	class UMaterialInstanceDynamic* UpperBodyMaterial;

};
