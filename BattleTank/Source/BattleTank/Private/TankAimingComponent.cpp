// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {
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

	auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	// Move from Tank-> AimingAt
	// UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from barrel location %s."), *OurTankName, *HitLocation.ToString(), *BarrelLocation);
	UE_LOG(LogTemp, Warning, TEXT("Firing at %f"), LaunchSpeed);
}

