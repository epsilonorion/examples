#include "Shape.h"

/// Shape class constructor
Shape::Shape(int newX, int newY, std::string newName)
{
  moveTo(newX, newY);
  setName(newName);
}

// accessors for x & y
int Shape::getX()
{
  return m_x;
}

int Shape::getY()
{
  return m_y;
}

std::string Shape::getName()
{
  return m_name;
}

void Shape::setX(int newX)
{
  m_x = newX;
}

void Shape::setY(int newY)
{
  m_y = newY;
}

void Shape::setName(std::string newName)
{
  m_name = newName;
}

// move the shape position
void Shape::moveTo(int newx, int newy)
{
  setX(newx);
  setY(newy);
}

void Shape::rMoveTo(int deltaX, int deltaY)
{
  moveTo(getX() + deltaX, getY() + deltaY);
}

// abstract methods
void Shape::draw()
{

}
