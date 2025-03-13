// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Struct_Wall0To1.generated.h"

USTRUCT(BlueprintType)
struct FStructWall0To1
{
	GENERATED_BODY()



	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector WallStart;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector WallEnd;
};