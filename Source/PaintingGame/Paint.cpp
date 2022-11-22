// Fill out your copyright notice in the Description page of Project Settings.


#include "Paint.h"

UPaint::UPaint()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPaint::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
}

void UPaint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//PaintWall();
}

void UPaint::PaintWall() const
{
	FHitResult HitResult;
	const FVector Start = GetOwner()->GetActorLocation();
	const FVector End = Start + GetOwner()->GetActorForwardVector() * 50;

	DrawDebugCapsule(World, End, 20, 10,FQuat::Identity, FColor::Blue, false, 5);
	
	if (World->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, FCollisionShape::MakeCapsule(20, 10)))
	{
		//HitResult.GetActor()->FindComponentByClass<UStaticMesh>();
	}
	

	
	
}

