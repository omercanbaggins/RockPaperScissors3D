// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "spawner.generated.h"

UCLASS()
class ROCKPAPERSCISSORS_API Aspawner : public AActor
{
	GENERATED_BODY()
		FTimerHandle timer;
public:	

	Aspawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		void spawn();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AEnemy> spawnClass;
};
