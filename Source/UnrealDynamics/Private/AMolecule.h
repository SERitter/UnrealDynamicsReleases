// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AAtom.h"
#include "ABond.h"
#include "Components/SphereComponent.h"
#include "AMolecule.generated.h"

UCLASS()
class AMolecule : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMolecule();
	
	/**
	 * Initialize a prototype molecule.  Calculates total mass and dipole moment.  Position etc are set to zero.
	 * @param NewName - Name of the molecule ("water" etc).
	 * @param NewMolecularFormula - Chemical formula for the molecule.
	 * @param NewAtoms - Atoms to put into the molecule.  Atom positions are relative to molecule's origin.
	 * @param NewBonds - List of bonds between atoms.
	 * @param NewDipoleMoment - Overall dipole moment of the molecule.
	 */
	void InitMoleculePrototype(
		FString NewName,
		FString NewMolecularFormula,
		TArray<AAtom*> NewAtoms,
		TArray<ABond*> NewBonds,
		FVector NewDipoleMoment
	);

	void InitMoleculeExactCopy(AMolecule *Source);

	/**
	 * Make a new molecule from a prototype.  Copies properties from the Source molecule.  Creates new AAtom objects as copies of those in the prototype.
	 * @param Source - Molecule object to copy properties from.
	 * @param NewPosition - Initial position of this molecule's origin.
	 * @param NewVelocity - Initial velocity.
	 * @param NewOrientation - Initial orientation.
	 * @param NewAngularVelocity - Initial rotational speed.
	 */
	void InitMoleculeCopy(
		AMolecule* Source,
		FVector NewPosition,
		FVector NewVelocity,
		FVector NewOrientation,
		FVector NewAngularVelocity
	);
	

	/** The name of this molecule ("water" etc.). */
	UFUNCTION()
		FString GetName();

	/** Chemical formula for the molecule. */
	UFUNCTION()
		FString GetMolecularFormula();

	/** Sum of all the atom masses in the molecule. */
	UFUNCTION()
		float GetTotalMass();

	/** Dipole moment of the molecule, in appropriate units. */
	UFUNCTION()
		FVector GetDipoleMoment();

	UFUNCTION()
	FVector GetPosition();

	//UFUNCTION()
	//FVector GetVelocity();

	UFUNCTION()
	FVector GetOrientation();

	UFUNCTION()
	FVector GetAngularVelocity();

	/**
	 * Record the list of molecules that are within this molecule's interaction radius.
	 * ASimulation will make a list like this for each molecule, then use it when calculating the forces on the molecule.
	 * (NOTE: Check how Unreal handles many-body forces like this; it might have
	 * a preferred way to handle them.)
	 * */
	UFUNCTION()
	void SetInteractingMolecules(TArray<AMolecule *> MoleculeList);
	
	UFUNCTION()
		TArray<AMolecule*> GetInteractingMolecules();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	USphereComponent* CenterOfMassIndicator;
	
	/** Is this a "prototype" molecule?  (If so, don't draw or interact.) */
	UPROPERTY()
		bool IsPrototype;

	/** Name of the molecule ("water" etc). */
	UPROPERTY()
		FString Name;

	/** Chemical formula for the molecule. */
	UPROPERTY()
		FString MolecularFormula;

	/** List of atoms in this molecule.  Atom positions are relative to molecule's origin. */
	UPROPERTY()
		TArray<AAtom*> Atoms;

	/** List of bonds between atoms. */
	UPROPERTY()
		TArray<ABond*> Bonds;

	/** Sum of all the atom masses in the molecule. */
	UPROPERTY()
		float TotalMass;

	/** Dipole moment of the molecule, in appropriate units. */
	UPROPERTY()
		FVector DipoleMoment;

	/** List of molecules within this molecule's interaction radius. */
	UPROPERTY()
		TArray<AMolecule*> InteractingMolecules;

	UPROPERTY()
	FVector Position;

	UPROPERTY()
	FVector Orientation;

	UPROPERTY()
	FVector Velocity;

	/** Rate of rotation of the molecule. */
	UPROPERTY()
		FVector AngularVelocity;

	/** Net force on the molecule (calculated by Simulation). */
	UPROPERTY()
		FVector NetForce;

	/** Net torque on the molecule (calculated by Simulation). */
	UPROPERTY()
		FVector NetTorque;  // TK Maybe?  Check how Unreal does rotations.
};
