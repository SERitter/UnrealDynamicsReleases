// Fill out your copyright notice in the Description page of Project Settings.


#include "AAtom.h"

// Sets default values
AAtom::AAtom()
{
}

void AAtom::InitAtomPrototype(FString NewName, FString NewSymbol, FString NewType, FLinearColor NewColor, float NewMass, int32 NewCharge, float NewCovalentRadius, float NewVanDerWaalsRadius, float NewVanDerWaalsMagnitude)
{
	this->Name = NewName;
	this->Symbol = NewSymbol;
	this->Type = NewType;
	this->Color = NewColor;
	this->Mass = NewMass;
	this->Charge = NewCharge;
	this->CovalentRadius = NewCovalentRadius;
	this->VanDerWaalsRadius = NewVanDerWaalsRadius;
	this->VanDerWaalsMagnitude = NewVanDerWaalsMagnitude;
}

void AAtom::InitAtomCopy(AAtom *Source, FVector NewPosition)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->Name = Source->Name;
	this->Symbol = Source->Symbol;
	this->Type = Source->Type;
	this->Color = Source->Color;
	this->Mass = Source->Mass;
	this->Charge = Source->Charge;
	this->CovalentRadius = Source->CovalentRadius;
	this->VanDerWaalsRadius = Source->VanDerWaalsRadius;
	this->VanDerWaalsMagnitude = Source->VanDerWaalsMagnitude;

	this->Position = NewPosition;

	// Initialize representation(s) here.
}

void AAtom::InitAtomExactCopy(AAtom* Source) {
	this->InitAtomCopy(Source, Source->GetPosition());
}

FVector
AAtom::GetPosition()
{
	return Position;
}

// Called when the game starts or when spawned
void AAtom::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
auto AAtom::Tick(float DeltaTime) -> void
{
	Super::Tick(DeltaTime);
}

FString AAtom::GetName() 
{
	return this->Name;
}

float AAtom::GetMass() {
	return this->Mass;
}

float AAtom::GetCharge()
{
	return this->Charge;
}

float AAtom::GetCovalentRadius()
{
	return this->CovalentRadius;
}

float AAtom::GetVanDerWaalsRadius()
{
	return this->VanDerWaalsRadius;
}

float AAtom::GetVanDerWaalsMagnitude()
{
	return this->VanDerWaalsMagnitude;
}
