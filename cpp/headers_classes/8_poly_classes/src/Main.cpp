#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <unistd.h>

int main(int argc, char * argv[]) {
  /// set up array to the shapes
  Shape *scribble[2];
  scribble[0] = new Rectangle(10, 20, 5, 6, "Rect1");
  scribble[1] = new Circle(15, 25, 8, "Circ1");

  /// iterate through the array and handle shapes polymorphically
  for (int i = 0; i < 2; i++) {
    std::cout << "Shape: " << scribble[i]->getName() << std::endl;
    std::cout << "Area: " << scribble[i]->getArea() << std::endl;
    std::cout << "Perimeter: " << scribble[i]->getPerimeter() << std::endl;
    std::cout << "Drawing shape..." << std::endl;
    scribble[i]->draw();
    std::cout << "Moving and drawing shape..." << std::endl;
    scribble[i]->rMoveTo(100, 100);
    scribble[i]->draw();
    std::cout << std::endl;

    sleep(2);
  }

  /// call a rectangle specific function
  Rectangle *arec = new Rectangle(0, 0, 15, 15, "Rect2");
  std::cout << "Shape: " << arec->getName() << std::endl;
  std::cout << "Area: " << arec->getArea() << std::endl;
  std::cout << "Perimeter: " << arec->getPerimeter() << std::endl;

  arec->setWidth(30);

  std::cout << "Shape Modified: " << arec->getName() << std::endl;
  std::cout << "Area: " << arec->getArea() << std::endl;
  std::cout << "Perimeter: " << arec->getPerimeter() << std::endl;
  std::cout << "Drawing shape..." << std::endl;
  arec->draw();
}
