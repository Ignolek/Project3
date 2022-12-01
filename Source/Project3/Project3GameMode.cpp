// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project3GameMode.h"
#include "Project3Character.h"
#include "UObject/ConstructorHelpers.h"

AProject3GameMode::AProject3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/GameModeClasses/BP_RunningCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
