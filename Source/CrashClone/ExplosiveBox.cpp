// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveBox.h"

// Sets default values
AExplosiveBox::AExplosiveBox()
	:SecondsToExplode(3),
	isExploting(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AExplosiveBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplosiveBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

