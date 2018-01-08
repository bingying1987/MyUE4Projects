// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine.h"
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FVector PlayViewPointLocation;
	FRotator PlayViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayViewPointLocation, PlayViewPointRotation);
//	UE_LOG(LogTemp, Warning, TEXT("Location: %s,Position: %s"), *PlayViewPointLocation.ToString(), *PlayViewPointRotation.ToString());

	FVector PointEnd = PlayViewPointLocation + PlayViewPointRotation.Vector() * Reach;
	DrawDebugLine(GetWorld(), PlayViewPointLocation, PointEnd, FColor::Red, false, 0, 0, 10.0f);

	//所有可以被追踪的物体要勾选 simulity Physics
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	
	GetWorld()->LineTraceSingleByObjectType(Hit, PlayViewPointLocation, PointEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParameters);
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()));
	}
}

