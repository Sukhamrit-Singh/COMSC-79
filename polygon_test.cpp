/*
This program uses a class named Regular Polygon to create
polygon objects. The class contains constructors, private 
and public variables, and methods which are used to display 
the traits of the object and calculate the perimeter and area 
of the object. In the main function, three object, one default 
and two with custom values, are created. Then the traits, perimeter,
and area for each object is displayed to the user.
Sukhamrit Singh, July 21, 2020
*/

#include <iostream>
#include <cmath> // to use max, tan, and abs functions and PI value

// Creating a class that will be used to create objects of
// type RegularPolygon
class RegularPolygon {

    // defining private variables that will hold the values
    // of the number of sides and side lengths. These values
    // will be passed to methods to calculate perimeter and area
    private:
        int nSides;
        double sideLength;
    
    // setting public constructors with default values or
    // passed in values from parameters. Additionally, creating
    // public methods and getters and setters
    public:

    // default constructor that will set the values of
    // nSides and sideLength to the default values if
    // no parameters are passed
        RegularPolygon() {
            nSides = 3;
            sideLength = 1.0;
        }

        // Constructor that will set the values of nSides
        // and sideLength based on the passed parameters. These
        // values will be set using the getter and setter methods
        RegularPolygon(int sides, double length) {
            setNSides(sides);
            setSideLength(length);
        }

        // setter method for nSides. If the passed value is
        // less than 3, the value of nSides will be set to 3
        void setNSides(int sides) {

            nSides = std::max(3, sides);
        }
        
        // getter method for nSides
        int getNSides() {

            return nSides;
        }

        // setter method for sideLength. If passed value is
        // less than 0, the value of sideLength will be abs of that value
        void setSideLength(int length) {

            if (length < 0) {
                sideLength = abs(length);
            } else {
                sideLength = length;
            }
        }
     
        // getter method for sideLength
        int getSideLength() {

            return sideLength;
        }

        // Display method which will take the values of nSides
        // and sideLength and will print them to the user
        void display() {
            printf("Number of sides: %i    Side length: %.2f", 
                nSides, sideLength);
        }

        // Method that will calculate the perimeter of the polygon
        // with the values of nSides and sideLength
        double getPerimeter() {

            // calculating the perimeter
            double perimeter = nSides * sideLength;

            // returning the value of perimeter
            return perimeter;
        }

        // Method that will calculate the area of the polygon
        // with the values of nSides and sideLength
        double getArea() {

            // calculating the area using some functions from the
            // cmath library
            double area = (nSides * pow(sideLength, 2)) /
                (4 * tan(M_PI / nSides));

            // returning the value of area
            return area;
        }
};

// main function
int main (void) {

    // creating an object of type RegularPolygon
    // this is a default polygon since there are no parameters
    RegularPolygon polyA;
    
    // calling the getPerimeter and getArea functions of the 
    // polygon and printing all the information of the polygon
    // with the display method and print statements
    double perimeter1 = polyA.getPerimeter();
    double area1 = polyA.getArea();
    printf("\nNormal Polygon\n");
    polyA.display();
    printf("\nPerimeter: %.2f\nArea: %.2f\n\n", perimeter1,
        area1);

    // creating another object of type RegularPolygon
    // this is not a default polygon since there are parameters
    // for specified values of nSides and sideLengths
    RegularPolygon polyB(6, 4.0);
    
    // calling the getPerimeter and getArea functions of the 
    // polygon and printing all the information of the polygon
    // with the display method and print statements
    double perimeter2 = polyB.getPerimeter();
    double area2 = polyB.getArea();
    printf("Polygon 2\n");
    polyB.display();
    printf("\nPerimeter: %.2f\nArea: %.2f\n\n", perimeter2,
        area2);

    // creating another object of type RegularPolygon
    // this is not a default polygon since there are parameters
    // for specified values of nSides and sideLengths
    RegularPolygon polyC(4, 7.5);
    
    // calling the getPerimeter and getArea functions of the 
    // polygon and printing all the information of the polygon
    // with the display method and print statements
    double perimeter3 = polyC.getPerimeter();
    double area3 = polyC.getArea();
    printf("Polygon 3\n");
    polyC.display();
    printf("\nPerimeter: %.2f\nArea: %.2f\n\n", perimeter3,
        area3);
    
    // conclude program
    return 0;
}