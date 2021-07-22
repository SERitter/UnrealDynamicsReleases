// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "AAtom.generated.h"


UCLASS()
class AAtom : public AActor
{
	GENERATED_BODY()
public:
	/**
	 * Default constructor.
	 */
	AAtom();

	/**
	 * Initializes an atom prototype object.  The prototype has position, velocity, etc set to zero.
	 * The AMBER 94 type lets us have atoms of the same element in different bond conditions, which will have different Van Der Waals parameters etc.
	 * @param NewName - Full English name of the atom
	 * @param NewSymbol - Atomic Symbol
	 * @param NewType - AMBER 94 type of atom
	 * @param NewColor - The colour to use for this atom.
	 * @param NewMass - Mass of the atom, in atomic mass units (or g/mol).
	 * @param NewCharge - Charge of the atom, in multiples of fundemental charges
	 * @param NewCovalentRadius - Covalent Radius of the atom, in Angstroms
	 * @param NewVanDerWaalsRadius - The AMBER94 van der Waals radius of the atom, in Angstroms
	 * @param NewVanDerWaalsMagnitude -/** The AMBER94 van der waals attraction magnitude of the Atom, in kCal/mol
	*/
	UFUNCTION()
	void InitAtomPrototype(
		FString NewName,
		FString NewSymbol,
		FString NewType,
		FLinearColor NewColor,
		float NewMass,
		int32 NewCharge,
		float NewCovalentRadius,
		float NewVanDerWaalsRadius,
		float NewVanDerWaalsMagnitude);

	/**
	 * Makes a new atom with the same properties as the source, at the new
	 * position.
	 * @param Source - The prototype to copy properties from.
	 * @param NewPosition - The position of the atom in the molecule, in angstroms.
	 */
	UFUNCTION()
	void InitAtomCopy(AAtom *Source, FVector NewPosition);

	/**
	 * Makes a new atom with the same properties as the source, at the same position.
	 * @param Source - The prototype to copy properties from.
	 */
	UFUNCTION()
	void InitAtomExactCopy(AAtom *Source);

	UFUNCTION()
	FVector GetPosition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString GetName();

	/**
	 * @return Get the atom's mass, in atomic mass units (or g/mol).
	 */
	float GetMass();

	float GetCharge();
	float GetCovalentRadius();
	float GetVanDerWaalsRadius();
	float GetVanDerWaalsMagnitude();

private:
	/** Full English name of the atom*/
	UPROPERTY()
	FString Name;

	/** AMBER 94 type of atom*/
	UPROPERTY()
	FString Type;

	/** Atomic Symbol*/
	UPROPERTY()
	FString Symbol;

	/** Stores a representation of the bond for use in engine. */
	UPROPERTY()
		UStaticMeshComponent* AtomRepresentation;

	/** Stores the material for the static mesh of the representation. */
	UPROPERTY()
		UMaterial* AtomMaterial;

	/** Stores the desired Color for the Material for the representation. */
	UPROPERTY()
		FLinearColor Color;

	/** Covalent Radius of the atom, in Angstroms*/
	UPROPERTY()
	float CovalentRadius;

	/** Charge of the atom, in multiples of fundemental charges */
	UPROPERTY()
	int32 Charge;

	UPROPERTY()
	float Mass;

	UPROPERTY()
	FVector Position;

	/** The AMBER94 van der Waals radius of the atom, in Angstroms */
	UPROPERTY()
	float VanDerWaalsRadius;

	/** The AMBER94 van der waals attraction magnitude of the Atom, in kCal/mol */
	UPROPERTY()
	float VanDerWaalsMagnitude;
};
