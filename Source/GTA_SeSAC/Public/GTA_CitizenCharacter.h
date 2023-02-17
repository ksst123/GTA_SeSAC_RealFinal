// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GTA_CitizenCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GTA_SESAC_API AGTA_CitizenCharacter : public AEnemy
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGTA_CitizenCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Citizen Settings")
	class USphereComponent* RightFistCollision;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Citizen Settings")
	class USphereComponent* LeftFistCollision;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Citizen Settings")
	int32 CurrentHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Citizen Settings")
	int32 MaxHP = 15;


	UPROPERTY()
	class UGTA_CitizenAnimInstance* BPAnim;
};
