#include<stdio.h>
#include<cs50.h>
#include<string.h>

bool checkSum(long userNumber, int length);
long number, tmpnumber;
int len;


int main(void)
{

    len=0;
    int TwoFirstDigits;

      len = 0;
      number = get_long("number\n");
      tmpnumber = number;

      while( number > 0)
      {
          len++;
          number = number/10;

          if ( 9 < number && number < 100)
          {
            TwoFirstDigits = number;
          }

      }

    if( len == 13 && checkSum(tmpnumber, len))
    {

      if( TwoFirstDigits/10 == 4)
      {
         printf("VISA\n");
         return 0;
      } else
      {
        printf("INVALID\n");
        return 0;
      }
    }

    if( len == 15 && checkSum(tmpnumber, len))
    {
      if( TwoFirstDigits == 34 || TwoFirstDigits == 37)
      {
         printf("AMEX\n");
         return 0;
      } else
      {
        printf("INVALID\n");
        return 0;
      }
    }


    if( len == 16 && checkSum(tmpnumber, len))
    {
      if( TwoFirstDigits/10 == 4 )
      {
         printf("VISA\n");
         return 0;
      }

      if( TwoFirstDigits == 54 || TwoFirstDigits == 51 || TwoFirstDigits == 52 || TwoFirstDigits == 53 || TwoFirstDigits == 55 )
      {
         printf("MASTERCARD\n");
         return 0;
      }
      else
      {
        printf("INVALID\n");
        return 0;
      }

    } else {
      printf("INVALID\n");
    }


}

bool checkSum(long userNumber, int length) {
  int checksum =0;

  while(userNumber > 0)
    {
      int scndToLastTimes2 = (((userNumber %100 - userNumber %10)/10)*2);
      checksum = checksum + userNumber %10;

      if(  9  <  scndToLastTimes2 )
      {
            checksum = checksum + scndToLastTimes2 %10 +  scndToLastTimes2/10;
      }

      else
      {
        checksum = checksum + scndToLastTimes2;
      }
      userNumber = userNumber/100;
    }

    if (checksum %10 == 0)

    {
        return true;
    }
return false;


}
