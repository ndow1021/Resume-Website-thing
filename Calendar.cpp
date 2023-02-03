#include <stdio.h>
#include <string.h>

int main(void) {
  int day, month, year, JDN, mDays;
  char DayofWk[] = "";

  day = 1;
  mDays = 0;

  printf("Enter month and year: ");
  scanf("%i %i", &month, &year);

  if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||month == 10 || month == 12)
    {
      mDays = 31;
    }
    else if(month == 4 || month == 6 || month == 9|| month == 11)
    {
      mDays = 30;
    }
    else if(month == 2)
    {
      if(year%4 ==0)
      {
        mDays = 29;
      }
      else
      {
        mDays = 28;
      }
    }
  
    printf("There are %i days in the month.\n", mDays);
  

  JDN = (1461 * (year + 4800 + (month - 14)/12))/4 +(367 * (month - 2 - 12 * ((month - 14)/12)))/12 - (3 * ((year + 4900 + (month - 14)/12)/100))/4 + day - 32075;

  if(((JDN+1) % 7) == 0)
  {
    strcat(DayofWk, "Sunday");
  }
  else if(((JDN+1) % 7) == 1)
  {
    strcat(DayofWk, "Monday");
  }
  else if(((JDN+1) % 7) == 2)
  {
    strcat(DayofWk, "Tuesday");
  }
  else if(((JDN + 1) % 7) == 3)
  {
    strcat(DayofWk, "Wendsday");
  }
  else if(((JDN + 1) % 7) == 4)
  {
    strcat(DayofWk, "Thursday");
  }
  else if(((JDN + 1) % 7) == 5)
  {
    strcat(DayofWk, "Friday");
  }
  else if(((JDN + 1) % 7) == 6)
  {
    strcat(DayofWk, "Saturday");
  }

  printf("The month starts on a %s.", DayofWk);

  return 0;
}