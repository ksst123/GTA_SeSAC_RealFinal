// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_PoliceBaseComponent.h"
#include "GTA_PoliceCharacter.h"

// Sets default values for this component's properties
UGTA_PoliceBaseComponent::UGTA_PoliceBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bWantsInitializeComponent = true;
}


// Called when the game starts
void UGTA_PoliceBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGTA_PoliceBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGTA_PoliceBaseComponent::InitializeComponent()
{
	Super::InitializeComponent();


	ownerPolice = Cast<AGTA_PoliceCharacter>(GetOwner());
}

