// Fill out your copyright notice in the Description page of Project Settings.


#include "Pistol.h"

// Sets default values
APistol::APistol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root Scene Component"));
	SetRootComponent(RootScene);


	PistolMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Pistol Skeletal Mesh Component"));
	PistolMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APistol::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APistol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

