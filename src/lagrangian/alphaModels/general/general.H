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

Class
    Foam::alphaModels::general

Description
    A general alpha model where the distribution is specified as
    (point, value) pairs. By default the values are assumed to represent
    a probability density function, but the model also supports specifying a
    cumulative distribution function. In both cases it is assumed that the
    function is linear between the specified points.

    In both modes of operation the values are automatically normalised.

SourceFiles
    general.C

\*---------------------------------------------------------------------------*/

#ifndef general_H
#define general_H

#include "alphaModel.H"
#include "Function1.H"
#include "Vector.H"
#include "VectorSpace.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace alphaModels
{

/*---------------------------------------------------------------------------*\
                           Class general Declaration
\*---------------------------------------------------------------------------*/

class general
:
    public alphaModel
{
    // Private Data

        typedef VectorSpace<Vector<scalar>, scalar, 2> pair;

        //- 2D function for alpha        
        autoPtr<Function1<scalar>> alphaTable_;

    
public:

    //- Runtime type information
    TypeName("general");


    // Constructors

        //- Construct from components
        general(const dictionary& dict);

        //- Construct copy
        general(const general& p);

        //- Construct and return a clone
        virtual autoPtr<alphaModel> clone() const
        {
            return autoPtr<alphaModel>(new general(*this));
        }


    //- Destructor
    virtual ~general();


    // Member Functions

        //- Sample the distributionModel
        virtual scalar sample(scalar) const;

        //- Return the diameter value
        virtual bool diameter() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace alphaModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
