// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_CitizenMoveComponent.h"
#include "GTA_CitizenCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UGTA_CitizenMoveComponent::UGTA_CitizenMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGTA_CitizenMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGTA_CitizenMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGTA_CitizenMoveComponent::OnActionJump()
{
	ownerCitizen->Jump();
}

void UGTA_CitizenMoveComponent::OnActionRunPressed()
{
	ownerCitizen->GetCharacterMovement()->MaxWalkSpeed = RunMultiplier * WalkSpeed;
}

void UGTA_CitizenMoveComponent::OnActionRunReleased()
{
	ownerCitizen->GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void UGTA_CitizenMoveComponent::OnActionStartCover()
{
}

void UGTA_CitizenMoveComponent::OnActionEndCover()
{
}

