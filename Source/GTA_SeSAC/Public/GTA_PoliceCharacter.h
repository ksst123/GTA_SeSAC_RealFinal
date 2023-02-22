// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GTA_PoliceCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GTA_SESAC_API AGTA_PoliceCharacter : public AEnemy
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGTA_PoliceCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Police Settings")
	class USphereComponent* RightFistCollision;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Police Settings")
	class USphereComponent* LeftFistCollision;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UGTA_PoliceMoveComponent* MoveComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UGTA_PoliceFightComponent* FightComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Police Settings")
	int32 CurrentHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Police Settings")
	int32 MaxHP = 30;


	UPROPERTY()
	class UGTA_PoliceAnimInstance* BPAnim;
};
