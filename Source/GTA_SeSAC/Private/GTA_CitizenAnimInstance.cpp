// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_CitizenAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GTA_CitizenCharacter.h"
#include "Components/SphereComponent.h"

void UGTA_CitizenAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);


	ownerCitizen = Cast<AGTA_CitizenCharacter>(TryGetPawnOwner());

	if (ownerCitizen != nullptr)
	{
		FVector velocity = ownerCitizen->GetVelocity();
		Speed = FVector::DotProduct(ownerCitizen->GetActorForwardVector(), velocity);

		bIsJumping = ownerCitizen->GetCharacterMovement()->IsFalling();
	}
}

void UGTA_CitizenAnimInstance::AnimNotify_Jap()
{
	ownerCitizen->LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void UGTA_CitizenAnimInstance::AnimNotify_Straight()
{
	ownerCitizen->RightFistCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void UGTA_CitizenAnimInstance::AnimNotify_JapEnd()
{
	ownerCitizen->LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UGTA_CitizenAnimInstance::AnimNotify_StraightEnd()
{
	ownerCitizen->LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UGTA_CitizenAnimInstance::AnimNotify_FistDamaged()
{
}