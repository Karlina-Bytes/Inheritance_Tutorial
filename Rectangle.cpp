//******************************************************************************
//  Rectangle.cpp
//  Inheritance
//
//  Created by Karlina Beringer on July 9, 2014.
//
//  This source file contains the Rectangle class definition.
//  Rectangle is derived from the Quadrilateral class.
//******************************************************************************

#include "Rectangle.h"

// Helper method forces sides to form 90-degree angles.
void Rectangle::setAttributes()
{
    double AB = A.getDistance( B );
    double BC = B.getDistance( C );
    double CD = C.getDistance( D );
    double DA = D.getDistance( A );
    
    // Check if sides AB and CD are the same length.
    // Check if sides BC and AD are the same length.
    bool lengthTest = (AB == CD && BC == DA);
    
    // Check if sides AB and CD are perpendicular.
    // Check if sides BC and AD are perpendicular.
    double slope_AB = A.getSlope( B );
    double slope_CD = C.getSlope( D );
    double slope_BC = B.getSlope( C );
    double slope_AD = A.getSlope( D );
    bool slopeTest = (slope_AB == slope_CD && slope_BC == slope_AD);
    
    // If conditions are not met, set values to default.
    if (!lengthTest || !slopeTest)
    {
        A = Point( 0, 0 );
        B = Point( 0, 5 );
        C = Point( 6, 5 );
        D = Point( 6, 0 );
    }
    
    // Set Rectangle-specific attributes.
    width = A.getDistance( B );
    length = A.getDistance( D );
}

// Default constructor calls Quadrilateral's default constructor.
Rectangle::Rectangle(): Quadrilateral()
{
    setAttributes();
}

// Normal constructor calls Quadrilateral's normal constructor.
Rectangle::Rectangle( Point A, Point B, Point C, Point D ):
Quadrilateral ( A, B, C, D )
{
    setAttributes();
}

// Copy constructor calls Quadrilateral's copy constructor.
Rectangle::Rectangle( Quadrilateral & quad ): Quadrilateral( quad )
{
    setAttributes();
}

// Getter returns the area of this Quadrilateral.
// Override the method to customize it for Rectangle.
// Area = Length * Width
double Rectangle::getArea()
{
    return length * width;
}

// Getter returns the perimeter of this Quadrilateral.
// Override the method to customize it for Rectangle.
// Perimeter = (Length + Width) * 2
double Rectangle::getPerimeter()
{
    return (length + width) * 2;
}

// Print the contents of this Quadrilateral.
// Override the method to customize it for Rectangle.
void Rectangle::print( ostream & output )
{
    output << "------------------------\n";
    output << TYPE << "\n";
    output << "------------------------\n";
    output  << "Points:\n";
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
    output << "\twidth = " << width << "\n";
    output << "\tlength = " << length << "\n";
    output << "\tPerimeter = " << getPerimeter() << "\n";
    output << "\tArea = " << getArea() << "\n\n";
}

// Friend function behaves like Rectangle's print method.
// Overloads the ostream operator.
// Friend is NOT a member of this class, but has access to its members.
ostream & operator << ( ostream & output, Rectangle & rect )
{
    rect.print( output );
    return output;
}

//******************************************************************************
// End of File
//******************************************************************************
