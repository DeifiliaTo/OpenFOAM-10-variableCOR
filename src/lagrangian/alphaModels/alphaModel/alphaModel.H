/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2020 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::alphaModel

Description
    A library of runtime-selectable alpha  models.

    Returns a sampled value, possibly dependent on the particle diameter and velocity

    Current alpha models include:
    - fixedValue
    - general

SourceFiles
    alphaModel.C
    alphaModelNew.C

\*---------------------------------------------------------------------------*/

#ifndef alphaModel_H
#define alphaModel_H

#include "IOdictionary.H"
#include "autoPtr.H"
#include "Random.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                      Class alphaModel Declaration
\*---------------------------------------------------------------------------*/

class alphaModel
{


protected:

    // Protected data

        //- Coefficients dictionary
        const dictionary alphaModelDict_;

    //- Is the function dependent on diameter or velocity
        bool diameter_;

    // Protected Member Functions

        //- Check that the distribution model is valid
        virtual void check() const;

        //- Print information about the distribution
        void info() const;


public:

    //-Runtime type information
    TypeName("alphaModel");


    //- Declare runtime constructor selection table
    declareRunTimeSelectionTable
    (
        autoPtr,
        alphaModel,
        dictionary,
        (
            const dictionary& dict
        ),
        (dict)
    );


    // Constructors

        //- Construct from dictionary
        alphaModel
        (
            const word& name,
            const dictionary& dict
        );

        //- Construct copy
        alphaModel(const alphaModel& p);

        //- Construct and return a clone
        virtual autoPtr<alphaModel> clone() const = 0;


    //- Selector
    static autoPtr<alphaModel> New
    (
        const dictionary& dict
    );


    //- Destructor
    virtual ~alphaModel();


    // Member Functions

        //- Sample the alphaModel
        virtual scalar sample(scalar) const = 0;

        //- Return whether the diameter switch
        virtual bool diameter() const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
