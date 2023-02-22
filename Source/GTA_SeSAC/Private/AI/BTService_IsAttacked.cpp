// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_IsAttacked.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GTA_CitizenCharacter.h"
#include "GTA_PoliceCharacter.h"
#include "AIController.h"

UBTService_IsAttacked::UBTService_IsAttacked()
{
	NodeName = TEXT("If Is Attacked");
}

void UBTService_IsAttacked::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AGTA_CitizenCharacter* citizen = Cast<AGTA_CitizenCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AGTA_PoliceCharacter* police = Cast<AGTA_PoliceCharacter>(OwnerComp.GetAIOwner()->GetPawn());


	/*if (citizen == nullptr)
	{
		return;
	}*/

	// OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), enemy->bIsDead);
}
