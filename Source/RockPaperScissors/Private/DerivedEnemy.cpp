// Fill out your copyright notice in the Description page of Project Settings.


#include "DerivedEnemy.h"
#include "Components/SphereComponent.h"
#include "PlayerRps.h"

ADerivedEnemy::ADerivedEnemy() {
}

void ADerivedEnemy::OnConstruction(const FTransform& Transform)
{
	Change(a);
}

void ADerivedEnemy::BeginPlay()
{
	Super::BeginPlay();
	colshape->OnComponentBeginOverlap.AddDynamic(this, &ADerivedEnemy::Overlap);
}

void ADerivedEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(20.f, 0, 0), false);

}
void ADerivedEnemy::Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, OtherActor->GetName(), true);
	APlayerRps* player = Cast<APlayerRps>(OtherActor);
	if (player) {
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, "sc1	", true);

		AEnemy* childcomp = Cast<AEnemy>(player->child->GetChildActor());
		if (childcomp) {
			GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, UEnum::GetValueAsString(childcomp->charstate), true);
			//GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, "sc2", true);

			if (childcomp->charstate == eq) {}
			
			else if (childcomp->charstate == incr) {
				childcomp->Destroy();

			}
			else if (childcomp->charstate == decr) {
				Destroy();
			};
		}
		else {
		};
	}
	else {
	}
}