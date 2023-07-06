#include <iostream>

#include "epochconverter.h"

int main( int argc, char *argv[] )
{
   EpochConverter *converter;
   int secs = 0;

   if( argc < 2 )
   {
      std::cout << "Usage: " << argv[0] << " <seconds>\n";
      return 0;
   }
   secs = atoi( argv[1] );

   converter = new EpochConverter( secs );

   converter->secs2date();
   converter->print_datetime();

   delete converter;
   return 0;
}
