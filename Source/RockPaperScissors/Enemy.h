// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Enemy.generated.h"


UENUM()
enum state {
	rock=0,
	paper,
	scissors,
};

USTRUCT()
struct FInformation:public FTableRowBase{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
		UStaticMesh* shape;
	UPROPERTY(EditAnywhere)
		TEnumAsByte<state> equal;
	UPROPERTY(EditAnywhere)
		TEnumAsByte<state> inc;
	UPROPERTY(EditAnywhere)
		TEnumAsByte<state> dec;
};

UCLASS()
class ROCKPAPERSCISSORS_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();
	FName rowName;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(EditAnywhere)
		int a = 0;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		void Change(int &c);
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere)
		UDataTable* table;
	UPROPERTY(EditAnywhere)
		TEnumAsByte<state> charstate;
	UPROPERTY(EditAnywhere)
		TEnumAsByte<state> eq;
	UPROPERTY(EditAnywhere)
		TEnumAsByte<state> incr;
	UPROPERTY(EditAnywhere)
		TEnumAsByte<state> decr;
	UPROPERTY(EditAnywhere)
		class USphereComponent* colshape;

	FInformation* infoStruct;
};
