#include <iomanip>
#include <iostream>

#include "epochconverter.h"

EpochConverter::EpochConverter()
   : seconds( 0 ), month_days{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, datetime{ 0 }
{

}

EpochConverter::EpochConverter( int secs ) 
   : seconds( secs ), month_days{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, datetime{ 0 }
{
   
}

EpochConverter::EpochConverter( std::string date_str )
   : seconds( 0 ), month_days{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, datetime{ 0 }
{

}

void EpochConverter::secs2date()
{
   int dayclock = seconds % DAY_SECS;
   int days_count = seconds / DAY_SECS + 1;
   int year_days = 365;
   datetime.year = YEAR_START;

   // calculate seconds
   datetime.seconds = dayclock % SECONDS_DIV;
   dayclock /= SECONDS_DIV; // minutes

   // calculate minutes
   datetime.minutes = dayclock % MINUTES_DIV;
   dayclock /= MINUTES_DIV; // hours

   // calculate hours
   datetime.hour = dayclock % HOURS_DIV;

   // calculate year
   while( days_count > year_days )
   {
      days_count -= year_days;
      datetime.year++;
      if( datetime.year % 4 == 0 || datetime.year % 400 == 0 )
      {
         month_days[February] = 29;
         year_days = 366;
      }
      else
      {
         month_days[February] = 28;
         year_days = 365;
      }
   }

   // calculate month and day
   for( int i = 1; i < MONTH_COUNT; i++ )
   {
      if( days_count > month_days[i] )
         days_count -= month_days[i];
      else
      {
         datetime.month = i;
         datetime.day = days_count;
         break;
      }
   }

}

void EpochConverter::print_datetime() const
{
   std::cout << "Date: "
             << std::setw(2) << std::setfill('0') << datetime.day << '/'
             << std::setw(2) << std::setfill('0') << datetime.month << '/'
             << std::setw(4) << std::setfill('0') << datetime.year << ' '
             << std::setw(2) << std::setfill('0') << datetime.hour << ':'
             << std::setw(2) << std::setfill('0') << datetime.minutes << ':'
             << std::setw(2) << std::setfill('0') << datetime.seconds << std::endl;
}
