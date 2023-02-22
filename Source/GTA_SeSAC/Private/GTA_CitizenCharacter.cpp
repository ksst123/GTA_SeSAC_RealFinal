// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_CitizenCharacter.h"
#include "Components/SphereComponent.h"
#include "GTA_CitizenAnimInstance.h"
#include "GTA_CitizenMoveComponent.h"
#include "GTA_CitizenFightComponent.h"

AGTA_CitizenCharacter::AGTA_CitizenCharacter()
{
	RightFistCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Right Fist Collision"));
	RightFistCollision->SetupAttachment(GetMesh(), TEXT("hand_rFistSocket"));
	RightFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LeftFistCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Left Fist Collision"));
	LeftFistCollision->SetupAttachment(GetMesh(), TEXT("hand_lFistSocket"));
	LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	MoveComponent = CreateDefaultSubobject<UGTA_CitizenMoveComponent>(TEXT("Move Component"));
	FightComponent = CreateDefaultSubobject<UGTA_CitizenFightComponent>(TEXT("Fight Component"));
}

void AGTA_CitizenCharacter::BeginPlay()
{
	Super::BeginPlay();


	// 애니메이션 블루프린트
	BPAnim = Cast<UGTA_CitizenAnimInstance>(GetMesh()->GetAnimInstance());
}

void AGTA_CitizenCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
