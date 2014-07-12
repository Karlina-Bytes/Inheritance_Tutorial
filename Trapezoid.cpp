//******************************************************************************
//  Trapezoid.cpp
//  Inheritance
//
//  Created by Karlina Beringer on July 10, 2014.
//
//  This source file contains the Trapezoid class definition.
//  Trapezoid is derived from the Quadrilateral class.
//******************************************************************************

#include "Trapezoid.h"

// Helper method forces exactly two sides to be parallel.
void Trapezoid::setAttributes()
{
    // Check that only AB and CD are parallel
    // or else that only BC and DA are parallel; not both!
    double slope_AB = A.getSlope( B );
    double slope_CD = C.getSlope( D );
    double slope_BC = B.getSlope( C );
    double slope_AD = A.getSlope( D );
    if (!(slope_AB == slope_CD xor slope_BC == slope_AD))
    {
        A = Point( 0, 0 );
        B = Point( 1, 1 );
        C = Point( 3, 1 );
        D = Point( 5, 0 );
    }
    
    // Set Trapezoid-specific attributes.
    if (slope_AB == slope_CD)
    {
        if (A.getDistance( B ) > C.getDistance( D ))
        {
            base1 = A.getDistance( B );
            base2 = C.getDistance( D );
        }
        else
        {
            base1 = C.getDistance( D );
            base2 = A.getDistance( B );
        }
        height = B.getDistance( C );
    }
    else
    {
        if (B.getDistance( C ) > D.getDistance( A ))
        {
            base1 = B.getDistance( C );
            base2 = D.getDistance( A );
        }
        else
        {
            base1 = D.getDistance( A );
            base2 = B.getDistance( C );
        }
        height = A.getDistance( B );
    }
}

// Default constructor calls Quadrilateral's default constructor.
Trapezoid::Trapezoid(): Quadrilateral()
{
    setAttributes();
}

// Normal constructor calls Quadrilateral's normal constructor.
Trapezoid::Trapezoid( Point A, Point B, Point C, Point D ):
Quadrilateral( A, B, C, D )
{
    setAttributes();
}

// Copy constructor calls Quadrilateral's copy constructor.
Trapezoid::Trapezoid( Quadrilateral & quad ): Quadrilateral( quad )
{
    setAttributes();
}

// Getter returns the area of this Quadrilateral.
// Override the method to customize it for Trapezoid.
// Area = [(Base1 + Base2) * Height] / 2
double Trapezoid::getArea()
{
    return (( base1 + base2 ) * height) / 2;
}

// Print the contents of this Quadrilateral.
// Override the method to customize it for Trapezoid.
// If no ostream parameter is supplied, default will be cout.
void Trapezoid::print( ostream & output )
{
    output << "------------------------\n";
    output << TYPE << "\n";
    output << "------------------------\n";
    output << "Points:\n";
    output << "\tA = " << A << "\n";
    output << "\tB = " << B << "\n";
    output << "\tC = " << C << "\n";
    output << "\tD = " << D << "\n";
    output << "Side Lengths:\n";
    output << "\tAB = " << A.getDistance( B ) << "\n";
    output << "\tBC = " << B.getDistance( C ) << "\n";
    output << "\tCD = " << C.getDistance( D ) << "\n";
    output << "\tDA = " << D.getDistance( A ) << "\n";
    output << "Shape Properties:\n";
    output << "\tbase1= " << base1 << "\n";
    output << "\tbase2 = " << base2 << "\n";
    output << "\theight = " << height << "\n";
    output << "\tPerimeter = " << getPerimeter() << "\n";
    output << "\tArea = " << getArea() << "\n\n";
}

// Friend function behaves like Trapezoid's print method.
// Overloads the ostream operator.
// Friend is NOT a member of this class, but has access to its members.
ostream & operator << ( ostream & output, Trapezoid & trap )
{
    trap.print( output );
    return output;
}

//******************************************************************************
// End of File
//******************************************************************************
