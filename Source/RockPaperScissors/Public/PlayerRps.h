// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerRps.generated.h"

UCLASS()
class ROCKPAPERSCISSORS_API APlayerRps : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerRps();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
		void leftRight(float V);
	void changeState();
	UPROPERTY(EditDefaultsOnly)
		UChildActorComponent* child;
	UPROPERTY(EditAnywhere)
		class UCameraComponent* cam;
	UPROPERTY(EditAnywhere)
		class USpringArmComponent* cmboom;

};
