
#include "MaterialInstanceCreator.h"

UMaterialInstanceCreator::UMaterialInstanceCreator()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UMaterialInstanceCreator::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	MyMaterialInstance = UMaterialInstanceDynamic::Create(StaticMesh->GetMaterial(0), this);
}

void UMaterialInstanceCreator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMaterialInstanceCreator::PaintWall() const
{
	MyMaterialInstance->SetVectorParameterValue("Color", FLinearColor::Yellow);

	StaticMesh->SetMaterial(0, MyMaterialInstance);
}

