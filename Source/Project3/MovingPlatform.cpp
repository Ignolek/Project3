// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
	: CurrentRangeValue(0.0f)
	, RangeModifier(1.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainRootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = MainRootComponent;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentRangeValue >= MovingRange || CurrentRangeValue <= -MovingRange)
	{
		RangeModifier = -RangeModifier;
	}

	FVector NewTargetLocation = this->GetActorLocation();

	if (CurrentRangeValue >= -MovingRange && CurrentRangeValue <= MovingRange)
	{
		NewTargetLocation += RangeModifier * MovingSpeed * 0.1f;

		if (RangeModifier > 0.0f)
		{
			CurrentRangeValue++;
		}
		else
		{
			CurrentRangeValue = CurrentRangeValue-1.0f;
		}
	}

	this->SetActorLocation(NewTargetLocation, true);
	
}

