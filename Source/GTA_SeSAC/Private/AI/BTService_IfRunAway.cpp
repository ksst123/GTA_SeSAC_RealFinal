// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_IfRunAway.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GTA_CitizenCharacter.h"
#include "AIController.h"

UBTService_IfRunAway::UBTService_IfRunAway()
{
	NodeName = TEXT("If Run Away");
}

void UBTService_IfRunAway::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	AGTA_CitizenCharacter* citizen = Cast<AGTA_CitizenCharacter>(OwnerComp.GetAIOwner()->GetCharacter());

	UE_LOG(LogTemp, Warning, TEXT("%d"), citizen->RunAwayValue);

	if (citizen != nullptr)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsInt(GetSelectedBlackboardKey(), citizen->RunAwayValue);
	}
}