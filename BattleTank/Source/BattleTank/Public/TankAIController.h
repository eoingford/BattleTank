// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank; // Forward Declaration

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledAITank() const;
	
	virtual void BeginPlay() override;

	ATank* GetPlayerTank() const;
};
