//******************************************************************************
//  Rectangle.h
//  Inheritance
//
//  Created by Karlina Beringer on July 9, 2014.
//
//  This header file contains the Rectangle class declaration.
//  Rectangle is derived from the Quadrilateral class.
//******************************************************************************

#ifndef Rectangle_h
#define Rectangle_h
#include "Quadrilateral.h"

//-------------------------------------------------------------------------
// Rectangle represents a quadrilateral whose sides form 90-degree angles.
//-------------------------------------------------------------------------
class Rectangle: public Quadrilateral
{
// Rectangle inherits the data members and methods of Quadrilateral.
protected:
    
    // width and length are adjacent sides that form a right angle.
    double width, length;
    
    // A brief description of the class.
    const string TYPE = "QUADRILATERAL/RECTANGLE";
    
    // Helper method forces sides to form 90-degree angles.
    void setAttributes();
    
public:
    // Default constructor calls Quadrilateral's default constructor.
    Rectangle();
    
    // Normal constructor calls Quadrilateral's normal constructor.
    Rectangle( Point A, Point B, Point C, Point D );
    
    // Copy constructor calls Quadrilateral's copy constructor.
    Rectangle( Quadrilateral & quad );
    
    // Getter returns the area of this Quadrilateral.
    // Override the method to customize it for Rectangle.
    // Area = Length * Width
    double getArea();
    
    // Getter returns the perimeter of this Quadrilateral.
    // Override the method to customize it for Rectangle.
    // Perimeter = (Length + Width) * 2
    double getPerimeter();
    
    // Print the contents of this Quadrilateral.
    // Override the method to customize it for Rectangle.
    // If no ostream parameter is supplied, default will be cout.
    void print( ostream & output = cout );
    
    // Friend function behaves like Rectangle's print method.
    // Overloads the ostream operator.
    // Friend is NOT a member of this class, but has access to its members.
    friend ostream & operator << ( ostream & output, Rectangle & rect );
};

#endif

//******************************************************************************
// End of File
//******************************************************************************
