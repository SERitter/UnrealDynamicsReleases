// Fill out your copyright notice in the Description page of Project Settings.


#include "AMolecule.h"

AMolecule::AMolecule()
{
	CenterOfMassIndicator = CreateDefaultSubobject<USphereComponent>(TEXT("CenterOfMass"));

	SetRootComponent(CenterOfMassIndicator);
	CenterOfMassIndicator->SetHiddenInGame(false);
	CenterOfMassIndicator->SetSphereRadius(170.f);
}

// AMolecule::AMolecule(FString Name, FString MolecularFormula, TArray<AAtom*> Atoms, TArray<ABond*> Bonds,
// 	FVector DipoleMoment, FVector Position, FVector Velocity, FVector Orientation, FVector AngularVelocity)
// {
// }

void AMolecule::InitMoleculePrototype( FString NewName, FString NewMolecularFormula, TArray<AAtom *> NewAtoms, TArray<ABond *> NewBonds, FVector NewDipoleMoment)
{
	int32 i;

	this->Name = NewName;
	this->MolecularFormula = NewMolecularFormula;
	this->DipoleMoment = NewDipoleMoment;

	// This makes new copies of the arrays (not just copying the array address).
	this->Atoms = NewAtoms;
	this->Bonds = NewBonds;

	// Calculate molecule's total mass.
	this->TotalMass = 0;
	for (i = 0; i < this->Atoms.Num(); ++i) {
		this->TotalMass += this->Atoms[i]->GetMass();
	}

	// Calculate molecule's centre of mass, and shift the atom coordinates to put the CM at the origin.
	FVector cm(0, 0, 0);
	for (i = 0; i < this->Atoms.Num(); ++i) {
		cm += (this->Atoms[i]->GetMass())*this->Atoms[i]->GetPosition();
	}
	cm /= this->TotalMass;
	for (i = 0; i < this->Atoms.Num(); ++i) {
		this->Atoms[i]->GetPosition() -= cm;
	}

	// TODO: Set the "Actor" locations for the atoms to put the visual representations
	// at the right places.
	// (Something about SetActorLocation...)
	// NOTE: Might not have to do this for prototypes!  (In which case it would go in the next constsructor, below.)

	// TODO: Draw the bonds, now that the atom locations are set up in the CM coordinates.
	// NOTE: Might not have to do this for prototypes!  (In which case it would go in the next constsructor, below.)
}

void AMolecule::InitMoleculeExactCopy(AMolecule *Source)
{
	UE_LOG(LogTemp, Warning, TEXT("AMolecule::InitMoleculeExactCopy() Called."));
	this->InitMoleculeCopy(Source, Source->GetPosition(), Source->GetVelocity(), Source->GetOrientation(), Source->GetAngularVelocity());
}

void AMolecule::InitMoleculeCopy( AMolecule *Source, FVector NewPosition, FVector NewVelocity, FVector NewOrientation, FVector NewAngularVelocity)
{
	int32 i;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Copy properties from the source molecule.
	this->Name = Source->Name;
	this->MolecularFormula = Source->MolecularFormula;
	this->DipoleMoment = Source->DipoleMoment;

	// Need to make new (deep) copies of the atoms and bonds, in case we want to
	// handle oscillations etc.
	for (i = 0; i < Source->Atoms.Num(); ++i) {
		// AAtom NewAtom = *(Source->Atoms[i]);
		AAtom *NewAtom = NewObject<AAtom>();
		NewAtom->InitAtomExactCopy(Source->Atoms[i]);
		this->Atoms.Add(NewAtom);
	}
	for (i = 0; i < Source->Bonds.Num(); ++i) {
		// ABond NewBond = *(Source->Bonds[i]);
		ABond *NewBond = NewObject<ABond>();
		NewBond->InitBondExactCopy(Source->Bonds[i]);
		this->Bonds.Add(NewBond);
	}

	// Initialize the new molecule.
	this->Position = NewPosition;
	this->Velocity = NewVelocity;
	this->Orientation = NewOrientation;
	this->AngularVelocity = NewAngularVelocity;
}

FString AMolecule::GetName()
{
	return this->Name;
}

FString AMolecule::GetMolecularFormula()
{
	return this->MolecularFormula;
}

float AMolecule::GetTotalMass()
{
	return this->TotalMass;
}

FVector AMolecule::GetDipoleMoment()
{
	return this->DipoleMoment;
}

FVector AMolecule::GetPosition()
{
	return this->Position;
}

/*
FVector AMolecule::GetVelocity()
{
	return this->Velocity;
}
*/

FVector AMolecule::GetOrientation()
{
	return this->Orientation;
}

FVector AMolecule::GetAngularVelocity()
{
	return this->AngularVelocity;
}

void AMolecule::SetInteractingMolecules(TArray<AMolecule *> MoleculeList)
{
	
}

TArray<AMolecule*> AMolecule::GetInteractingMolecules()
{
	return TArray<AMolecule*>();
}

// Called when the game starts or when spawned
void AMolecule::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMolecule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

