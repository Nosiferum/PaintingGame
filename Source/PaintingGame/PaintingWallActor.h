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
	virtual void BeginPlay() override;
	void CheckForPlayerInputToChange() const;
	void ClearPaintingWall();

public:	
	virtual void Tick(float DeltaTime) override;
	void SetBrushSize(float BrushSize) const;
	void SetStaticMeshMaterialColor(FLinearColor LinearColor) const;

private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UMaterialInstanceDynamic* MyMaterialInstance;
	UMaterial* LoadedPaintingMaterial;
	UStaticMeshComponent* StaticMesh; 
	UMaterialInterface* StaticMeshMaterial;
	UMaterialInstanceDynamic* MyStaticMaterialInstance;
	APlayerController* PlayerController;
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	bool IsErasable = false;

};
