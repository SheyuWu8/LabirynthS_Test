// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Labirynths.h"


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
			int SeedRandom = FMath::RandRange(0, 2147483647);
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
	}


}


// Called when the game starts or when spawned
void ACPP_Labirynths::BeginPlay()
{
	Super::BeginPlay();
	
	if (X > 0 && Y > 0) 
	{
		if (RndSeed) {

		}
		else {
			SeedRandom = rand();
		}
	}

}

// Called every frame
void ACPP_Labirynths::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

