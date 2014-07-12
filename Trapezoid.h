//******************************************************************************
//  Trapezoid.h
//  Inheritance
//
//  Created by Karlina Beringer on July 10, 2014.
//
//  This header file contains the Trapezoid class declaration.
//  Trapezoid is derived from the Quadrilateral class.
//******************************************************************************

#ifndef Trapezoid_h
#define Trapezoid_h
#include "Quadrilateral.h"

//-----------------------------------------------------------------------------
// Trapezoid represents a quadrilateral with exactly least two parallel sides.
//-----------------------------------------------------------------------------
class Trapezoid: public Quadrilateral
{
// Trapezoid inherits the data members and methods of Quadrilateral.
private:
    
    // Base1 is the longest parallel edge.
    // Base2 is the shortest parellel edge.
    // Height is the distance between parallel edges.
    double base1, base2, height;
    
    // A brief description of the class.
    const string TYPE = "QUADRILATERAL/TRAPEZOID";
    
    // Helper method forces exactly two sides to be parallel.
    void setAttributes();
    
public:
    
    // Default constructor calls Quadrilateral's default constructor.
    Trapezoid();
    
    // Normal constructor calls Quadrilateral's normal constructor.
    Trapezoid( Point A, Point B, Point C, Point D );
    
    // Copy constructor calls Quadrilateral's copy constructor.
    Trapezoid( Quadrilateral & quad );
    
    // Getter returns the area of this Quadrilateral.
    // Override the method to customize it for Trapezoid.
    // Area = [(Base1 + Base2) * Height] / 2
    double getArea();
    
    // Print the contents of this Quadrilateral.
    // Override the method to customize it for Trapezoid.
    // If no ostream parameter is supplied, default will be cout.
    void print( ostream & output = cout );
    
    // Friend function behaves like Trapezoid's print method.
    // Overloads the ostream operator.
    // Friend is NOT a member of this class, but has access to its members.
    friend ostream & operator << ( ostream & output, Trapezoid & trap );
};

#endif

//******************************************************************************
// End of File
//******************************************************************************
