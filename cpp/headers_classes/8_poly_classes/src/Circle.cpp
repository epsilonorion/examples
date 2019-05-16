#include "Shape.h"
#include "Circle.h"
#include <iostream>

/// Circle Constructor
/// Uses an initialization list to call the base class constructor to quickly initializae
/// name, x, and y positions.
Circle::Circle(int newX, int newY, int newRadius, std::string newName): Shape(newX, newY, newName)
{
  setRadius(newRadius);
}

// accessors for the radius
int Circle::getRadius()
{
  return m_radius;
}

void Circle::setRadius(int newRadius)
{
  m_radius = newRadius;
}

// draw the circle
void Circle::draw()
{
  std::cout << "Drawing a Circle at:(" << getX() << "," << getY() <<
    "), radius " << getRadius() << std::endl;
}

double Circle::getArea()
{
  return (3.14 * getRadius() * getRadius());
}

double Circle::getPerimeter()
{
  return (2 * 3.14 * getRadius());
}
