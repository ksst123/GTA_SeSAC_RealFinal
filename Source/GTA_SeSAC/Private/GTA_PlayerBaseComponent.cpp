// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_PlayerBaseComponent.h"
#include "GTA_Player.h"

// Sets default values for this component's properties
UGTA_PlayerBaseComponent::UGTA_PlayerBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bWantsInitializeComponent = true;
}


// Called when the game starts
void UGTA_PlayerBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGTA_PlayerBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGTA_PlayerBaseComponent::InitializeComponent()
{
	Super::InitializeComponent();


	ownerPlayer = Cast<AGTA_Player>(GetOwner());

	ownerPlayer->SetupInputDelegate.AddUObject(this, &UGTA_PlayerBaseComponent::SetupPlayerInput);
}

