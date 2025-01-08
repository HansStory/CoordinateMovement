// Fill out your copyright notice in the Description page of Project Settings.


#include "AMyActor.h"

// Sets default values
AMyActor::AMyActor()
{
    currentPos = FVector2D(0, 0);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Log, TEXT("Init My Pos! Pos X : %f, Pos Y : %f"), currentPos.X, currentPos.Y);

    Move();
}


void AMyActor::Move()
{
    for (int i = 0; i < MoveCount; i++)
    {
        currentPos = FVector2D(currentPos.X + Step(), currentPos.Y + Step());
        totalMoveCount++;

        UE_LOG(LogTemp, Log, TEXT("Start Move!!"));
        UE_LOG(LogTemp, Log, TEXT("Current Pos X : %f, Pos Y : %f"), currentPos.X, currentPos.Y);
        UE_LOG(LogTemp, Log, TEXT("Move Count : %d"), totalMoveCount);
    }
}

int AMyActor::Step()
{
    return FMath::RandRange(0, 1);
}

