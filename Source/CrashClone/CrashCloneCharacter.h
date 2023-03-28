// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CrashCloneCharacter.generated.h"


UENUM(BlueprintType)
enum class States : uint8
{
	Idle,
	Jumping,
	Running
};

UCLASS(config=Game)
class ACrashCloneCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ChangeDimensionAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SpinAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

public:
	ACrashCloneCharacter();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void Jump() override;	
	virtual void StopJumping() override;

	UFUNCTION(BlueprintImplementableEvent)
	void ChangeDimensionActivated();

	UFUNCTION(BlueprintCallable)
	void ApplyDamage();

	UFUNCTION(BlueprintCallable)
	void IncrementApples(int ApplesIncrement);

	UPROPERTY(BlueprintReadWrite)
	int Apples;

	UPROPERTY(BlueprintReadWrite)
	int Lives;

	UPROPERTY(BlueprintReadWrite)
	States CurrentState;
	
	UPROPERTY(BlueprintReadOnly)
	bool isSpinning;

	UPROPERTY(BlueprintReadWrite)
	FVector SpawnPoint;

	UPROPERTY(BlueprintReadWrite)
	int DamageResistance;

private:
	
	float DeathLine;
	float SpinningTime;
	float SpinningTimeRemaining;

	void Spin();
	void Die();
};

