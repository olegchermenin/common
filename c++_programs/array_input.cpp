#include <iostream>

const int ARRAY_SIZE = 100;

int main()
{
   int array[ARRAY_SIZE] = {0};
   int n = 0;
   int temp = 0;

   std::cout << "Enter array elements (max count is " << ARRAY_SIZE
             << "; Ctrl+D/Ctrl+Z to end input):\n\n";

   // array input
   for( n = 0; n < ARRAY_SIZE; n++ )
   {
      std::cout << "array[" << n << "] = ";
      std::cin >> temp;
      if( std::cin.eof() )
      {
         std::cout << "not saved\n\n";
         break;
      }
      
      array[n] = temp;
   }
   std::cout << "You entered " << n << " elements\n";

   // array output in reverse order
   std::cout << "Array elements in reverse order:\n";
   for( int i = n - 1; i >= 0; i-- )
   {
      std::cout << "array[" << i << "] = ";
      std::cout << array[i] << '\n';
   }

   return 0;
}
