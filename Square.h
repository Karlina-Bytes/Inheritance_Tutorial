//******************************************************************************
//  Square.h
//  Inheritance
//
//  Created by Karlina Beringer on July 10, 2014.
//
//  This header file contains the Square class declaration.
//  Square is derived from the Rectangle class.
//******************************************************************************

#ifndef Square_h
#define Square_h
#include "Rectangle.h"

//---------------------------------------------------------------------------
// Square represents a rectangle whose length and width are the same length.
//---------------------------------------------------------------------------
class Square: public Rectangle
{
    
// Square inherits the data members and methods of Quadrilateral.
private:
    
    // A brief description of the class.
    const string TYPE = "QUADRILATERAL/RECTANGLE/SQUARE";
    
    // Helper method forces length and width to be the same length.
    void setAttributes();

public:
    
    // Default constructor calls Rectangle's default constructor.
    Square();
    
    // Normal constructor calls Rectangle's normal constructor.
    Square( Point A, Point B, Point C, Point D );
    
    // Copy constructor calls Quadrilateral's copy constructor.
    Square( Quadrilateral & quad );
    
    // Getter returns the perimeter of this Rectangle.
    // Override the method to customize it for Square.
    // Perimeter =  Length * 4
    double getPerimeter();
    
    // Getter returns the area of this Rectangle.
    // Override the method to customize it for Square.
    // Area = Length * Length
    double getArea();
    
    // Print the contents of this Rectangle.
    // Override the method to customize it for Square.
    // If no ostream parameter is supplied, default will be cout.
    void print( ostream & output = cout );
    
    // Friend function behaves like Square's print method.
    // Overloads the ostream operator.
    // Friend is NOT a member of this class, but has access to its members.
    friend ostream & operator << ( ostream & output, Square & sqr );
};


#endif

//******************************************************************************
// End of File
//******************************************************************************
