// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_PoliceMoveComponent.h"
#include "GTA_PoliceCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UGTA_PoliceMoveComponent::UGTA_PoliceMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UGTA_PoliceMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGTA_PoliceMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGTA_PoliceMoveComponent::OnActionJump()
{
	ownerPolice->Jump();
}

void UGTA_PoliceMoveComponent::OnActionRunPressed()
{
	ownerPolice->GetCharacterMovement()->MaxWalkSpeed = RunMultiplier * WalkSpeed;
}

void UGTA_PoliceMoveComponent::OnActionRunReleased()
{
	ownerPolice->GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void UGTA_PoliceMoveComponent::OnActionStartCover()
{
}

void UGTA_PoliceMoveComponent::OnActionEndCover()
{
}

