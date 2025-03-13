// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Struct_Wall.generated.h"

USTRUCT(BlueprintType)
struct FStructWall
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FVector> Wall0To1;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool ConnectedQM;
};