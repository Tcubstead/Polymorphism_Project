//Thomas Cubsyead
//4/28/25
//Polymorphism_Project
//Master
//This program creates a circle, rectangle, and square and finds their features using inheritance prom the general BasicShape class

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// BasicShape Class
class BasicShape {
private:
    double area;
    string name;

public:
    virtual ~BasicShape() = default;

    double getArea() const { return area; }
    void setArea(double a) { area = a; }

    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    virtual void calcArea() = 0;
};

// Circle Class
class Circle : public BasicShape {
private:
    double xCenter, yCenter, radius;

public:
    Circle(double x, double y, double r, const string& n = "Circle")
        : xCenter(x), yCenter(y), radius(r) {
        setName(n);
        calcArea();
    }

    //calculates the area of a circle
    void calcArea() override {
        double a = M_PI * radius * radius;
        setArea(a);
    }

    double getXCenter() const { return xCenter; }
    double getYCenter() const { return yCenter; }
    double getRadius() const { return radius; }
};

// Rectangle Class
class Rectangle : public BasicShape {
private:
    double length, width;

public:
    Rectangle(double l, double w, const string& n = "Rectangle")
        : length(l), width(w) {
        setName(n);
        calcArea();
    }

    //calculates the area of a rectangle
    void calcArea() override {
        setArea(length * width);
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }
};

// Square Class
class Square : public Rectangle {
private:
    double side;

public:
    Square(double s, const string& n = "Square")
        : Rectangle(s, s, n), side(s) {
        setName(n);
    }

    double getSide() const { return side; }
};

// Main Program
int main() {
    vector<BasicShape*> shapes;

    // creates two rectangles
    shapes.push_back(new Rectangle(10, 5, "MyRectangle1"));
    shapes.push_back(new Rectangle(7, 3, "MyRectangle2"));

    // creates two circles
    shapes.push_back(new Circle(0, 0, 5, "MyCircle1"));
    shapes.push_back(new Circle(1, 1, 3, "MyCircle2"));

    // creates one square
    shapes.push_back(new Square(4, "MySquare"));

    // Print each shape's name and area
    for (const auto* shape : shapes) {
        cout << "Shape: " << shape->getName()
            << ", Area: " << shape->getArea() << endl;
    }

    // Cleanup
    for (auto* shape : shapes) {
        delete shape;
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
