#include "CHUD.h"
#include "Global.h"
#include "Engine/Texture2D.h"
#include "Engine/Canvas.h"

ACHUD::ACHUD()
{
	CHelpers::GetAsset(&CrossHairTexture, "/Game/Player/FirstPersonCrosshair");
}

void ACHUD::DrawHUD()
{
	Super::DrawHUD();
	CheckFalse(bVisible);

	const FVector2D center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D imageHalfSize(CrossHairTexture->GetSurfaceWidth() * 0.5, CrossHairTexture->GetSurfaceHeight() * 0.5f);
	const FVector2D imagePosition(center.X - imageHalfSize.X, center.Y - imageHalfSize.Y);

	FCanvasTileItem imageItem(imagePosition, CrossHairTexture->Resource, FLinearColor::White);
	imageItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(imageItem);
}