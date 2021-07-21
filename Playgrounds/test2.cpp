#include <iostream>
#include <cmath>

class RegularPolygon {

    private:
        int nSides;
        double sideLength;
    
    public:

        RegularPolygon(){
            nSides = 3;
            sideLength = 1.0;
        }

        RegularPolygon(int sides, double length) {
            setNSides(sides);
            setSideLength(length);
        }

        void setNSides(int sides) {

            nSides = std::max(3, sides);
        }
        
        int getNSides() {

            return nSides;
        }

        void setSideLength(int length) {

            if (sideLength < 0) {
                sideLength = abs(length);
            }

            sideLength = length;
        }
        
        int getSideLength() {

            return sideLength;
        }

        void display() {
            printf("Number of sides: %i    Side length: %.2f", 
                nSides, sideLength);
        }

        double getPerimeter() {

            double perimeter = nSides * sideLength;

            return perimeter;
        }

        double getArea() {

            double area = (nSides * pow(sideLength, 2)) /
                (4 * tan(M_PI / nSides));

            return area;
        }
};

class Triangle {
   private:
      double side1;
      double side2;
      double side3;
   public:
      // methods and constructors go here..
      double getPerimeter();

      Triangle(){
            side1 = 3;
            side2 = 1.0;
            side3 = 9;
        }
};

double Triangle :: getPerimeter() {
    double perimeter = side1 + side2 + side3;
    return perimeter;
}

int main (void) {

    // RegularPolygon polyA;
    
    // double perimeter1 = polyA.getPerimeter();
    // double area1 = polyA.getArea();
    // printf("Normal Polygon\n");
    // polyA.display();
    // printf("\nPerimeter: %.2f\nArea: %.2f\n\n", perimeter1,
    //     area1);

    // RegularPolygon polyB(6, 4.0);
    
    // double perimeter2 = polyB.getPerimeter();
    // double area2 = polyB.getArea();
    // printf("Polygon 2\n");
    // polyB.display();
    // printf("\nPerimeter: %.2f\nArea: %.2f\n\n", perimeter2,
    //     area2);

    // RegularPolygon polyC(4, 7.5);
    
    // double perimeter3 = polyC.getPerimeter();
    // double area3 = polyC.getArea();
    // printf("Polygon 3\n");
    // polyC.display();
    // printf("\nPerimeter: %.2f\nArea: %.2f\n\n", perimeter3,
    //     area3);
    
    Triangle tri;
    double p = tri.getPerimeter();
    printf("%f\n", p);

    
    return 0;
}