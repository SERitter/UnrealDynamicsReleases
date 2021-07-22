Word to Markdown Converter
Results of converting "Simulation Cell Analysis"
Markdown
Simulation Cell: Analysis

Revision: 0

Shawn Ritter

**Introduction**

This document is an attempt to clarify thinking about the simulation cell problem and to refine an understanding of how a solution to the simulation cell might be approached. It is intended to capture my current understanding of the problem domain and to break the problem into tractable pieces that can be tackled by team members. Any insights or comments are welcome and should be emailed to [shawn.ritter@kingsu.ca](mailto:shawn.ritter@kingsu.ca). I will attempt to be very explicit in this analysis so that future team members will be able to clearly understand my thought process in approaching this problem, and I hope this document will provide team members with a solid foundation from which they will be able to assist with the refinement of this document and the resulting implementation.

**Object Oriented Analysis**

**Noun extraction**

In traditional OOA, one of the first steps typically taken is to use what is called the noun extraction method to find candidate entity classes which can then be refined as part of a possible solution to a problem. The first step in this process is to attempt to describe the software goal in a single paragraph. After the paragraph has been crafted, the next step is to identify the nouns in that paragraph. These will become candidate entity classes. Abstract nouns, which identify things that have no physical existence rarely become an entity class and are more likely to be attributes existing in another class. I present here my current understanding of the problem in a short paragraph intended to be used for noun extraction:

Our goal is to create a simplified molecular-dynamics simulation that can run inside the Unreal Engine, and which can update in real-time. The simulation is intended to model the movement and collision of molecules and atoms inside a simulation cell. The focus of the simulation is to model the movements of molecules and atoms by utilizing Newton&#39;s equations of motion for a system of interacting particles. In this system forces between the particles and their potential energies will be calculated using molecular mechanics force fields as described in the AMBER system. Molecules are a collection of covalently bonded atoms, and if the molecules collide with the appropriate orientation and energy a reaction can occur. The intention is that the simulation cell can have a variety of distinct molecules added and the quantity or concentration of the molecules can be set at run-time. The simulation cell is expected to be able to report the current energy of the molecules being simulated and to adjust the energy of the system as desired by the user.

From this paragraph we can begin to think about what classes might be needed, but we should be aware that there are likely to be additional classes and objects that will be of use. Through careful consideration of the classes here and use cases of our simulation cell we should be able to refine our solution. At this stage we are looking for what are called entity classes. Entity classes model information that is long lived, and often correspond to concrete things.

Molecular-dynamics, simulation, Unreal Engine, update, real-time, model, movement, collision, atoms, molecules, simulation cell, focus, Newton&#39;s Equations of motion, system, interacting, particles, potential energies, molecular mechanics force fields, AMBER, collection, covalently bonded, orientation, energy, reaction, intention, variety, distinct, quantity, concentration, run-time, report, current energy, user

Several of these nouns are abstract, and many of them will be referring to attributes that will arise in our solution. Some of these nouns might be different terms that refer to the same object or concept. In this first pass the nouns that jump out as being important are the following:

**Simulation -** The object that contains the molecular-dynamics simulation and interfaces with the unreal engine.

**Molecule -** An object in the simulation composed of atoms and covalent bonds to which Newton&#39;s equations of motion are applied.

**Atom –** An object inside a molecule contributing mass, charge, electrostatic potential and AMBER force fields to the molecule.

**Reaction –** An object in the simulation cell that occurs when two molecules collide with the appropriate orientation, energy, and atoms.

**Bond –** Indicates a relationship between two atoms

**Covalent Bond –** Indicates that two atoms are covalently linked inside of a molecule.

**Hydrogen Bond –** Indicates the presence of a Hydrogen bond between two atoms.

The user interacts with the Unreal Engine and the Unreal Engine contains and runs the simulation. These objects lie outside of the problem boundary and can be ignored. I will explore the other nouns in more detail as I build information about the classes and their attributes. For now, I have prepared a class diagram based upon the entities we have identified in bold above.

![](RackMultipart20210719-4-krjfbi_html_10cd2c6c72b22b38.png)

_Figure 1 - The first iteration of the class diagram for the simulation cell problem._

An alternative method to the noun extraction process for entity class creation is known as CRC cards. Class-responsibility-collaboration cards are used to explore the functionality and connections of classes in a system. These provide a powerful tool for revealing insight about missing or incorrect fields in a class and they help to clarify relationships among the classes. I will begin to build and list the CRC cards for this project below. In the figures below, the class name is in the top box, the attributes of the class are in the second box and the responsibilities of the class are in the third box.

![](RackMultipart20210719-4-krjfbi_html_2d6bd3b78a16de3e.png)

_Figure 2- The first revision of the CRC cards for the simulation problem._

The next step is to attempt to do some dynamic modelling and to begin to build statecharts for the various classes we are building. This is accomplished by examining the possible states, of the class and events that might trigger a transition to or from that state. This will help us to think deeper about the responsibilities or functionality of a class.
Rendered
Simulation Cell: Analysis

Revision: 0

Shawn Ritter

Introduction

This document is an attempt to clarify thinking about the simulation cell problem and to refine an understanding of how a solution to the simulation cell might be approached. It is intended to capture my current understanding of the problem domain and to break the problem into tractable pieces that can be tackled by team members. Any insights or comments are welcome and should be emailed to shawn.ritter@kingsu.ca. I will attempt to be very explicit in this analysis so that future team members will be able to clearly understand my thought process in approaching this problem, and I hope this document will provide team members with a solid foundation from which they will be able to assist with the refinement of this document and the resulting implementation.

Object Oriented Analysis

Noun extraction

In traditional OOA, one of the first steps typically taken is to use what is called the noun extraction method to find candidate entity classes which can then be refined as part of a possible solution to a problem. The first step in this process is to attempt to describe the software goal in a single paragraph. After the paragraph has been crafted, the next step is to identify the nouns in that paragraph. These will become candidate entity classes. Abstract nouns, which identify things that have no physical existence rarely become an entity class and are more likely to be attributes existing in another class. I present here my current understanding of the problem in a short paragraph intended to be used for noun extraction:

Our goal is to create a simplified molecular-dynamics simulation that can run inside the Unreal Engine, and which can update in real-time. The simulation is intended to model the movement and collision of molecules and atoms inside a simulation cell. The focus of the simulation is to model the movements of molecules and atoms by utilizing Newton's equations of motion for a system of interacting particles. In this system forces between the particles and their potential energies will be calculated using molecular mechanics force fields as described in the AMBER system. Molecules are a collection of covalently bonded atoms, and if the molecules collide with the appropriate orientation and energy a reaction can occur. The intention is that the simulation cell can have a variety of distinct molecules added and the quantity or concentration of the molecules can be set at run-time. The simulation cell is expected to be able to report the current energy of the molecules being simulated and to adjust the energy of the system as desired by the user.

From this paragraph we can begin to think about what classes might be needed, but we should be aware that there are likely to be additional classes and objects that will be of use. Through careful consideration of the classes here and use cases of our simulation cell we should be able to refine our solution. At this stage we are looking for what are called entity classes. Entity classes model information that is long lived, and often correspond to concrete things.

Molecular-dynamics, simulation, Unreal Engine, update, real-time, model, movement, collision, atoms, molecules, simulation cell, focus, Newton's Equations of motion, system, interacting, particles, potential energies, molecular mechanics force fields, AMBER, collection, covalently bonded, orientation, energy, reaction, intention, variety, distinct, quantity, concentration, run-time, report, current energy, user

Several of these nouns are abstract, and many of them will be referring to attributes that will arise in our solution. Some of these nouns might be different terms that refer to the same object or concept. In this first pass the nouns that jump out as being important are the following:

Simulation - The object that contains the molecular-dynamics simulation and interfaces with the unreal engine.

Molecule - An object in the simulation composed of atoms and covalent bonds to which Newton's equations of motion are applied.

Atom – An object inside a molecule contributing mass, charge, electrostatic potential and AMBER force fields to the molecule.

Reaction – An object in the simulation cell that occurs when two molecules collide with the appropriate orientation, energy, and atoms.

Bond – Indicates a relationship between two atoms

Covalent Bond – Indicates that two atoms are covalently linked inside of a molecule.

Hydrogen Bond – Indicates the presence of a Hydrogen bond between two atoms.

The user interacts with the Unreal Engine and the Unreal Engine contains and runs the simulation. These objects lie outside of the problem boundary and can be ignored. I will explore the other nouns in more detail as I build information about the classes and their attributes. For now, I have prepared a class diagram based upon the entities we have identified in bold above.



Figure 1 - The first iteration of the class diagram for the simulation cell problem.

An alternative method to the noun extraction process for entity class creation is known as CRC cards. Class-responsibility-collaboration cards are used to explore the functionality and connections of classes in a system. These provide a powerful tool for revealing insight about missing or incorrect fields in a class and they help to clarify relationships among the classes. I will begin to build and list the CRC cards for this project below. In the figures below, the class name is in the top box, the attributes of the class are in the second box and the responsibilities of the class are in the third box.



Figure 2- The first revision of the CRC cards for the simulation problem.

The next step is to attempt to do some dynamic modelling and to begin to build statecharts for the various classes we are building. This is accomplished by examining the possible states, of the class and events that might trigger a transition to or from that state. This will help us to think deeper about the responsibilities or functionality of a class.

Want to convert another document?

Feedback
Source
Donate
Terms
Privacy
@benbalter