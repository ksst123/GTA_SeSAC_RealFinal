// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GTA_PoliceAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GTA_SESAC_API UGTA_PoliceAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


	UPROPERTY()
	class AGTA_PoliceCharacter* ownerPolice;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Speed;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bIsJumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
		bool bIsFighting = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
		bool bHasGun = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Montages")
		class UAnimMontage* PunchJap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Montages")
		class UAnimMontage* PunchStraight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Montages")
		class UAnimMontage* EnteringCar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Montages")
		class UAnimMontage* ExitingCar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Montages")
		class UAnimMontage* DrivingCar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Montages")
		class UAnimMontage* PistolReload;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Montages")
		class UAnimMontage* Damaged;


	UFUNCTION()
	void AnimNotify_Jap();
	UFUNCTION()
	void AnimNotify_Straight();
	UFUNCTION()
	void AnimNotify_JapEnd();
	UFUNCTION()
	void AnimNotify_StraightEnd();
	UFUNCTION()
	void AnimNotify_DamagedStraightEnd();
};
