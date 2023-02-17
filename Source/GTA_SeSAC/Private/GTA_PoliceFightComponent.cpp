// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_PoliceFightComponent.h"
#include "GTA_PoliceCharacter.h"
#include "GTA_PoliceAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Pistol.h"

// Sets default values for this component's properties
UGTA_PoliceFightComponent::UGTA_PoliceFightComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGTA_PoliceFightComponent::BeginPlay()
{
	Super::BeginPlay();

	
	CurrentPistolAmmo = MaxPistolAmmo;
}


// Called every frame
void UGTA_PoliceFightComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGTA_PoliceFightComponent::OnActionAimPressed()
{
	if (ownerPolice->BPAnim != nullptr)
	{
		ownerPolice->BPAnim->bIsFighting = true;
		ownerPolice->GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}

void UGTA_PoliceFightComponent::OnActionAimReleased()
{
	if (ownerPolice->BPAnim != nullptr)
	{
		ownerPolice->BPAnim->bIsFighting = false;
		ownerPolice->GetCharacterMovement()->bOrientRotationToMovement = false;
		ownerPolice->BPAnim->AnimNotify_Jap();
	}
}

void UGTA_PoliceFightComponent::OnActionJap()
{
	if ((ownerPolice->BPAnim->PunchJap != nullptr) && (ownerPolice->BPAnim->bIsFighting == true) && (ownerPolice->BPAnim->bHasGun != true))
	{
		UGameplayStatics::PlaySoundAtLocation(this, PunchSound, ownerPolice->GetActorLocation());
		bIsJap = true;
	}
}

void UGTA_PoliceFightComponent::OnActionStraight()
{
	if ((ownerPolice->BPAnim->PunchStraight != nullptr) && (ownerPolice->BPAnim->bIsFighting == true) && (ownerPolice->BPAnim->bHasGun != true))
	{
		UGameplayStatics::PlaySoundAtLocation(this, PunchSound, ownerPolice->GetActorLocation());
		bIsJap = false;
		bIsStraight = true;
		ownerPolice->BPAnim->AnimNotify_Straight();
	}
}

void UGTA_PoliceFightComponent::OnActionShoot()
{
}

void UGTA_PoliceFightComponent::DoFire()
{
}

void UGTA_PoliceFightComponent::OnActionReload()
{
	if (!bHasGun)
	{
		return;
	}
	ownerPolice->PlayAnimMontage(ownerPolice->BPAnim->PistolReload, 1, TEXT("PistolReload"));
	CurrentPistolAmmo = MaxPistolAmmo;

	OnMyPistolAmmoUpdate(CurrentPistolAmmo, MaxPistolAmmo);
}

void UGTA_PoliceFightComponent::OnActionHand()
{
	if (Pistol == nullptr)
	{
		return;
	}


	Pistol->Destroy();


	ownerPolice->BPAnim->bHasGun = false;
	bHasGun = ownerPolice->BPAnim->bHasGun;
}

void UGTA_PoliceFightComponent::OnActionPistol()
{
	Pistol = GetWorld()->SpawnActor<APistol>(PistolClass);


	Pistol->SetActorRelativeLocation(FVector(-11.f, 3.f, 5.f));
	Pistol->SetActorRelativeRotation(FRotator(-1.5f, -90.f, 13.f));
	Pistol->SetActorRelativeScale3D(FVector(0.5f));
	Pistol->AttachToComponent(ownerPolice->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("GunSocket"));
	Pistol->SetOwner(ownerPolice);


	ownerPolice->BPAnim->bHasGun = true;
	bHasGun = ownerPolice->BPAnim->bHasGun;
}

void UGTA_PoliceFightComponent::OnMyPistolAmmoUpdate(int32 current, int32 max)
{
}

