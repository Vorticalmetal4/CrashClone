// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ApplesBox.generated.h"

UENUM(BlueprintType)
enum class KindsOfBox : uint8
{
	IndividualApple,
	MultipleApples,
	Trampoline,
	InfiniteTrampoline,
	CheckPoint
};

UCLASS()
class CRASHCLONE_API AApplesBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AApplesBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kind Of Box")
	KindsOfBox KindOfBox;

	UPROPERTY(BlueprintReadWrite, Category = "Apples")
	int ApplesNumber;

	UPROPERTY(BlueprintReadWrite, Category = "Jumps")
	int NumberOfJumps;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Jumps")
	bool NeedJumpToDamage;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Apples")
	bool ExtraJump;

	UFUNCTION(BlueprintCallable)
	void DamageDetected();

	UFUNCTION(BlueprintImplementableEvent)
	void Destroyed();
};
