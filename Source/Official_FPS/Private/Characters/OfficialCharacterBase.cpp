// Fill out your copyright notice in the Description page of Project Settings.


#include "OfficialCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFrameWork/CharacterMovementComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AOfficialCharacterBase::AOfficialCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CharacterCamera"));
	CameraComp->SetupAttachment(GetRootComponent());
	CameraComp->bUsePawnControlRotation = true;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh1P"));
	Mesh1P->SetupAttachment(CameraComp);
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetOwnerNoSee(false);
	Mesh1P->SetCastShadow(false);
	Mesh1P->SetReceivesDecals(false);

	GetMesh()->SetOnlyOwnerSee(false);
	GetMesh()->SetOwnerNoSee(true);

}

// Called when the game starts or when spawned
void AOfficialCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	DefaultWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
}

// Called every frame
void AOfficialCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOfficialCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AOfficialCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveForwards"), this, &AOfficialCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AOfficialCharacterBase::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &AOfficialCharacterBase::MoveUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AOfficialCharacterBase::Turn);
	PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &AOfficialCharacterBase::TurnRate);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AOfficialCharacterBase::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AOfficialCharacterBase::LookUpRate);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AOfficialCharacterBase::StartJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AOfficialCharacterBase::StopJump);

	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &AOfficialCharacterBase::StartShoot);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Released, this, &AOfficialCharacterBase::StopShoot);

	PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Pressed, this, &AOfficialCharacterBase::StartSprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Released, this, &AOfficialCharacterBase::StopSprint);

}

void AOfficialCharacterBase::MoveForward(float Delta)
{
	if (Delta != 0.0)
	{
		AddMovementInput(GetActorForwardVector(), Delta);
	}
	else
	{
		StopSprint();
	}
}

void AOfficialCharacterBase::MoveRight(float Delta)
{

	if (Delta != 0.0)
	{
		AddMovementInput(GetActorRightVector(), Delta);
	}
}

void AOfficialCharacterBase::MoveUp(float Delta)
{

	if (Delta != 0.0)
	{
		AddMovementInput(GetActorUpVector(), Delta);
	}
}

void AOfficialCharacterBase::Turn(float Delta)
{
	AddControllerYawInput(Delta);
}

void AOfficialCharacterBase::TurnRate(float Delta)
{
	AddControllerYawInput((Delta * BaseTurnRate) * GetWorld()->GetDeltaSeconds());
}

void AOfficialCharacterBase::LookUp(float Delta)
{
	AddControllerPitchInput(Delta);
}

void AOfficialCharacterBase::LookUpRate(float Delta)
{
	AddControllerPitchInput((Delta * BaseLookAtRate) * GetWorld()->GetDeltaSeconds());
}

void AOfficialCharacterBase::StartJump()
{
	Jump();
}

void AOfficialCharacterBase::StopJump()
{
	StopJumping();
}

void AOfficialCharacterBase::StartShoot()
{

}

void AOfficialCharacterBase::StopShoot()
{

}

void AOfficialCharacterBase::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxSprintSpeed;
}

void AOfficialCharacterBase::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = DefaultWalkSpeed;
}


