/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2019 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "alphaModel.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(alphaModel, 0);
    defineRunTimeSelectionTable(alphaModel, dictionary);
}


// * * * * * * * * * * * * * Protected Member Functions  * * * * * * * * * * //

void Foam::alphaModel::check() const
{
    if (minValue() < 0)
    {
        FatalErrorInFunction
            << type() << "distribution: Minimum value must be greater than "
            << "zero." << nl << "Supplied minValue = " << minValue()
            << abort(FatalError);
    }

    if (maxValue() < minValue())
    {
        FatalErrorInFunction
            << type() << "distribution: Maximum value is smaller than the "
            << "minimum value:" << nl << "    maxValue = " << maxValue()
            << ", minValue = " << minValue()
            << abort(FatalError);
    }
}


void Foam::alphaModel::info() const
{
    Info<< "    Distribution min: " << minValue() << " max: " << maxValue()
        << " mean: " << meanValue() << endl;
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::alphaModel::alphaModel
(
    const word& name,
    const dictionary& dict
)
:
    alphaModelDict_(dict.subDict(name + "Distribution"))
{}


Foam::alphaModel::alphaModel
(
    const alphaModel& p
)
:
    alphaModelDict_(p.alphaModelDict_)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::alphaModel::~alphaModel()
{}


// ************************************************************************* //
