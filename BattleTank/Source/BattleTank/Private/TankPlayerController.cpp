// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No possessed tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank possessed: %s"), *ControlledTank->GetName());
	}
}
