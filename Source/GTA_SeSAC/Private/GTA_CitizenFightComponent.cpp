// Fill out your copyright notice in the Description page of Project Settings.


#include "GTA_CitizenFightComponent.h"
#include "GTA_CitizenCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GTA_CitizenAnimInstance.h"
#include "Pistol.h"

// Sets default values for this component's properties
UGTA_CitizenFightComponent::UGTA_CitizenFightComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGTA_CitizenFightComponent::BeginPlay()
{
	Super::BeginPlay();

	
	CurrentPistolAmmo = MaxPistolAmmo;
}


// Called every frame
void UGTA_CitizenFightComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGTA_CitizenFightComponent::OnActionAimPressed()
{
	if (ownerCitizen->BPAnim != nullptr)
	{
		ownerCitizen->BPAnim->bIsFighting = true;
		ownerCitizen->GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}

void UGTA_CitizenFightComponent::OnActionAimReleased()
{
	if (ownerCitizen->BPAnim != nullptr)
	{
		ownerCitizen->BPAnim->bIsFighting = false;
		ownerCitizen->GetCharacterMovement()->bOrientRotationToMovement = false;
	}
}

void UGTA_CitizenFightComponent::OnActionJap()
{
	if ((ownerCitizen->BPAnim->PunchJap != nullptr) && (ownerCitizen->BPAnim->bIsFighting == true) && (ownerCitizen->BPAnim->bHasGun != true))
	{
		UGameplayStatics::PlaySoundAtLocation(this, PunchSound, ownerCitizen->GetActorLocation());
		bIsJap = true;
		ownerCitizen->BPAnim->AnimNotify_Jap();
	}
}

void UGTA_CitizenFightComponent::OnActionStraight()
{
	if ((ownerCitizen->BPAnim->PunchStraight != nullptr) && (ownerCitizen->BPAnim->bIsFighting == true) && (ownerCitizen->BPAnim->bHasGun != true))
	{
		UGameplayStatics::PlaySoundAtLocation(this, PunchSound, ownerCitizen->GetActorLocation());
		bIsJap = false;
		bIsStraight = true;
		ownerCitizen->BPAnim->AnimNotify_Straight();
	}
}

void UGTA_CitizenFightComponent::OnActionShoot()
{
}

void UGTA_CitizenFightComponent::DoFire()
{
}

void UGTA_CitizenFightComponent::OnActionReload()
{
	if (!bHasGun)
	{
		return;
	}
	ownerCitizen->PlayAnimMontage(ownerCitizen->BPAnim->PistolReload, 1, TEXT("PistolReload"));
	CurrentPistolAmmo = MaxPistolAmmo;

	OnMyPistolAmmoUpdate(CurrentPistolAmmo, MaxPistolAmmo);

}

void UGTA_CitizenFightComponent::OnActionHand()
{
	if (Pistol == nullptr)
	{
		return;
	}


	Pistol->Destroy();


	ownerCitizen->BPAnim->bHasGun = false;
	bHasGun = ownerCitizen->BPAnim->bHasGun;
}

void UGTA_CitizenFightComponent::OnActionPistol()
{
	Pistol = GetWorld()->SpawnActor<APistol>(PistolClass);


	Pistol->SetActorRelativeLocation(FVector(-11.f, 3.f, 5.f));
	Pistol->SetActorRelativeRotation(FRotator(-1.5f, -90.f, 13.f));
	Pistol->SetActorRelativeScale3D(FVector(0.5f));
	Pistol->AttachToComponent(ownerCitizen->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("GunSocket"));
	Pistol->SetOwner(ownerCitizen);


	ownerCitizen->BPAnim->bHasGun = true;
	bHasGun = ownerCitizen->BPAnim->bHasGun;
}

void UGTA_CitizenFightComponent::OnMyPistolAmmoUpdate(int32 current, int32 max)
{
}

