// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above or they won't work

class UTankBarrel; // Foward declaration
class UTankTurret; // Forward declaration
class UTankAimingComponent; // Foward declaration
class AProjectile; // Forward declaration

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	

private:	
	// Sets default values for this pawn's properties
	ATank();

	UTankBarrel* Barrel = nullptr; // TODO Remove

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile>ProjectileBlueprint;

	// TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 100000; // TODO Find sensible default;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;





	

	double LastFireTime = 0;
};
