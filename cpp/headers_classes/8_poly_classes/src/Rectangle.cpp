#include "Shape.h"
#include "Rectangle.h"
#include <iostream>

/// Rectangle Constructor
/// Uses an initialization list to call the base class constructor to quickly initializae
/// name, x, and y positions.
Rectangle::Rectangle(int newX, int newY, int newWidth, int newHeight, std::string newName):
  Shape(newX, newY, newName)
{
  setWidth(newWidth);
  setHeight(newHeight);
}

// accessors for width and height
int Rectangle::getWidth()
{
  return m_width;
}

int Rectangle::getHeight()
{
  return m_height;
}

void Rectangle::setWidth(int newWidth)
{
  m_width = newWidth;
}

void Rectangle::setHeight(int newHeight)
{
  m_height = newHeight;
}

// draw the rectangle
void Rectangle::draw()
{
  std::cout << "Drawing a Rectangle at:(" << getX() << "," << getY() <<
    "), width " << getWidth() << ", height " << getHeight() << std::endl;
}

double Rectangle::getArea()
{
  return (getWidth() * getHeight());
}

double Rectangle::getPerimeter()\
{
  return (2 * (getWidth() + getHeight()));
}
