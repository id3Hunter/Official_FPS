// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class ABulletBase;

UCLASS()
class OFFICIAL_FPS_API AWeaponBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess = "true"))
	class UArrowComponent* MuzzlePoint;
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	TSubclassOf<ABulletBase> BulletClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	float FiringRate = 0.1f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	int CurrAmmoAmount = 10000;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	bool bFullyAutomatic = false;

	UFUNCTION(BlueprintNativeEvent, Category = "Weapon")
	void StartFiring();

	UFUNCTION(BlueprintNativeEvent, Category = "Weapon")
	void StopFiring();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
