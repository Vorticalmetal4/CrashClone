// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplesBox.h"

// Sets default values
AApplesBox::AApplesBox()
	:NumberOfJumps(1),
	NeedJumpToDamage(true)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AApplesBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AApplesBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AApplesBox::DamageDetected()
{
	NumberOfJumps--;
	if (NumberOfJumps <= 0)
		Destroyed();
}

