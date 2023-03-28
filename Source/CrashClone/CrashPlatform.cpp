// Fill out your copyright notice in the Description page of Project Settings.


#include "CrashPlatform.h"

// Sets default values
ACrashPlatform::ACrashPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACrashPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrashPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrashPlatform::DimensionChanged()
{
	IsActivated = !IsActivated;
}

