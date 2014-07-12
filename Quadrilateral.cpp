//*****************************************************************
//  Quadrilateral.cpp
//  Inheritance
//
//  Created by Karlina Beringer on July 8, 2014.
//
//  This source file contains the Quadrilateral class definition.
//  Quadrilateral is the base class for an inheritance chain.
//  Quadrilateral includes Point through composition.
//*****************************************************************

#include "Quadrilateral.h"

// Default constructor initializes all Points to default values.
Quadrilateral::Quadrilateral()
{
    A = Point( 0, 0 );
    B = Point( 1, 1 );
    C = Point( 2, 1 );
    D = Point( 3, -1 );
}

// Normal constructor assigns Points to the parameter values.
Quadrilateral::Quadrilateral( Point A, Point B, Point C, Point D )
{
    this -> A = Point( A );
    this -> B = Point( B );
    this -> C = Point( C );
    this -> D = Point( D );
}

// Copy constructor creates a clone of Quadrilateral object.
Quadrilateral::Quadrilateral( Quadrilateral & quadrilateral )
{
    A = quadrilateral.A;
    B = quadrilateral.B;
    C = quadrilateral.C;
    D = quadrilateral.D;
}

// Getter returns the perimeter of this Quadrilateral.
// Perimeter = sum of all side lengths.
double Quadrilateral::getPerimeter()
{
    return ( A.getDistance( B ) + B.getDistance( C ) +
             C.getDistance( D ) + D.getDistance( A ) );
}

// Getter returns the area of this Quadrilateral.
// 1. Divide the quadrilateral into two triangles.
// 2. Use Heron's Formula to compute the area of
//    each triangle.
// 3. Return the sum of the two triangle areas to get
//    the area of the quadrilateral.
// --------------------------------------------------------
// Heron's Formula:
//    Let A, B, and C be the side lengths of a triangle.
//    Let S = ( A + B + C ) / 2
//    Then we can compute the area of the triangle:
//    Area = sqrt[ S*( S - A )*( S - B )*( S - C ) ]
// --------------------------------------------------------
double Quadrilateral::getArea()
{
    // First Triangle
    double AB = A.getDistance( B );
    double BC = B.getDistance( C );
    double CA = C.getDistance( A );
    
    // Second Triangle
    double AC = A.getDistance( C );
    double CD = C.getDistance( D );
    double DA = D.getDistance( A );
    
    // Compute half the perimeters.
    double S1 = ( AB + BC + CA ) / 2;
    double S2 = ( AC + CD + DA ) / 2;
    
    // Compute the areas using Heron's formula.
    double A1 = sqrt( S1*( S1-AB )*( S1-BC )*( S1-CA ));
    double A2 = sqrt( S2*( S2-AC )*( S2-CD )*( S2-DA ));
    
    // Return the sum of the two triangles.
    return A1 + A2;
}

// Print the contents of this Quadrilateral.
// If no ostream parameter is supplied, default will be cout.
void Quadrilateral::print( ostream & output )
{
    cout << "--------------\n";
    output << TYPE << "\n";
    cout << "--------------\n";
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
    output << "\tPerimeter = " << getPerimeter() << "\n";
    output << "\tArea = " << getArea() << "\n\n";
}

// Friend function behaves like Quadrilateral's print method.
// Overloads the ostream operator.
// Friend is NOT a member of this class, but has access to its members.
ostream & operator << ( ostream & output, Quadrilateral & quad )
{
    quad.print( output );
    return output;
}

//*****************************************************************
// End of File
//*****************************************************************
