// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h" // Must first one to incude
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	// Log AI controlled tank ID name
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}

	// Log Player tank name from AI controller
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find a player tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController find a player tank: %s"), *(PlayerTank->GetName()));
	}

}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	//if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready

	}
}