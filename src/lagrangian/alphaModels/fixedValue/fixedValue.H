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
    Foam::alphaModels::fixedValue

Description
    Returns a fixed value

SourceFiles
    fixedValue.C

\*---------------------------------------------------------------------------*/

#ifndef fixedValue_H
#define fixedValue_H

#include "alphaModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace alphaModels
{
/*---------------------------------------------------------------------------*\
                         Class fixedValue Declaration
\*---------------------------------------------------------------------------*/

class fixedValue
:
    public alphaModel
{
    // Private Data

        //- Fixed value
        scalar value_;


public:

    //- Runtime type information
    TypeName("fixedValue");


    // Constructors

        //- Construct from components
        fixedValue(const dictionary& dict);

        //- Construct copy
        fixedValue(const fixedValue& p);

        //- Construct and return a clone
        virtual autoPtr<alphaModel> clone() const
        {
            return autoPtr<alphaModel>(new fixedValue(*this));
        }


    //- Destructor
    virtual ~fixedValue();


    // Member Functions

        //- Sample the alphaModel
        virtual scalar sample() const;

        //- Return the minimum value
        virtual scalar minValue() const;

        //- Return the maximum value
        virtual scalar maxValue() const;

        //- Return the mean value
        virtual scalar meanValue() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace alphaModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
