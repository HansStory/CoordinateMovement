// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMyActor.generated.h"

UCLASS()
class COORDINATEMOVEMENT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

protected:
	virtual void BeginPlay() override;

public:
	void Move();
	void PrintMoveResult();

	int Step();

	float Distance(FVector2D first, FVector2D second);

	void TryTriggerEvent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	int MoveCount = 10;

private:
	FVector2D currentPos = FVector2D(0, 0);
	int totalMoveCount = 0;
	int totalEventCount = 0;
};
