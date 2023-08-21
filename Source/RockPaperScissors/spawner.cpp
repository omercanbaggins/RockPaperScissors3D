// Fill out your copyright notice in the Description page of Project Settings.


#include "spawner.h"
#include "TimerManager.h"
#include "Enemy.h"
// Sets default values

Aspawner::Aspawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FTimerHandle spawnTimer;
// Called when the game starts or when spawned
void Aspawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(spawnTimer,this, &Aspawner::spawn, 1.0f, true, 1.0f);
}

// Called every frame
void Aspawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Aspawner::spawn()
{
	GetWorld()->SpawnActor<AEnemy>(spawnClass, GetActorLocation(), GetActorRotation(),FActorSpawnParameters::FActorSpawnParameters());
}

