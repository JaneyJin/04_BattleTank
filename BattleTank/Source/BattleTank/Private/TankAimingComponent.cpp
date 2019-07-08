// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO Should this really tick?

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
	this->Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {

	// Move from Tank-> AimingAt
	// auto OurTankName = GetName();

	// From hierarchy point of view, we are in the aiming component, comme up to the tank itself and then get its name
	 auto OurTankName = GetOwner()->GetName();
	// auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	// Move from Tank-> AimingAt
	// UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from barrel location %s."), *OurTankName, *HitLocation.ToString(), *BarrelLocation);
	// UE_LOG(LogTemp, Warning, TEXT("Firing at %f"), LaunchSpeed);

	// Protect the Barrel
	if (!Barrel) { return; }
	
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	// Calculate the OutLauchVelocity
	// Collision Radius to 0 because we want aim percies
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace // Paramenter need to be present before UE4.20
	);
	if (bHaveAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		// UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *OurTankName, *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: %s Aim solution found"), Time, *OurTankName);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);
	}
	// If no soultion found do nothing
	
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	// Work-out difference between current barrel rotation, and AimDirection
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;

	// UE_LOG(LogTemp, Warning, TEXT("AimAsRotator %s"), *DeltaRotator.ToString())

	Barrel->Elevate(5);

}
