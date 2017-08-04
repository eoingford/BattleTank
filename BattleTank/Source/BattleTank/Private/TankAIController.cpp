// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
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

			// TODO fix firing
			// ControlledTank->Fire(); // TODO Limit firing rate
		}


	
	
}

	



