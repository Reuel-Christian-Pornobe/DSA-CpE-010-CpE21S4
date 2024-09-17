#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Triangle {
private:
    double angle1, angle2, angle3;
    double side1, side2, side3;
    
public:
    Triangle(double angle1, double angle2, double angle3, double side1, double side2, double side3);
    void updateAngles(double angle1, double angle2, double angle3);
    void updateSides(double side1, double side2, double side3);
    bool isValidTriangle();
    double calculateArea();
    double calculatePerimeter();
    string determineTriangleType();
};

Triangle::Triangle(double angle1, double angle2, double angle3, double side1, double side2, double side3)
    : angle1(angle1), angle2(angle2), angle3(angle3), side1(side1), side2(side2), side3(side3) {}

void Triangle::updateAngles(double angle1, double angle2, double angle3) {
    this->angle1 = angle1;
    this->angle2 = angle2;
    this->angle3 = angle3;
}

void Triangle::updateSides(double side1, double side2, double side3) {
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

bool Triangle::isValidTriangle() {
    // Check if the angles add up to 180 and if sides are positive
    return (angle1 + angle2 + angle3 == 180) && (side1 > 0 && side2 > 0 && side3 > 0);
}

double Triangle::calculateArea() {
    // Heron's formula to calculate the area of the triangle
    double s = calculatePerimeter() / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double Triangle::calculatePerimeter() {
    return side1 + side2 + side3;
}

string Triangle::determineTriangleType() {
    if (!isValidTriangle()) return "Invalid"; // In case angles don't add up to 180 or sides are not valid

    if (angle1 < 90 && angle2 < 90 && angle3 < 90) return "Acute-angled";
    if (angle1 == 90 || angle2 == 90 || angle3 == 90) return "Right-angled";
    return "Obtuse-angled";
}

int main() {
    double angle1, angle2, angle3;
    double side1, side2, side3;

    // Get user input for the angles
    cout << "Enter the three angles of the triangle (in degrees):\n";
    cin >> angle1 >> angle2 >> angle3;

    // Get user input for the side lengths
    cout << "Enter the three sides of the triangle:\n";
    cin >> side1 >> side2 >> side3;

    // Create a Triangle object with the user input
    Triangle userTriangle(angle1, angle2, angle3, side1, side2, side3);

    if(userTriangle.isValidTriangle()) {
        cout << "The shape is a valid triangle.\n";
        cout << "Area: " << userTriangle.calculateArea() << "\n";
        cout << "Perimeter: " << userTriangle.calculatePerimeter() << "\n";
        cout << "Type: " << userTriangle.determineTriangleType() << "\n";
    } else {
        cout << "The shape is NOT a valid triangle.\n";
    }
    
    return 0;
}
