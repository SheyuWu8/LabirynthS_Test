// Copyright Epic Games, Inc. All Rights Reserved.

#include "LabirynthS_TestGameMode.h"
#include "LabirynthS_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALabirynthS_TestGameMode::ALabirynthS_TestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
