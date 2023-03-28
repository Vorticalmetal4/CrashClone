// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrashPlatform.generated.h"

UCLASS()
class CRASHCLONE_API ACrashPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrashPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:

	UFUNCTION(BlueprintCallable)
	void DimensionChanged();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mechanics")
	bool IsActivated;
};
