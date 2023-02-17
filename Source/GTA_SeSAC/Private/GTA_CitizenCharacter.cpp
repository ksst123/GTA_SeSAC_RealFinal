// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_CitizenCharacter.h"
#include "Components/SphereComponent.h"
#include "GTA_CitizenAnimInstance.h"

AGTA_CitizenCharacter::AGTA_CitizenCharacter()
{
	RightFistCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Right Fist Collision"));
	RightFistCollision->SetupAttachment(GetMesh(), TEXT("hand_rFistSocket"));
	RightFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LeftFistCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Left Fist Collision"));
	LeftFistCollision->SetupAttachment(GetMesh(), TEXT("hand_lFistSocket"));
	LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AGTA_CitizenCharacter::BeginPlay()
{
	Super::BeginPlay();


	// �ִϸ��̼� �������Ʈ
	BPAnim = Cast<UGTA_CitizenAnimInstance>(GetMesh()->GetAnimInstance());
}

void AGTA_CitizenCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
