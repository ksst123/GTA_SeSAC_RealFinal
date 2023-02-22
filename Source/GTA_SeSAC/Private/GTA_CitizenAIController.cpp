// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_CitizenAIController.h"
#include "GTA_Player.h"
#include "Kismet/GameplayStatics.h"

AGTA_CitizenAIController::AGTA_CitizenAIController()
{

}

void AGTA_CitizenAIController::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AGTA_Player>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));


	if (Player != nullptr)
	{
		if (BT_Citizen != nullptr)
		{
			RunBehaviorTree(BT_Citizen);
		}
	}
}

void AGTA_CitizenAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


