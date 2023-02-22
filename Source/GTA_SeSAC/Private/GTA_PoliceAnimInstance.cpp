// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_PoliceAnimInstance.h"
#include "GTA_PoliceCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SphereComponent.h"

void UGTA_PoliceAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);


	ownerPolice = Cast<AGTA_PoliceCharacter>(TryGetPawnOwner());

	if (ownerPolice != nullptr)
	{
		FVector velocity = ownerPolice->GetVelocity();
		Speed = FVector::DotProduct(ownerPolice->GetActorForwardVector(), velocity);

		bIsJumping = ownerPolice->GetCharacterMovement()->IsFalling();
	}
}

void UGTA_PoliceAnimInstance::AnimNotify_Jap()
{
	ownerPolice->LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void UGTA_PoliceAnimInstance::AnimNotify_Straight()
{
	ownerPolice->RightFistCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void UGTA_PoliceAnimInstance::AnimNotify_JapEnd()
{
	ownerPolice->LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UGTA_PoliceAnimInstance::AnimNotify_StraightEnd()
{
	ownerPolice->LeftFistCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UGTA_PoliceAnimInstance::AnimNotify_FistDamaged()
{
}