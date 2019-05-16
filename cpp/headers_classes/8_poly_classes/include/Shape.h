/**
 * @author Joshua Weaver
 * @date 6/22/17
 *
 * @brief Definition of shape class that will be used for all shapes.
 *
 * Define the base class for shapes that will be used in all derived shape
 * classes. Also defines basic variables and functions needed for each shape
 * while specifying functions that must be written per shape.
 *
 * This files also are used to help demonstrate headers and c files,
 * inheritance, and polymorphism.
 */

#ifndef SHAPECLASS_H
#define SHAPECLASS_H

#include <string>

/**
 * @class Shape Shape.h
 *
 * @brief Primary and base class for all shapes.
 *
 * This class will serve as the base for all shapes. It should be inherited
 * by any shape to define basic variables and functionality. Some functions
 * will be defined as virtual functions to form a dynamic linkage to the
 * derived class. These functions should be redefined in the derived class
 * as they are particular to a certain shape.
 */
class Shape {

public:
  /** Shape class constructor
   *
   * Defines basic components of a shape. Specifically, places based values
   * into the member variables of the class.
   *
   * @param newX The initial x position of the shape
   * @param newY The initial y position of the shape
   * @param newName The initial name to provide for the shape
   */
  Shape(int newX, int newY, std::string newName);

  /** Shape class destructor
   *
   */
  ~Shape() {}

  /** Getter function for providing x position of shape
   *
   * Provides caller the internal private variable holding the position
   * of the shape.
   *
   * @return Provide the private variable x position of the shape
   */
  int getX();

  /** Getter function for providing y position of shape
   *
   * Provides caller the internal private variable holding the position
   * of the shape.
   *
   * @return Provide the private variable y position of the shape
   */
  int getY();

  /** Getter function for providing name of shape
   *
   * Provides caller the internal private variable holding the name of
   * the shape.
   *
   * @return Provide the private variable name of the shape
   */
  std::string getName();

  /** Setter function for defining the x position of the shape
   *
   * @param newX The new x position to be used for the shape
   */
  void setX(int newX);

  /** Setter function for defining the y position of the shape
   *
   * @param newY The new y position to be used for the shape
   */
  void setY(int newY);

  /** Setter function for defining the name to be used for the shape
   *
   * @param newName The new name that will be used for the shape
   */
  void setName(std::string newName);

  /** Define/Redefine the x and y position of the shape
   *
   * @param newX The new x position to be used for the shape
   * @param newY The new y position to be used for the shape
   */
  void moveTo(int newX, int newY);

  /** Offset the position of the shape provided the delta positions
   *
   * @param deltaX The amount of space to move the shape in x direction
   * @param deltaY The amount of space to move the shape in y direction
   */
  void rMoveTo(int deltaX, int deltaY);

  /** Initial definition of draw function
   *
   * This function is a virtual function demonstrating the use of
   * polymorphism. Developers may redefine this function in a derived
   * class to better draw that specific shape. There must be a base
   * definition for this function within the Shape.cpp file, but it
   * is not required to do anything special.
   */
  virtual void draw();

  /** Initial definition of getArea
   *
   * This function is a pure virtual function demonstrating the use of
   * polymorphism. Pure virtual functions must be redefined within the
   * derived class. There may be a defined body for this function in
   * Shape.cpp, but is not required.
   *
   * @return The calculated area of the shape per defined equation
   */
  virtual double getArea() = 0;

  /** Initial definition of getPerimeter
   *
   * This function is a pure virtual function demonstrating the use of
   * polymorphism. Pure virtual functions must be redefined within the
   * derived class. There may be a defined body for this function in
   * Shape.cpp, but is not required.
   *
   * @return The calculated perimeter of the shape per defined equation
   */
  virtual double getPerimeter() = 0;

private:
  std::string m_name;	  ///< Shape's name
  int m_x;              ///< Drawn x position of shape
  int m_y;              ///< Drawn y position of shape
};

#endif
