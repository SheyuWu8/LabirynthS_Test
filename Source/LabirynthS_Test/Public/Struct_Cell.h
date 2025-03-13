// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Struct_Wall.h"
#include "Struct_Cell.generated.h"


USTRUCT(BlueprintType)
struct FStructCell
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool visited;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool current;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Neighbors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStructWall Wall_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStructWall Wall_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStructWall Wall_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStructWall Wall_3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DistanceToStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ExitWall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isExitWall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isAtBorder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Cell;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DeadEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Removed;


};
