// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/SphereComponent.h"
#

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("objesi"));
	colshape = CreateDefaultSubobject<USphereComponent>(TEXT("col"));
	SetRootComponent(colshape);
	mesh->SetupAttachment(colshape);
	charstate = state::rock;
	colshape->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemy::Change(int &c) {
	charstate = (state)c; 
		
	if (c >= 2) {
		c = 0;
	}
	else {
		c++;
	}
	switch (charstate) {

	case rock:
		rowName = "rock";
		break;
	case paper:
		rowName = "paper";
		break;
	case scissors:
		rowName = "scissors";
		break;
	}
	if (table) {
		infoStruct = table->FindRow<FInformation>(rowName, "asd", true);
		if (infoStruct) {
			mesh->SetStaticMesh(infoStruct->shape);
			decr = infoStruct->dec; incr = infoStruct->inc; eq = infoStruct->equal;
		}
	}
}