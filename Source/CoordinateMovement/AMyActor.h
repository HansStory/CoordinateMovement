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

	int Step();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	int MoveCount = 10;

private:
	FVector2D currentPos;
	int totalMoveCount;
};
