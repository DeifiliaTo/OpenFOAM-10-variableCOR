/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2021 OpenFOAM Foundation
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

#include "general.H"
#include "IFstream.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace alphaModels
{
    defineTypeNameAndDebug(general, 0);
    addToRunTimeSelectionTable(alphaModel, general, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::alphaModels::general::general
(
    const dictionary& dict
)
:
    alphaModel(typeName, dict),
    alphaTable_(nullptr)
{
    check();

    alphaTable_.reset(Function1<scalar>::New("alpha", alphaModelDict_).ptr());

    // Additional sanity checks
    info();
}


Foam::alphaModels::general::general(const general& p)
:
    alphaModel(p)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::alphaModels::general::~general()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::scalar Foam::alphaModels::general::sample(scalar d) const
{
    return alphaTable_->value(d);
}


bool Foam::alphaModels::general::diameter() const
{
    return diameter_;
}


// ************************************************************************* //
