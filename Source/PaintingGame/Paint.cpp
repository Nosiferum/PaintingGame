// Fill out your copyright notice in the Description page of Project Settings.


#include "Paint.h"

#include "MaterialInstanceCreator.h"


UPaint::UPaint()
{
	PrimaryComponentTick.bCanEverTick = true;

	//LoadedPaintingMaterial = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Materials/MT_Blue.MT_Blue'"));
}

void UPaint::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
}

void UPaint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	PaintWall();
}

void UPaint::PaintWall() 
{
	FHitResult HitResult;
	const FVector Start = GetOwner()->GetActorLocation();
	const FVector End = Start + GetOwner()->GetActorForwardVector() * 50;

	//DrawDebugCapsule(World, End, 20, 10,FQuat::Identity, FColor::Blue, false, 5);
	
	/*if (World->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, FCollisionShape::MakeCapsule(20, 10)))
	{
		if (UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(HitResult.GetComponent()))
		{
			MyMaterialInstance = UMaterialInstanceDynamic::Create(LoadedPaintingMaterial, this);
			MyMaterialInstance->SetVectorParameterValue("Color", FLinearColor::Red);

			StaticMesh->SetMaterial(0, MyMaterialInstance);
		}
	}*/
	
	/*if (World->LineTraceSingleByChannel(HitResult, Start, End, ECC_GameTraceChannel2))
	{
		if (UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(HitResult.GetComponent()))
		{
			MyMaterialInstance = UMaterialInstanceDynamic::Create(LoadedPaintingMaterial, this);
			MyMaterialInstance->SetVectorParameterValue("Color", FLinearColor::Red);

			StaticMesh->SetMaterial(0, MyMaterialInstance);
			
			FVector UV;
				UV = HitResult.ImpactPoint - HitResult.Normal * FVector::DotProduct(HitResult.ImpactPoint, HitResult.Normal);	
		}
	}*/

	if (World->LineTraceSingleByChannel(HitResult, Start, End, ECC_GameTraceChannel2))
	{
		/*if (UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(HitResult.GetComponent()))
		{
			MyMaterialInstance = UMaterialInstanceDynamic::Create(StaticMesh->GetMaterial(0), StaticMesh);
			MyMaterialInstance->SetVectorParameterValue("Color", FLinearColor::Red);

			StaticMesh->SetMaterial(0, MyMaterialInstance);
			
			
		}*/

		if (const UMaterialInstanceCreator* MaterialInstanceCreator = HitResult.Component->GetOwner()->FindComponentByClass<UMaterialInstanceCreator>())
		{
			MaterialInstanceCreator->PaintWall();
		}
	}
	
}

