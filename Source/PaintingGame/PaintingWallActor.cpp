
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

	StaticMeshMaterial = FindComponentByClass<UStaticMeshComponent>()->GetMaterial(0);
	MyStaticMaterialInstance = UMaterialInstanceDynamic::Create(StaticMeshMaterial, this);

	StaticMesh = FindComponentByClass<UStaticMeshComponent>();
	StaticMesh->SetMaterial(0, MyStaticMaterialInstance);

	PlayerController = GetWorld()->GetFirstPlayerController();
}

void APaintingWallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ClearPaintingWall();
	CheckForPlayerInputToChange();
}

void APaintingWallActor::ClearPaintingWall()
{
	if (PlayerController->IsInputKeyDown(EKeys::Z))
	{
		IsErasable = true;
	}

	else
	{
		IsErasable = false;
	}
}

void APaintingWallActor::CheckForPlayerInputToChange() const
{
	if (PlayerController->IsInputKeyDown(EKeys::F))
	{
		SetStaticMeshMaterialColor(FLinearColor::Red);
	}

	else if (PlayerController->IsInputKeyDown(EKeys::G))
	{
		SetStaticMeshMaterialColor(FLinearColor::Green);
	}

	else if (PlayerController->IsInputKeyDown(EKeys::H))
	{
		SetStaticMeshMaterialColor(FLinearColor::Blue);
	}

	if (PlayerController->IsInputKeyDown(EKeys::R))
	{
		SetBrushSize(0.5f);
	}

	else if (PlayerController->IsInputKeyDown(EKeys::T))
	{
		SetBrushSize(1);
	}

	else if (PlayerController->IsInputKeyDown(EKeys::Y))
	{
		SetBrushSize(0.1f);
	}
}

void APaintingWallActor::SetBrushSize(const float BrushSize) const
{
	MyMaterialInstance->SetScalarParameterValue("Draw Size", BrushSize);
}

void APaintingWallActor::SetStaticMeshMaterialColor(const FLinearColor LinearColor) const
{
	MyStaticMaterialInstance->SetVectorParameterValue("UV", LinearColor);
}