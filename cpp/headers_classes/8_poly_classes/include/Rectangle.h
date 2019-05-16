class Rectangle: public Shape {

public:
  Rectangle(int newX, int newY, int newWidth, int newHeight, std::string newName);
  int getWidth();
  int getHeight();
  void setWidth(int newWidth);
  void setHeight(int newHeight);
  void draw();
  double getArea();
  double getPerimeter();

private:
  int m_width;
  int m_height;
};
