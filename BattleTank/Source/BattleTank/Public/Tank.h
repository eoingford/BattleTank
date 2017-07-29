// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above or they won't work

class UTankBarrel; // Foward declaration
class UTankTurret; // Forward declaration
class UTankAimingComponent; // Foward declaration
class AProjectile; // Forward declaration
class UTankMovementComponent; // Forward declaration

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	UFUNCTION(BluePrintCallable, Category = Setup)
	void SetMovementComponent(UTankMovementComponent* TankMovementToSet);

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	

private:	
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile>ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 100000; // TODO Find sensible default;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;

	UTankBarrel* Barrel = nullptr; // Local barrel reference for spawning projectile




	

	double LastFireTime = 0;
};
