// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Labirynths.h"

// Sets default values
ACPP_Labirynths::ACPP_Labirynths()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void ACPP_Labirynths::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);


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

