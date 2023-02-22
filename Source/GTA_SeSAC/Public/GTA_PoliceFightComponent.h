// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GTA_PoliceBaseComponent.h"
#include "GTA_PoliceFightComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GTA_SESAC_API UGTA_PoliceFightComponent : public UGTA_PoliceBaseComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGTA_PoliceFightComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Character Settings")
	int32 FistDamage = 5;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentPistolAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxPistolAmmo = 12;


	UPROPERTY(EditAnywhere)
	class USoundBase* PunchSound;
	UPROPERTY(EditAnywhere)
	class USoundBase* PistolSound;


	UPROPERTY(EditAnywhere, Category = "My Character Settings")
	class UParticleSystem* BulletEffect;
	UPROPERTY(EditAnywhere, Category = "My Character Settings")
	class UParticleSystem* PistolEffect;


	UPROPERTY()
	class APistol* Pistol;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class APistol> PistolClass;


	UPROPERTY()
	bool bHasGun;
	UPROPERTY()
	bool bIsAttacked;
	UPROPERTY()
	bool bIsJap;
	UPROPERTY()
	bool bIsStraight;
	UPROPERTY()
	bool bIsDead;
	UPROPERTY()
	bool bDoOnce = false;


	// ===========================================================================
	// ===========================================================================


	void OnActionAimPressed();
	void OnActionAimReleased();


	void OnActionJap();
	void OnActionStraight();
	void OnActionShoot();
	void DoFire();


	void OnDamagedJap(int32 damage);
	void OnDamagedStraight(int32 damage);


	void OnActionReload();


	void OnActionHand();
	void OnActionPistol();


	void OnMyPistolAmmoUpdate(int32 current, int32 max);
};
