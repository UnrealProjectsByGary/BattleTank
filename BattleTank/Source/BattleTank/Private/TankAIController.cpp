// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetControlledTank();

	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No possessed AI tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank possessed: %s"), *AIControlledTank->GetName());
	}

	auto PlayerPawn = GetPlayerController();
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController cant find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *PlayerPawn->GetName());
	}
}

ATank* ATankAIController::GetPlayerController() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}