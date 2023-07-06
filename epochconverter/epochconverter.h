#ifndef EPOCHCONVERTER_H
#define EPOCHCONVERTER_H

#include <string>

struct DateTime
{
   int year;
   int month;
   int day;
   int hour;
   int minutes;
   int seconds;
};

class EpochConverter
{
   private:
      enum Months
      {
         null,
         January,
         February,
         March,
         April,
         May,
         June,
         July,
         August,
         September,
         October,
         November,
         December
      };

      static const int YEAR_START = 1970;
      static const int MONTH_COUNT = 13;
      static const int YEAR_SECS = 31556926;
      static const int DAY_SECS = 86400;
      static const int HOURS_DIV = 3600;
      static const int MINUTES_DIV = 60;
      static const int SECONDS_DIV = 60;
      
      int month_days[MONTH_COUNT]; // first number is sign of a leap year
      int seconds;
      DateTime datetime;

   public:
      EpochConverter();
      EpochConverter( int secs );
      EpochConverter( std::string date_str );
      void secs2date();
      void print_datetime() const;
};

#endif // EPOCHCONVERTER_H
