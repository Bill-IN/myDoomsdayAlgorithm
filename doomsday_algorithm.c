/*Doomsday algorithm:Calculates day of the week for any given day in the Greogorian calendar.*/

/*Sunday"Noneday"=0 			Doomsdates:All of the following dates fall on the doomsday for the year
  Monday"Oneday"=1				January 3/4(common/leap year)		July 11			December 12
  Tuesday"Twosday"=2			February 28/29(common/leap year)	August 8		March 0(last day of febuary)
  Wednesday"Treblesday"=3		April 4								September 5
  Thursday"Foursday"=4			May 9								October 10
  Friday"Fiveday"=5				June 6								November 7
  Saturday"Six-a-day"=6*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{	
	int congruent[7]={7,8,9,10,11,12,13};//Negative modulo doesn't work properly
	const char *DOTW[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};//two-dimensional aray
	int doomsdates[12]={3,28,0,4,9,6,11,8,5,10,7,12};//Array of doomsdates.Just the days.
	int day,month,year,anchor,doomsday,is_a_leap_year,dayoftheweek;
	int y,c,a,b,e,difference,tmp_1,i;
	double tmp_2;
	
	//Getting input from user
	printf("Enter the date in the format dd/mm/yyyy: ");
	scanf("%d/%d/%d",&day,&month,&year);

	//Calculating anchor day for the century
	tmp_2=year/100;
	c=floor(tmp_2);
	anchor=(5*((c%4)%7)+2)%7; //mod 7 to keep the days in modulo 7
	printf("\n\nThe anchor day for the century is %s\n\n",DOTW[anchor]);

	//Calculating the doomsday for the year;using the anchor day
	y=year%100;/*Taking last two digits of year*/
	tmp_2=y/12;
	a=floor(tmp_2);
	b=y%12;
	tmp_2=b/4;
	e=floor(tmp_2);
	doomsday=((a+b+e)%7+anchor)%7;
	printf("The doomsday for the year is %s\n\n",DOTW[doomsday]);

	/*Every year that is exactly divisible by four is a leap year,
	 except for years that are exactly divisible by 100,
	 but these centurial years are leap years if they are exactly divisible by 400.
	 For example, the years 1700, 1800, and 1900 were not leap years,
	 but the years 1600 and 2000 were.*/
	if(((year%100==0)&&(year%400==0)) || ((year%4==0)&&(year%100!=0)))
	{
		is_a_leap_year=1;
		doomsdates[0]=4;
		doomsdates[1]=29;
	}
	
	else
	{
		is_a_leap_year=0;
	}

	//Calculating day of the week
	if(day>=doomsdates[month-1])
	{
		tmp_1=day-doomsdates[month-1];//Counting forward
		difference=abs(tmp_1);
		dayoftheweek=(doomsday+(difference)%7)%7;
		printf("The day of the week is:%s",DOTW[dayoftheweek]);
	}
	
	else if(day<doomsdates[month-1])
	{
		tmp_1=day-doomsdates[month-1];//Counting back
		difference=abs(tmp_1);
		
		if(doomsday<difference)//Damn negative modulo
		{
			for(i=0;i<7;i++)
			{
				if(doomsday==i)
				{
					doomsday=congruent[i];
				}
			}
		}
		
		dayoftheweek=(doomsday-(difference)%7)%7;//Problem here,negative modulo if difference>doomsday
		printf("The day of the week is:%s",DOTW[dayoftheweek]);
	}
		
	return 0;
}
