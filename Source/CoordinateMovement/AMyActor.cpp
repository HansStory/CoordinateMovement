// Fill out your copyright notice in the Description page of Project Settings.


#include "AMyActor.h"

// Sets default values
AMyActor::AMyActor()
{

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
        UE_LOG(LogTemp, Log, TEXT("Start Move!!"));

        FVector2D moveTargetPos = FVector2D(currentPos.X + Step(), currentPos.Y + Step());
        float moveDistance = Distance(moveTargetPos, currentPos);

        totalMoveDistance += moveDistance;
        totalMoveCount++;

        currentPos = moveTargetPos;
        UE_LOG(LogTemp, Log, TEXT("Current Pos X : %f, Pos Y : %f"), currentPos.X, currentPos.Y);
        UE_LOG(LogTemp, Log, TEXT("Move Distance : %f"), moveDistance);

        TryTriggerEvent();
    }

    PrintMoveResult();
}

void AMyActor::PrintMoveResult()
{
    UE_LOG(LogTemp, Log, TEXT("Total Move Count : %d, Total Move Distance : %f, Total Event Count : %d"), totalMoveCount, totalMoveDistance, totalEventCount);
}

int AMyActor::Step()
{
    return FMath::RandRange(0, 1);
}

float AMyActor::Distance(FVector2D first, FVector2D second)
{
    float dx = first.X - second.X;
    float dy = first.Y - second.Y;
    return FMath::Sqrt(dx * dx + dy * dy);
}

void AMyActor::TryTriggerEvent()
{
    if (Step())
    {
        UE_LOG(LogTemp, Error, TEXT("Event Triggered!!"));
        totalEventCount++;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Event Not Triggered!!"));
    }
}
