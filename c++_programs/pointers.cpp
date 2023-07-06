#include <iostream>

void swap( int *a, int *b );
void print( int *ptr1, int *ptr2 );

int main()
{
   int num1 = 5, num2 = 10;
   int *ptr1 = &num1, *ptr2 = &num2;

   std::cout << "Before swap:\n";
   print( ptr1, ptr2 );
   swap( ptr1, ptr2 );

   std::cout << "After swap:\n";
   print( ptr1, ptr2 );

   return 0;
}

void swap( int *a, int *b )
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void print( int *ptr1, int *ptr2 )
{
   std::cout << "num1 = " << *ptr1 << ' '
             << "num2 = " << *ptr2 << '\n';
}
