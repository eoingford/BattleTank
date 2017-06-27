// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();



	if (!PlayerTank) { UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find player tank.")); }
	else {UE_LOG(LogTemp,Warning,TEXT("AI Controller found Player Tank: %s"),*(PlayerTank->GetName())) }
	
}

void ATankAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	if (GetPlayerTank()) {

		// TODO Move towards the player
		
		// Aim towards the player
		GetControlledAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		
		// Fire if ready
	}
	
}

	

ATank* ATankAIController::GetControlledAITank() const
{
	return Cast<ATank>(GetPawn());
}

 ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	
	return Cast<ATank>(PlayerPawn);
}

