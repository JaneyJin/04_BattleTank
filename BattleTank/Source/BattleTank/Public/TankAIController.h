// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declaration
class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

private:

	// BeginPlay() should stay public if you plan to inherit from this class
	virtual void BeginPlay() override;


	
	virtual void Tick(float DeltaTime) override;

	//ATank* GetControlledTank() const;

	// ATank* GetPlayerTank() const;
};
