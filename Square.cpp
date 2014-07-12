//******************************************************************************
//  Square.cpp
//  Inheritance
//
//  Created by Karlina Beringer on July 10, 2014.
//
//  This source file contains the Square class definition.
//  Square is derived from the Rectangle class.
//******************************************************************************

#include "Square.h"

// Helper method forces length and width to be the same length.
void Square::setAttributes()
{
    // Call the setAttributes method from the parent class.
    Rectangle::setAttributes();
    
    //setAttributes();
    if (length != width)
    {
        A = Point( 0, 0 );
        B = Point( 0, 5 );
        C = Point( 5, 5 );
        D = Point( 5, 0 );
    }
    width = 5;
    length = 5;
}

// Default constructor calls Rectangle's default constructor.
Square::Square(): Rectangle()
{
    setAttributes();
}

// Normal constructor calls Rectangle's normal constructor.
Square::Square( Point A, Point B, Point C, Point D ):
Rectangle( A, B, C, D )
{
    setAttributes();
}

// Copy constructor calls Rectangle's copy constructor.
Square::Square( Quadrilateral & quad ): Rectangle( quad )
{
    setAttributes();
}

// Getter returns the perimeter of this Rectangle.
// Override the method to customize it for Square.
// Perimeter =  Length * 4
double Square::getPerimeter()
{
    return length * 4;
}

// Getter returns the area of this Rectangle.
// Override the method to customize it for Square.
// Area = Length * Length
double Square::getArea()
{
    return length * length;
}

// Print the contents of this Rectangle.
// Override the method to customize it for Square.
// If no ostream parameter is supplied, default will be cout.
void Square::print( ostream & output )
{
    cout << "--------------------------------\n";
    output << TYPE << "\n";
    cout << "--------------------------------\n";
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
    output << "\tlength = " << length << "\n";
    output << "\tPerimeter = " << getPerimeter() << "\n";
    output << "\tArea = " << getArea() << "\n\n";
}

// Friend function behaves like Square's print method.
// Overloads the ostream operator.
// Friend is NOT a member of this class, but has access to its members.
ostream & operator << ( ostream & output, Square & sqr )
{
    sqr.print( output );
    return output;
}

//******************************************************************************
// End of File
//******************************************************************************
