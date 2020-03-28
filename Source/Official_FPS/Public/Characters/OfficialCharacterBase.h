// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OfficialCharacterBase.generated.h"


class UCameraComponent;

UCLASS()
class OFFICIAL_FPS_API AOfficialCharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character", meta=(AllowPrivateAccess="true"))
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;

public:
	// Sets default values for this character's properties
	AOfficialCharacterBase();

	UCameraComponent* GetCameraComponent() { return CameraComp; }

	USkeletalMeshComponent* GetMesh1P() { return Mesh1P; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Delta);
	void MoveRight(float Delta);
	void MoveUp(float Delta);
	void Turn(float Delta); //For Controllers
	void TurnRate(float Delta); //For Controllers
	void LookUp(float Delta); //For Mouse
	void LookUpRate(float Delta); //FOr Mouse

	void StartJump();
	void StopJump();
	void StartShoot();
	void StopShoot();
	void StartSprint();
	void StopSprint();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Official")
	float BaseTurnRate = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Official")
	float BaseLookAtRate = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Official")
	float MaxSprintSpeed = 900.0f;

private:
	float DefaultWalkSpeed;

};
