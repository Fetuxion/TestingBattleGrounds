// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TestingBattleGroundsGameMode.h"
#include "TestingBattleGroundsHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestingBattleGroundsGameMode::ATestingBattleGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingBattleGroundsHUD::StaticClass();
}
