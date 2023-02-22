// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_PoliceCharacter.h"
#include "GTA_PoliceMoveComponent.h"
#include "GTA_PoliceFightComponent.h"
#include "Components/SphereComponent.h"
#include "GTA_PoliceAnimInstance.h"

AGTA_PoliceCharacter::AGTA_PoliceCharacter()
{
	RightFistCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Right Fist Collision"));
	RightFistCollision->SetupAttachment(GetMesh(), TEXT("hand_rFistSocket"));
	RightFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LeftFistCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Left Fist Collision"));
	LeftFistCollision->SetupAttachment(GetMesh(), TEXT("hand_lFistSocket"));
	LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	MoveComponent = CreateDefaultSubobject<UGTA_PoliceMoveComponent>(TEXT("Move Component"));
	FightComponent = CreateDefaultSubobject<UGTA_PoliceFightComponent>(TEXT("Fight Component"));
}

void AGTA_PoliceCharacter::BeginPlay()
{
	Super::BeginPlay();


	CurrentHP = MaxHP;


	// 애니메이션 블루프린트
	BPAnim = Cast<UGTA_PoliceAnimInstance>(GetMesh()->GetAnimInstance());
}

void AGTA_PoliceCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
