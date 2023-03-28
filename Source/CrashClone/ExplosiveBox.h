// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplosiveBox.generated.h"

UENUM(BlueprintType)
enum class KindsOfBomb : uint8
{
	TNT,
	Nitroglycerine
};

UCLASS()
class CRASHCLONE_API AExplosiveBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplosiveBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kind of Box")
	KindsOfBomb KindOfBomb;

	UPROPERTY(BlueprintReadWrite)
	int SecondsToExplode;

	UPROPERTY(BlueprintReadWrite)
	bool isExploting;

};
