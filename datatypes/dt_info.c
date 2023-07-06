#include <limits.h>
#include <stdio.h>
#include <string.h>

void print_dt_info( int argc, char *argv[] );
void print_all();
void print_char_info( int index );
void print_short_info( int index );
void print_int_info( int index );
void print_long_info( int index );

void print_help( const char *prog_name );

#define DT_MSG "\t%s is %lu bytes and in range "
#define CHAR_SHRT_INT_SPEC_RANGE       "[%d, %d]\n"
#define UNS_CHAR_SHRT_INT_SPEC_RANGE   "[%u, %u]\n"
#define LONG_SPEC_RANGE                "[%ld, %ld]\n"
#define UNS_LONG_SPEC_RANGE            "[%d, %lu]\n"

int main( int argc, char *argv[] )
{
   if( argc > 1)
   {
      if( !strcmp( argv[1], "help" ) )
      {
         print_help( argv[0] );
         return 0;
      }
      else 
         print_dt_info( argc, argv );
   }
   else
      print_dt_info( argc, NULL );

   return 0;
}

void print_dt_info( int argc, char **argv )
{
   printf( "Data types on this system:\n\n" );

   if( argc == 1)
   {
      print_all();
      return;
   }

   for( int i = 1; i < argc; i++ )
   {
      if( !strcmp( argv[i], "char" ) )
         print_char_info( i );
      else if( !strcmp( argv[i], "short" ) )
         print_short_info( i );
      else if( !strcmp( argv[i], "int" ) )
         print_int_info( i );
      else if( !strcmp( argv[i], "long" ) )
         print_long_info( i );
      else
         printf( "Incorrect data type!\n" );

      printf("\n");
   }
}

void print_all()
{
   print_char_info( 1 );
   printf("\n");

   print_short_info( 2 );
   printf("\n");

   print_int_info( 3 );
   printf("\n");

   print_long_info( 4 );
   printf("\n");
}

void print_help( const char *prog_name )
{
   printf( "Brief: dt_types print information about data types on your system (size and range).\n\n");
   printf( "Usage: %s [data type = char/short/int/long]\n", prog_name );
   printf( "Start without arguments print information about all data types.\n");
}

void print_char_info( int index )
{
   char *char_msg = "\tchar in this system is represented as an %s char\n";

   printf( "%d. char data type:\n", index );
   if( CHAR_MIN == SCHAR_MIN )
      printf( char_msg, "signed" );
   else
      printf( char_msg, "unsigned" );

   printf( DT_MSG CHAR_SHRT_INT_SPEC_RANGE, "signed char", sizeof( char ), SCHAR_MIN, SCHAR_MAX );
   printf( DT_MSG UNS_CHAR_SHRT_INT_SPEC_RANGE, "unsigned char", sizeof( char ), 0, UCHAR_MAX );
}

void print_short_info( int index )
{
   printf( "%d. short data type:\n", index );

   printf( DT_MSG CHAR_SHRT_INT_SPEC_RANGE, "short", sizeof( short ), SHRT_MIN, SHRT_MAX );
   printf( DT_MSG UNS_CHAR_SHRT_INT_SPEC_RANGE, "unsigned short", sizeof( short ), 0, USHRT_MAX );
}

void print_int_info( int index )
{
   printf( "%d. int data type:\n", index );

   printf( DT_MSG CHAR_SHRT_INT_SPEC_RANGE, "int", sizeof( int ), INT_MIN, INT_MAX );
   printf( DT_MSG UNS_CHAR_SHRT_INT_SPEC_RANGE, "unsigned int", sizeof( int ), 0, UINT_MAX );
}

void print_long_info( int index )
{
   printf( "%d. long data type:\n", index );

   printf( DT_MSG LONG_SPEC_RANGE, "long", sizeof( long ), LONG_MIN, LONG_MAX );
   printf( DT_MSG UNS_LONG_SPEC_RANGE, "unsigned long", sizeof( long ), 0, ULONG_MAX );
}