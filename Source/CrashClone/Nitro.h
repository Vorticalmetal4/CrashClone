// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Nitro.generated.h"

UCLASS()
class CRASHCLONE_API ANitro : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANitro();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadWrite)
		bool isExploting;

};
