
#include "PaintingWallActor.h"

APaintingWallActor::APaintingWallActor()
{
	PrimaryActorTick.bCanEverTick = true;

	LoadedPaintingMaterial = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Materials/MT_Painter.MT_Painter'"));
}

void APaintingWallActor::BeginPlay()
{
	Super::BeginPlay();

	MyMaterialInstance = UMaterialInstanceDynamic::Create(LoadedPaintingMaterial, this);
	
}

void APaintingWallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

