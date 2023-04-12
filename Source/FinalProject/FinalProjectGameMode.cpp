// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinalProjectGameMode.h"
#include "FinalProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFinalProjectGameMode::AFinalProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
