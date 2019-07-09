// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed) {
	auto OurTankName = GetOwner()->GetName();
	
	// Clamp relative speed between -1 to 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	if (RelativeSpeed < 0) {
		UE_LOG(LogTemp, Warning, TEXT("%s left"), *OurTankName)
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s right"), *OurTankName)
	}

	
	auto RotationChange = MaxDegreesPerSecond * RelativeSpeed * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	

	SetRelativeRotation(FRotator(0, Rotation, 0));
}




