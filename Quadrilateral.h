//******************************************************************************
//  Quadrilateral.h
//  Inheritance
//
//  Created by Karlina Beringer on July 8, 2014.
//
//  This header file contains the Quadrilateral class declaration.
//  Quadrilateral is the base class for an inheritance chain.
//  Quadrilateral includes Point through composition.
//******************************************************************************

#ifndef Quadrilateral_h
#define Quadrilateral_h
#include "Point.h"

//------------------------------------------------------------------------------
// Quadrilateral represents a four-sided polygon whose vertices can be
// circumscribed on a circle such that we get one area rather than two
// triangles touching each other at a singe point.
//------------------------------------------------------------------------------
class Quadrilateral
{
protected:
    
    // Points are accessible only by Quadrilateral and its descendents.
    Point A, B, C, D;
    
    // A brief description of the class.
    const string TYPE = "QUADRILATERAL";
    
    // Determines whether the quadrilateral is cyclic using
    // Ptolemy's Theorem:
    //    If AB × CD + BC × DA = AC × BD,
    //    where AB, CD, BC, and DA are side lengths,
    //    Then the quadrilateral ABCD is cyclic.
    bool isCyclicQuadrilateral();
    
public:
    // Default constructor initializes all Points to default values.
    Quadrilateral();
    
    // Normal constructor assigns Points to the parameter values.
    Quadrilateral( Point A, Point B, Point C, Point D );
    
    // Copy constructor creates a clone of Quadrilateral object.
    Quadrilateral( Quadrilateral & quadrilateral );
    
    // Getter returns the perimeter of this Quadrilateral.
    // Perimeter = sum of all side lengths.
    double getPerimeter();
    
    // Getter returns the area of this Quadrilateral.
    double getArea();
    
    // Print the contents of this Quadrilateral.
    // If no ostream parameter is supplied, default will be cout.
    void print( ostream & output = cout );
    
    // Friend function behaves like Quadrilateral's print method.
    // Overloads the ostream operator.
    // Friend is NOT a member of this class, but has access to its members.
    friend ostream & operator << ( ostream & output, Quadrilateral & quad );
};

#endif

//******************************************************************************
// End of File
//******************************************************************************
