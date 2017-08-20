// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Tank.h" // So we can implement OnDeath()


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe our local method to the tanks death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn()) { return; }
	auto PossessedPawn = GetPawn();
	PossessedPawn->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	
		// TODO Move towards the player

		//Get Controlled AI Tank
		auto ControlledTank = GetPawn();
		//Get Player Tank
		auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
		
		if (!ensure(PlayerTank && ControlledTank)) { return; }
		{
			MoveToActor(PlayerTank, AcceptanceRadius);

			// Aim towards the player
			auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
			AimingComponent->AimAt(PlayerTank->GetActorLocation());

			auto CurrentState = AimingComponent->GetFiringState();
			
			// if aiming or locked then fire
			if (AimingComponent->GetFiringState() == EFiringState::Locked)
			{ 
			AimingComponent->Fire(); // TODO Limit firing rate
			}
		}


	
	
}

	



