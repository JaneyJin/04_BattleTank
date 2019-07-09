// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	auto OurTankName = GetOwner()->GetName();
	// UE_LOG(LogTemp, Warning, TEXT(" Barrel-Elevate called at speed %f"), RelativeSpeed)


	// Clamp relative speed between -1 to 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	//if (RelativeSpeed < 0) {
	//	UE_LOG(LogTemp, Warning, TEXT("%s down"), *OurTankName)
	//}
	//else {
	//	UE_LOG(LogTemp, Warning, TEXT("%s up"), *OurTankName)
	//}

	// Move the barrel the right amout this frame
	// Given a max elevation speed, and the frame time
	// Returns the frame delta time in seconds, adjusted by time dilation.
	auto ElevationChange = MaxDegreesPerSecond * RelativeSpeed * GetWorld()->DeltaTimeSeconds;
	// Unclamped new elevation
	// Rotation of the component relative to its parent, it will stop until hit the maximum ptich rotator value (90 degrees)
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	// Clamp can be used to tell it what specific type of thing to clamp; float can be ignore, it will get some implicity type conversion
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation,0,0));
}

