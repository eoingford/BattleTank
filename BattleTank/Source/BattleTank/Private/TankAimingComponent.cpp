// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed) 
{
	if (!Barrel) {return;}
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	TArray<AActor *> ActorsToIgnore;

	// Calculate the OutLaunchVelocity
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace);
		
	if (bHaveAimSolution) 
	{
	auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	auto TankName = GetOwner()->GetName();
	// UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s"), *TankName, (*AimDirection.ToString()))
	MoveBarrelTowards(AimDirection);
	}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) 
	{
		// Work out difference between CurrentBarrelRotation and AimDirection
		auto BarrelRotator = Barrel->GetForwardVector().Rotation();
		auto AimAsRotator = AimDirection.Rotation();
		auto DeltaRotator = AimAsRotator - BarrelRotator;
		
		Barrel->Elevate(5); // TODO Remove magic number
		

		
	
	}


