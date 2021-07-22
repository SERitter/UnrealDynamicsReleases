// Fill out your copyright notice in the Description page of Project Settings.

//********************************************************************
// Code Organization:
//	UE4 Default Functions
//	Blueprint Accessible Functions
//		Dynamics - Getter Functions
//		Dynamics - Initializer Functions
//		Dynamics - Other Functions
//		Dynamics - Utility Functions
//		Dynamics - Setter Functions
//	C++ Private Functions
//		Adder Functions
//		Other Functions
//		Remover Functions
//		Update Functions
//********************************************************************

#include "ASimulation.h"

//********************************************************************
// UE4 Default Functions
//********************************************************************
// Sets default values
ASimulation::ASimulation()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::ASimulation() Called."));
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SystemEnergy = 0;
	SystemEnergyTolerance = 0.01;
	Temperature = 298.15;
	TimeScale = 1;
}

// Called when the game starts or when spawned
void ASimulation::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::BeginPlay() Called."));
	Super::BeginPlay();
}

// Called every frame
void ASimulation::Tick(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("ASimulation::Tick() Called."));
	Super::Tick(DeltaTime);
}

//********************************************************************
// Blueprint Accessible Functions
//********************************************************************
//********************************************************************
// Dynamics - Getter Functions
//********************************************************************
float ASimulation::GetMoleculeCounts()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetMoleculeCounts() Called - Still needs implementation."));
	return 0.0f;
}

int32 ASimulation::GetNumberOfMoleculesByType()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetNumberOfMoleculesByType() Called - Still needs implementation."));
	return 0;
}

int32 ASimulation::GetNumberOfMoleculesTotal()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetNumberOfMoleculesTotal() Called - Still needs implementation."));
	return 0;
}

float ASimulation::GetSimulationEnergy()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetSimulationEnergy() Called: %E."), SystemEnergy);
	return SystemEnergy;
}

float ASimulation::GetSimulationTemp()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetSimulationTemp() Called: %f."), Temperature);
	return Temperature;
}

TArray<FMoleculeConcentration> ASimulation::GetSimulationConcentrations()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetSimulationConcentrations() Called - Still needs implementation."));
	return TArray<FMoleculeConcentration>();
}

float ASimulation::GetSolventConcentration()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetSolventConcentration() Called - Still needs implementation."));
	return 0.0f;
}

float ASimulation::GetSimulationVolume()
{
	float volume = SimulationCell->GetVolume();
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetSimulationVolume() Called: %f."), volume);
	return volume;
}

float ASimulation::GetSolventDensity()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::GetSolventDensity() Called - Still needs implementation."));
	return 0.0f;
}

//********************************************************************
// Dynamics - Initializer Functions
//********************************************************************
void ASimulation::InitializeSimulation()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::InitializeSimulation() Called - Incomplete implementation."));

	UE_LOG(LogTemp, Warning, TEXT("ASimulation's Location is: %s"), *GetActorLocation().ToString());

	BuildDefaultPrototypes();
	UE_LOG(LogTemp, Warning, TEXT("Finished Call to Build DefaultPrototypes"));

	//density in kg/m^3
	//MolarMass in g/mol
	FVector Position;
	float CellWidth = SimulationCell->GetWidth() / 2;
	int32 NumAtoms = CalculateNumberOfSolventMolecules(998.2, 18.01528);
	for(int32 i = 0; i <= NumAtoms; i++)
	{
		Position = FVector(FMath::RandRange(-1 * CellWidth, CellWidth), FMath::RandRange(-1 * CellWidth, CellWidth), FMath::RandRange(-1 * CellWidth, CellWidth));
		UE_LOG(LogTemp, Warning, TEXT("Adding Molecule: %d - Position: [%f, %f, %f]"), i, Position.X, Position.Y, Position.Z);
		
		AddMolecule(TEXT("Water"), Position);
	}
}

void ASimulation::InitInteractionRadius(float Radius)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::InitInteractionRadius() Called - Still needs implementation."));
}

bool ASimulation::InitMoleculeData(FString FileName)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::InitMoleculeData() Called - Still needs implementation."));
	return false;
}

bool ASimulation::InitReactionData(FString FileName)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::InitReactionData() Called - Still needs implementation."));
	return false;
}

void ASimulation::InitSimulationCell(float CellWidth, FColor CellColor)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::InitSimulationCell(%f) Called."), CellWidth);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SimulationCell = GetWorld()->SpawnActor<ASimulationCell>(GetActorLocation(), GetActorRotation(), SpawnInfo);
	SimulationCell->InitVolume(CellWidth);
//	SimulationCell->SetLineThickness(LineThickness);
	SimulationCell->SetShapeColor(CellColor);
	//AttachToActor(this, FAttachmentTransformRules::SnapToTargetIncludingScale, this->GetRootComponent());
	SimulationCell->AttachToActor(this, FAttachmentTransformRules::SnapToTargetIncludingScale);
	SimulationCell->SetActorRelativeLocation(FVector(0.f, 0.f, (CellWidth/2.f)));
}

void ASimulation::InitSolvent(AMolecule* Solvent)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::InitSolvent() Called - Still needs implementation."));
}

//********************************************************************
// Dynamics - Other Functions
//********************************************************************
void ASimulation::CheckCollision()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::CheckCollision() Called - Still needs implementation."));
}

void ASimulation::UpdateSimulation()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::UpdateSimulation() Called - Still needs implementation."));
}

//********************************************************************
// Dynamics - Utility Functions
//********************************************************************
float ASimulation::Convert_C_to_F(float CTemp)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_C_to_F(%f) Called."), CTemp);
	return CTemp * (9 / 5) + 32;
}

float ASimulation::Convert_C_to_K(float CTemp)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_C_to_K(%f) Called."), CTemp);
	return CTemp + 273.15f;
}

float ASimulation::Convert_eV_to_J(float eVEnergy)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_eV_to_J() Called"), eVEnergy);
	return eVEnergy * 1.602176634e-19f;
}

float ASimulation::Convert_eV_to_kCal(float eVEnergy)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_eV_to_kCal()"), eVEnergy);
	return eVEnergy * 3.826732796e-23f;
}

float ASimulation::Convert_F_to_C(float FTemp)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_F_to_C(%f) Called."), FTemp);
	return (FTemp - 32.f) * 5.f / 9.f;
}

float ASimulation::Convert_F_to_K(float FTemp)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_F_to_K(%f) Called."), FTemp);
	return Convert_C_to_K(Convert_F_to_C(FTemp));
}

float ASimulation::Convert_J_to_eV(float JEnergy)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_J_to_eV(%E) Called"), JEnergy);
	return JEnergy / 1.602176634e-19f;
}

float ASimulation::Convert_K_to_C(float KTemp)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_K_to_C(%f) Called."), KTemp);
	return KTemp - 273.15f;
}

float ASimulation::Convert_K_to_F(float KTemp)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_K_to_F(%f) Called."), KTemp);
	return Convert_C_to_F(Convert_K_to_C(KTemp));
}

float ASimulation::Convert_kCal_to_eV(float kCalEnergy)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_kCal_to_eV(%E)"), kCalEnergy);
	return kCalEnergy / 3.826732796e-23f;
}

float ASimulation::Convert_L_to_pm3(float LVolume)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_L_to_pm3(%E) Called"), LVolume);
	return LVolume * 1e+33f;
}

float ASimulation::Convert_mL_to_pm3(float mLVolume)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_mL_to_pm3(%E) Called"), mLVolume);
	return mLVolume * 1e+30f;
}

float ASimulation::Convert_pm3_to_L(float pm3Volume)
{
	float mLVolume = pm3Volume * 1e-33;
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_pm3_to_L(%E) Called: %E"), pm3Volume, mLVolume);
	return mLVolume;
}

float ASimulation::Convert_pm3_to_mL(float pm3Volume)
{
	float mLVolume = pm3Volume * 1e-30;
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::Convert_pm3_to_mL(%E) Called: %E"), pm3Volume, mLVolume);
	return mLVolume;
}

//********************************************************************
// Dynamics - Setter Functions
//********************************************************************
void ASimulation::SetSimulationCellVolume(float Volume)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::SetSimulationCellVolume(%f) Called."), Volume);
	SimulationCell->SetVolume(Volume);
}

void ASimulation::SetSimulationCellWidth(float Width)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::SetSimulationCellWidth(%f) Called."), Width);
	SimulationCell->SetWidth(Width);
}

void ASimulation::SetSimulationTemp(float temp)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::SetSimulationTemp(%f) Called - Still needs implementation."),temp);
	Temperature = temp;
}

void ASimulation::SetSoluteConcentration()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::SetSoluteConcentration() Called - Still needs implementation."));
}

void ASimulation::SetTimeScale(float ScaleFactor)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::SetTimeScale(%f) Called."),ScaleFactor);
	TimeScale = ScaleFactor;
}

//********************************************************************
// C++ Private Functions
//********************************************************************
//********************************************************************
// Adder Functions
//********************************************************************
void ASimulation::AddHydrogenBond()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::AddHydrogenBond() Called - Still needs implementation."));
}

void ASimulation::AddMolecule(FString MoleculeName, FVector Position)
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::AddMolecule(%s) Called."),*MoleculeName);

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = SimulationCell;
	AMolecule* NewMolecule = GetWorld()->SpawnActor<AMolecule>(GetActorLocation(), GetActorRotation(), SpawnInfo);
	NewMolecule->AttachToActor(SimulationCell, FAttachmentTransformRules::SnapToTargetIncludingScale);
	NewMolecule->SetActorRelativeLocation(Position);

	if(!this->PrototypeMolecules.Contains(TEXT("Water")))
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR - ASimulation::AddMolecule(%s) - Not found in PrototypeMolecules List."),*MoleculeName);
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::AddMolecule(%s) - Prototype Molecule Found."), *MoleculeName);
	
	NewMolecule->InitMoleculeExactCopy(PrototypeMolecules[MoleculeName]);
	Molecules.Add(NewMolecule);

	UE_LOG(LogTemp, Warning, TEXT("ASimulation::AddMolecule(%s) Completed."), *MoleculeName);
}

void ASimulation::AddReaction()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::AddReaction() Called - Still needs implementation."));
}

//********************************************************************
// Other Functions
//********************************************************************
void ASimulation::AdjustSystemEnergy()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::AdjustSystemEnergy() Called - Still needs implementation."));
}

void ASimulation::BuildDefaultPrototypes()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::BuildDefaultPrototypes() Called."));

	FString Name = TEXT("Water");
	FString MolecularFormula = TEXT("H2O");

	TArray<AAtom *> WaterAtoms;
	TArray<ABond *> WaterBonds;

	AAtom *NewAtom;
	AAtom *O;
	AAtom *H1;
	AAtom *H2;
	ABond *NewBond;
	AMolecule *WaterMolecule;

	// Define atom prototypes.
	NewAtom = NewObject<AAtom>();
	NewAtom->InitAtomPrototype(
		TEXT("Hydrogen"),
		TEXT("H"),
		TEXT("HW"), // Hydrogen in water
		FColor::White,
		1.00794,
		0,
		37,
		0.01,
		0.0000);
	this->PrototypeAtoms.Add(NewAtom->GetName(), NewAtom);
	NewAtom = NewObject<AAtom>();
	NewAtom->InitAtomPrototype(
		TEXT("Oxygen"),
		TEXT("O"),
		TEXT("OW"), // Hydrogen in water
		FColor::Red,
		15.9994,
		0,
		73,
		176.83,
		0.1520);
	this->PrototypeAtoms.Add(NewAtom->GetName(), NewAtom);

	// Water atoms.
	O = NewObject<AAtom>();
	O->InitAtomCopy(this->PrototypeAtoms[TEXT("Oxygen")], FVector(0.53890, 0.65566, 0.00000));
	WaterAtoms.Add(O);
	H1 = NewObject<AAtom>();
	H1->InitAtomCopy(this->PrototypeAtoms[TEXT("Hydrogen")], FVector(1.50890, 0.65566, 0.00000));
	WaterAtoms.Add(H1);
	H2 = NewObject<AAtom>();
	H2->InitAtomCopy(this->PrototypeAtoms[TEXT("Hydrogen")], FVector(0.21557, 1.56969, -0.03013));
	WaterAtoms.Add(H2);
	// Water bonds.
	NewBond = NewObject<ABond>();
	NewBond->InitBond(
		TEXT("O-H1"),
		TEXT("Single"),
		0.9572,
		553.0,
		FColor::Blue,
		O,
		H1);
	WaterBonds.Add(NewBond);
	NewBond = NewObject<ABond>();
	NewBond->InitBond(
		TEXT("O-H2"),
		TEXT("Single"),
		0.9572,
		553.0,
		FColor::Blue,
		O,
		H2);
	WaterBonds.Add(NewBond);

	WaterMolecule = NewObject<AMolecule>();
	WaterMolecule->InitMoleculePrototype(
		Name,
		MolecularFormula,
		WaterAtoms,
		WaterBonds,
		FVector(0, 0, 0)
	);

	UE_LOG(LogTemp, Warning, TEXT("ProtoypeMolecule Names: %s"), *Name);
	this->PrototypeMolecules.Add(TEXT("Water"), WaterMolecule);
}

float ASimulation::CalculateNetForceForMolecule()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::CalculateNetForceForMolecule() Called - Still needs implementation."));
	return 0.0f;
}

bool ASimulation::CheckReaction()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::CheckReaction() Called - Still needs implementation."));
	return false;
}

int32 ASimulation::CalculateNumberOfSolventMolecules(float Density, float MolarMass)
{
	float Atoms = (((Density * 1e-33) / MolarMass) * AVOGADRO) * GetSimulationVolume();
	//kg to g and m^3 to pm^3
	int32 NumAtoms = FMath::Floor(Atoms);
	
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::CalculateNumberOfSolventMolecules(%f, %f) Called: %E, %d"), Density, MolarMass, Atoms, NumAtoms);
	return NumAtoms;
}

FVector ASimulation::CalculateSolventMoleculePosition(int32 CurrentCount, int TotalNum)
{
	return FVector();
}

void ASimulation::ProcessHBonds()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::ProcessHBonds() Called - Still needs implementation."));
}

void ASimulation::SetReactionDistance()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::SetReactionDistance() Called - Still needs implementation."));
}

//********************************************************************
// Remover Functions
//********************************************************************
void ASimulation::RemoveHydrogenBond()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::RemoveHydrogenBond() Called - Still needs implementation."));
}

void ASimulation::RemoveMolecule()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::RemoveMolecule() Called - Still needs implementation."));
}

void ASimulation::RemoveReaction()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::RemoveReaction() Called - Still needs implementation."));
}

//********************************************************************
// Update Functions
//********************************************************************
void ASimulation::UpdateForcesOnMolecules()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::UpdateForcesOnMolecules() Called - Still needs implementation."));
}

void ASimulation::UpdateSystemEnergy()
{
	UE_LOG(LogTemp, Warning, TEXT("ASimulation::UpdateSystemEnergy() Called - Still needs implementation."));
}
