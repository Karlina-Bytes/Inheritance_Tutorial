//******************************************************************************
//  main.cpp
//  Inheritance
//
//  Created by Karlina Beringer on July 8, 2014.
//
//  This driver implements the Quadrilateral class and its
//  derived and classes, Rectangle, Trapezoid, and Square.
//  Quadrilateral includes Point through composition.
//******************************************************************************

#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Square.h"

int main()
{
    //**************************************************************************
    // Point Tests
    //**************************************************************************
    cout << "---------------------------\n";
    cout << "Point Tests...\n";
    cout << "---------------------------\n\n";
    
    // Create a default Point object.
    Point A;
    cout << "\tDefault Point, A = ";
    cout << A << "\n";
    
    // Create a custom Point object.
    Point B( 1, 1 );
    cout << "\tCustom Point, B = ";
    cout << B << "\n";
    
    // Create a copy of Point A and call it C.
    Point C( A );
    cout << "\tCopy of Point A, named C = ";
    cout << C << "\n";
    
    // Reset the values of Point C.
    C.setX( 2 );
    C.setY( 0 );
    cout << "\tReset C to ";
    cout << C << "\n";
    
    // Get the slope of the line between A and B.
    cout << "\tSlope AB = ";
    cout << A.getSlope( B ) << "\n";
    
    // Get the distance between A and B.
    cout << "\tDistance AB = ";
    cout << A.getDistance( B ) << "\n";
    
    // Get the slope of the line between A and C.
    cout << "\tSlope AC = ";
    cout << A.getSlope( C ) << "\n";
    
    // Get the distance between A and C.
    cout << "\tDistance AC = ";
    cout << A.getDistance( C ) << "\n\n";
    
    //**************************************************************************
    // Quadrilateral Tests
    //**************************************************************************
    cout << "---------------------------\n";
    cout << "Quadrilateral Tests...\n";
    cout << "---------------------------\n\n";
    
    // Create a default Quadrilateral object.
    Quadrilateral quad1;
    cout << "\tDefault Quadrilateral...\n";
    cout << quad1;
    
    // Create a copy Quadrilateral object.
    Quadrilateral quad2( quad1 );
    cout << "\tCopy Quadrilateral...\n";
    cout << quad2;
    
    // Create a custom Quadrilateral object.
    cout << "\tCustom Quadrilateral...\n";
    Point W( -1, -1 ), X( 0, 2 ), Y( 2, 2 ), Z( 4, 0 );
    Quadrilateral quad3( W, X, Y, Z );
    cout << quad3;
    
    //**************************************************************************
    // Trapezoid Tests
    //**************************************************************************
    cout << "---------------------------\n";
    cout << "Trapezoid Tests...\n";
    cout << "---------------------------\n\n";
    
    // Create a default Trapezoid object.
    Trapezoid trap1;
    cout << "\tDefault Trapezoid...\n";
    cout << trap1;
    
    // Create a copy Trapezoid object from Quadrilateral object.
    Trapezoid trap2( quad1 );
    cout << "\tCopy Trapezoid from Quadrilateral...\n";
    cout << trap2;
    
    // Create a copy Trapezoid object from Trapezoid object.
    Trapezoid trap3( trap1 );
    cout << "\tCopy Trapezoid from Trapezoid...\n";
    cout << trap3;
    
    // Create a custom Trapezoid object.
    cout << "\tCustom Trapezoid...\n";
    Trapezoid trap5( W, X, Y, Z );
    cout << trap5;
    
    //**************************************************************************
    // Rectangle Tests
    //**************************************************************************
    cout << "---------------------------\n";
    cout << "Rectangle Tests...\n";
    cout << "---------------------------\n\n";
    
    // Create a default Rectangle object.
    Rectangle rect1;
    cout << "\tDefault Rectangle...\n";
    cout << rect1;
    
    // Create a copy Rectangle object from Quadrilateral object.
    Rectangle rect2( quad1 );
    cout << "\tCopy Rectangle from Quadrilateral...\n";
    cout << rect2;
    
    // Create a copy Rectangle object from Rectangle object.
    Rectangle rect3( rect1 );
    cout << "\tCopy Rectangle from Rectangle...\n";
    cout << rect3;
    
    // Create a custom Rectangle object.
    cout << "\tCustom Rectangle...\n";
    Rectangle rect4( W, X, Y, Z );
    cout << rect4;
    
    //**************************************************************************
    // Square Tests
    //**************************************************************************
    cout << "---------------------------\n";
    cout << "Square Tests...\n";
    cout << "---------------------------\n\n";
    
    // Create a default Square object.
    Square sqr1;
    cout << "\tDefault Square...\n";
    cout << sqr1;
    
    // Create a copy Square object from Quadrilateral object.
    Square sqr2( quad1 );
    cout << "\tCopy Square from Quadrilateral...\n";
    cout << sqr2;
    
    // Create a copy Square object from Rectangle object.
    Square sqr3( rect1 );
    cout << "\tCopy Square from Rectangle...\n";
    cout << sqr3;
    
    // Create a copy Square object from Square object.
    Square sqr4( sqr1 );
    cout << "\tCopy Square from Square...\n";
    cout << sqr4;
    
    // Create a custom Square object.
    cout << "\tCustom Square...\n";
    Square sqr5( W, X, Y, Z );
    cout << sqr5;
    
    // Terminate program
    return 0;
}

//******************************************************************************
// End of File
//******************************************************************************

