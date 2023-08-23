#pragma once

#include "CoreMinimal.h"
#include "Action/CDoAction.h"
#include "CDoAction_Melee.generated.h"

UCLASS()
class H07_TPSCPP_API ACDoAction_Melee : public ACDoAction
{
	GENERATED_BODY()
	
public:
	virtual void DoAction() override;
	virtual void Begin_DoAction() override;
	virtual void End_DoAction() override;

	virtual void OnAttachmentBeginOverlap(class ACharacter* InAttacker, class AActor* InCauser, class ACharacter* InOtherCharacter) override;
	virtual void OnAttachmentEndOverlap(class ACharacter* InAttacker, class AActor* InCauser, class ACharacter* InOtherCharacter) override;

};
