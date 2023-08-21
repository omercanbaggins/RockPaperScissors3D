// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "C:\Users\christopher\Documents\Unreal Projects\RockPaperScissors\Source\RockPaperScissors\Enemy.h"
#include "DerivedEnemy.generated.h"

/**
 * 
 */
UCLASS()
class ROCKPAPERSCISSORS_API ADerivedEnemy : public AEnemy
{
	GENERATED_BODY()
public:
	ADerivedEnemy();
	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);
	UFUNCTION()
		void Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
