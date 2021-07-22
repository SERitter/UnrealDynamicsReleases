#pragma once

/*

A reactant molecule and its concentration.  Used to initialize the simulation.

*/

#include "UObject/Class.h"
#include "AMolecule.h"
#include "FMoleculeConcentration.generated.h"

USTRUCT(BlueprintType)
struct FMoleculeConcentration
{
    GENERATED_BODY()

        /** Name of the molecule. */
        UPROPERTY()
        FString ReactantName;

    /** Reactant concentration (moles per litre solution). */
    UPROPERTY()
        float Concentration;
};
