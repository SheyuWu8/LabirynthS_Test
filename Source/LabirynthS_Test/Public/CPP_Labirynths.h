// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include <Components/TextRenderComponent.h>
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SceneComponent.h"

#include "CPP_Labirynths.generated.h"


UENUM(BlueprintType)
enum class Enum_SetUpLabyrinth : uint8
{
	StartAt00 UMETA(DisplayName = "StartAt00"),
	StartAtRndAll UMETA(DisplayName = "StartAtRndAll"),
	StartRndAtBorder UMETA(DisplayName = "StartRndAtBorder"),
	StartRndInside UMETA(DisplayName = "StartRndInside"),
	StartAtCenter UMETA(DisplayName = "StartAtCenter"),
};
UENUM(BlueprintType)
enum class Enum_CellSpawnOptions : uint8
{
	AllCells UMETA(DisplayName = "AllCells"),
	StandardAddDeadEnds UMETA(DisplayName = "Standard+DeadEnds"),
	StandardAddDeadEndsAddRemoved UMETA(DisplayName = "Standard + DeadEnds + Removed"),
};
UENUM(BlueprintType)
enum class WallSpawnOptions : uint8
{
	AllWalls UMETA(DisplayName = "AllWalls"),
	OutterAndInnerWalls UMETA(DisplayName = "OutterAndInnerWalls"),
};

UENUM(BlueprintType)
enum class Enum_ColumnsSpawnOptions : uint8
{
	KolumnsNone UMETA(DisplayName = "Kolumns None"),
	KolumnsAll UMETA(DisplayName = "Kolumns All"),
	KolumnsOutter UMETA(DisplayName = "Kolumns Outter"),
	KolumnsInner UMETA(DisplayName = "Kolumns Inner"),
	KolumnsOutterAndInner UMETA(DisplayName = "Kolumns Outter And Inner"),
};
UCLASS()
class LABIRYNTHS_TEST_API ACPP_Labirynths : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Labirynths();

	UPROPERTY()
	USceneComponent* DefaultSceneRoot;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "RenderText")
	UTextRenderComponent* TR_X_Axis;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "RenderText")
	UTextRenderComponent* TR_Y_Axis;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "RenderText")
	UTextRenderComponent* TR_IndexOrder;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
	UInstancedStaticMeshComponent* ISM;



	
	virtual void OnConstruction(const FTransform& Transform) override;

	//Variables
	UPROPERTY(EditAnywhere, Category = "Default")
	bool ResetLabirynth = false;
	UPROPERTY(EditAnywhere, Category = "Default")
	int X = 0;
	UPROPERTY(EditAnywhere, Category = "Default")
	int Y = 0;
	UPROPERTY(EditAnywhere, Category = "Default")
	int CellSizeXY = 1000;
	UPROPERTY(EditAnywhere, Category = "Default")
	bool RndSeed = false;
	UPROPERTY(EditAnywhere, Category = "Default")
	int SeedRandom = 0;
	UPROPERTY(EditAnywhere, Category = "Default")
	int Seed = 0;
	UPROPERTY(EditAnywhere, Category = "Default")
	bool RemoveRndCells = false;
	UPROPERTY(EditAnywhere, Category = "Default")
	float Weight_RemoveCell = 0;
	UPROPERTY(EditAnywhere, Category = "Default")
	bool PointsPerSpline = false;
	UPROPERTY(EditAnywhere, Category = "Default")
	bool ShowInstanceGrid = false;

	
	






protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;






};
