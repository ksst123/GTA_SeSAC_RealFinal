// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GTA_CitizenAIController.generated.h"

/**
 * 
 */
UCLASS()
class GTA_SESAC_API AGTA_CitizenAIController : public AAIController
{
	GENERATED_BODY()

public:
	AGTA_CitizenAIController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;


	UPROPERTY(EditAnywhere)
	class UBehaviorTree* BT_Citizen;

	UPROPERTY()
	class AGTA_Player* Player;
};
