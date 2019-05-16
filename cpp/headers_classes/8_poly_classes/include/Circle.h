class Circle: public Shape {

public:
  Circle(int newX, int newY, int newRadius, std::string newName);
  int getRadius();
  void setRadius(int newRadius);
  void draw();
  double getArea();
  double getPerimeter();

private:
  int m_radius;
};
