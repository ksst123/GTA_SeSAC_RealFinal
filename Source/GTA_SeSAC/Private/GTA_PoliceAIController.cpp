// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_PoliceAIController.h"
#include "GTA_Player.h"
#include "Kismet/GameplayStatics.h"

AGTA_PoliceAIController::AGTA_PoliceAIController()
{
}

void AGTA_PoliceAIController::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AGTA_Player>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));


	if (Player != nullptr)
	{
		if (BT_Police != nullptr)
		{
			RunBehaviorTree(BT_Police);
		}
	}
}

void AGTA_PoliceAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
