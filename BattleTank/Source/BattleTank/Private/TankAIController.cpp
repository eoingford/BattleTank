// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	
		// TODO Move towards the player

		//Get Controlled AI Tank
		auto ControlledTank = Cast<ATank>(GetPawn());
		//Get Player Tank
		auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
		
		if (PlayerTank)
		{
			MoveToActor(PlayerTank, AcceptanceRadius);

			// Aim towards the player
			ControlledTank->AimAt(PlayerTank->GetActorLocation());

			// Fire if ready
			ControlledTank->Fire(); // TODO Limit firing rate
		}


	
	
}

	



