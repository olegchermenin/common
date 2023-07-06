#include <iostream>

const float PI = 3.14;

class Shape
{
   public:
      virtual ~Shape() { };
      virtual float calc_area() = 0;
};

class Rect : public Shape
{
   private:
      float length;
      float width;

   public:
      Rect( float i_length, float i_width );
      ~Rect() { };
      float calc_area() override;
};

class Circle : public Shape
{
   private:
      float rad;

   public:
      Circle( float i_rad );
      ~Circle() { };
      float calc_area() override;
};

int main()
{
   Shape *ptrs[2];
   float rec_len = 0, rec_width = 0;
   float circ_rad = 0;

   std::cout << "Enter the length for the rectangle: ";
   std::cin >> rec_len;
   std::cout << "Enter the width for the rectangle: ";
   std::cin >> rec_width;

   std::cout << "Enter the radius of the circle: ";
   std::cin >> circ_rad;

   ptrs[0] = new Rect( rec_len, rec_width );
   ptrs[1] = new Circle( circ_rad );

   std::cout << "Area of a rectangle = " << ptrs[0]->calc_area() << '\n';
   std::cout << "Area of a circle = "    << ptrs[1]->calc_area() << '\n';

   for( int i = 0; i < 2; i++ )
      delete ptrs[i];

   return 0;
}

Rect::Rect( float i_length, float i_width ) :
   length( i_length ), width( i_width )
{

}

float Rect::calc_area()
{
   return length * width;
}

Circle::Circle( float i_rad ) : rad( i_rad )
{
   
}

float Circle::calc_area()
{
   return PI * rad * rad;
}
