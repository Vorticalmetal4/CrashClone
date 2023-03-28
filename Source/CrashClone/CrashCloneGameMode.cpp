// Copyright Epic Games, Inc. All Rights Reserved.

#include "CrashCloneGameMode.h"
#include "CrashCloneCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACrashCloneGameMode::ACrashCloneGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
