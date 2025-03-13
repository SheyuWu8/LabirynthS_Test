// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Labirynths.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ACPP_Labirynths::ACPP_Labirynths()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootComponent"));
	RootComponent = DefaultSceneRoot;
	
	TR_X_Axis = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Axis X"));
	TR_X_Axis->SetupAttachment(DefaultSceneRoot);

	TR_Y_Axis = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Axis Y"));
	TR_Y_Axis->SetupAttachment(DefaultSceneRoot);

	TR_IndexOrder = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Index Order"));
	TR_IndexOrder->SetupAttachment(DefaultSceneRoot);

	ISM = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("MainISM"));
	ISM->SetupAttachment(DefaultSceneRoot);
}
void ACPP_Labirynths::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ResetLabirynth = false;
	if (X > 0 && Y > 0)
	{
		if (RndSeed)
		{
			SeedRandom = FMath::RandRange(0, 2147483647);
			Stream.Initialize(Seed);

			static ConstructorHelpers::FObjectFinder<UStaticMesh>ShapePlaneFinder(TEXT("/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane"));
			if (ShapePlaneFinder.Succeeded())
			{
				ISM->SetStaticMesh(ShapePlaneFinder.Object);
			}
			static ConstructorHelpers::FObjectFinder<UMaterialInterface>PerInstanceColorFinder(TEXT("/Game/Material/M_PerInstanceColor.M_PerInstanceColor"));
			if (PerInstanceColorFinder.Succeeded())
			{
				ISM->SetMaterial(0,PerInstanceColorFinder.Object);
			}
		}
		else
		{
			Stream.Initialize(Seed);
			static ConstructorHelpers::FObjectFinder<UStaticMesh>ShapePlaneFinder(TEXT("/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane"));
			if (ShapePlaneFinder.Succeeded())
			{
				ISM->SetStaticMesh(ShapePlaneFinder.Object);
			}
			static ConstructorHelpers::FObjectFinder<UMaterialInterface>PerInstanceColorFinder(TEXT("/Game/Material/M_PerInstanceColor.M_PerInstanceColor"));
			if (PerInstanceColorFinder.Succeeded())
			{
				ISM->SetMaterial(0, PerInstanceColorFinder.Object);
			}
		}
		FVector L_Location_X;
		FVector L_Location_Y;
		int L_Index_X;
		TArray<FVector> L_Stone_Locations_X_Array;

		FRotator rotation = FRotator::ZeroRotator;


		int i = 0;
		int j = 0;
		for (i = 0; i < X; i++)
		{
			L_Index_X = i;
			L_Location_X = (i * UKismetMathLibrary::MakeVector(L_Index_X * CellSizeXY + CellSizeXY/2.0f, 0.0f, 0.0f));

			/*ArrayLocation*/
			L_Stone_Locations_X_Array.Add(L_Location_X);

			for (j = 0; j < Y; j++)
			{
				L_Location_Y = (i * UKismetMathLibrary::MakeVector(0.0f,L_Index_X * CellSizeXY + CellSizeXY / 2.0f, 0.0f) + L_Location_X);
				/*ArrayLocation*/
				//ISM->AddInstance(L_Location_Y, rotation, UKismetMathLibrary::MakeVector(CellSizeXY / 102.5f, CellSizeXY / 102.5f, 1.0f, false);
				ISM->AddInstance(FTransform(rotation, L_Location_Y, FVector(CellSizeXY / 102.5f, CellSizeXY / 102.5f, 1.0f)));
			}
		}

		int Solve_Steps = 0;

		int L_Index_Current = 0;
		int Index_Start_Cell = 0;
		switch (SetupLabyrinth)
		{
		case Enum_SetUpLabyrinth::StartAt00:
			L_Index_Current = 0;
			Index_Start_Cell = L_Index_Current;
			break;
		case Enum_SetUpLabyrinth::StartAtRndAll:
			L_Index_Current = (UKismetMathLibrary::RandomIntegerInRangeFromStream(Stream, 0, Y - 1) + (UKismetMathLibrary::RandomFloatInRangeFromStream(Stream, 0, X - 1)) * Y);
			Index_Start_Cell = L_Index_Current;
			break;
		case Enum_SetUpLabyrinth::StartRndAtBorder:
			int Out_Index;
			FGetBorderStart(Out_Index);
			L_Index_Current = Out_Index;
			Index_Start_Cell = L_Index_Current;
			break;
		case Enum_SetUpLabyrinth::StartRndInside:
			L_Index_Current = 0;
			Index_Start_Cell = L_Index_Current;
			break;
		case Enum_SetUpLabyrinth::StartAtCenter:
			L_Index_Current = 0;
			Index_Start_Cell = L_Index_Current;
			break;
		
		}
		
	}


}


void ACPP_Labirynths::FGetBorderStart(int&Out_Index)
{
	bool L_BorderFound = false;
	if (X > 2 && Y > 2)
	{	
		int LRndY;
		int LRndX;
		while (!L_BorderFound)
		{
			LRndY = UKismetMathLibrary::RandomIntegerInRangeFromStream(Stream, 0, Y - 1);
			LRndX = UKismetMathLibrary::RandomIntegerInRangeFromStream(Stream, 0, X - 1);
			L_BorderFound = (LRndY == 0 || LRndY == Y - 1) || (LRndX ==0 || LRndX == X - 1);
		}
		Out_Index = LRndY + (LRndX * Y);
	}
	else
	{
		Out_Index = (UKismetMathLibrary::RandomIntegerInRangeFromStream(Stream, 0, Y - 1) + (UKismetMathLibrary::RandomIntegerInRangeFromStream(Stream, 0, X - 1)) * Y);
	}
}

void ACPP_Labirynths::FGetInsideStart(int& Out_Index)
{

}





/*void F4WallPoints(int CellSize_X, int CellSize_Y)
{
	float L_CellSize_X = static_cast<float>(CellSize_X) * 0.5f;
	float L_CellSize_Y = static_cast<float>(CellSize_Y) * 0.5f;


	
	FVector TopLeft(L_CellSize_X * -1.0f, L_CellSize_Y * -1.0f, 0);
	FVector TopRight(L_CellSize_X * 1.0f, L_CellSize_Y * -1.0f, 0);
	
	TArray<FVector>vectorArrayTopLR;
	vectorArrayTopLR.Add(FVector (L_CellSize_X * -1.0f, L_CellSize_Y * -1.0f, 0));
	vectorArrayTopLR.Add(FVector (L_CellSize_X * 1.0f, L_CellSize_Y * -1.0f, 0));
	
}*/
TTuple <struct wall, struct wall, struct wall, struct wall >F4WallPoints(int CellSizeX, int CellSizeY)
{

}





/*void ACPP_Labirynths::FChangeColor(int InInstanceIndex, Color)
{
	ISM->SetCustomDataValue(InInstanceIndex, 0, Color[i].R, false);
	ISM->SetCustomDataValue(InInstanceIndex, 1, Color[i].G, false);
	ISM->SetCustomDataValue(InInstanceIndex, 2, Color[i].B, false);

}*/

// Called when the game starts or when spawned
void ACPP_Labirynths::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ACPP_Labirynths::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

