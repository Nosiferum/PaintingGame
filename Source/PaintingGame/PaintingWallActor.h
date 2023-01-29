// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaintingWallActor.generated.h"

UCLASS()
class PAINTINGGAME_API APaintingWallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintingWallActor();

protected:
	UPROPERTY(BlueprintReadOnly)
	UMaterialInstanceDynamic* MyMaterialInstance;
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UMaterial* LoadedPaintingMaterial;

};
