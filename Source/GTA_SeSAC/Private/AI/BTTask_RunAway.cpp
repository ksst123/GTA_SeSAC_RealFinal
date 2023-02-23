// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_RunAway.h"

#include "AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GTA_PoliceCharacter.h"
#include "GTA_CitizenCharacter.h"

UBTTask_RunAway::UBTTask_RunAway()
{
	NodeName = TEXT("Run Away");
}

EBTNodeResult::Type UBTTask_RunAway::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AGTA_CitizenCharacter* citizen = Cast<AGTA_CitizenCharacter>(OwnerComp.GetAIOwner()->GetCharacter());
	AGTA_PoliceCharacter* police = Cast<AGTA_PoliceCharacter>(OwnerComp.GetAIOwner()->GetCharacter());


	if (citizen != nullptr)
	{
		citizen->GetCharacterMovement()->MaxWalkSpeed = 450.f;
	}
	else if (police != nullptr)
	{
		police->GetCharacterMovement()->MaxWalkSpeed = 550.f;
	}

	return EBTNodeResult::Succeeded;
}
