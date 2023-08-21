// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerRps.h"
#include "C:\Users\christopher\Documents\Unreal Projects\RockPaperScissors\Source\RockPaperScissors\Enemy.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerRps::APlayerRps()
{
	PrimaryActorTick.bCanEverTick = true;

	child = CreateDefaultSubobject<UChildActorComponent>(TEXT("stateComponent"));
	SetRootComponent(child);

	cmboom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("cam"));

	cmboom->SetupAttachment(RootComponent);
	cam->SetupAttachment(cmboom);

	AutoPossessPlayer = EAutoReceiveInput::Player0;


}

// Called when the game starts or when spawned
void APlayerRps::BeginPlay()
{
	Super::BeginPlay();

	//GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red,child->GetChildActorClass()->GetName());
}

// Called every frame
void APlayerRps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerRps::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("left", this, &APlayerRps::leftRight);
	PlayerInputComponent->BindAction("change", EInputEvent::IE_Pressed, this, &APlayerRps::changeState);
}

void APlayerRps::leftRight(float V) {
	AddMovementInput(FVector(0, 10.f, 0), V);
};

void APlayerRps::changeState() {
	AEnemy* childRef = Cast<AEnemy>(child->GetChildActor());
	childRef->Change(childRef->a);

};


