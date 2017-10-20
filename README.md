# myDoomsdayAlgorithm #
This is my C implementation of the doomsday algorithm created by mathematician John Conway.

- - - - 

## Background ##
I started my CS degree in September 2016 with no prior programming experience. So when I saw the programming module that I would be taking in my first semester, I wasn't sure what to expect but I had an open mind. The programmiing module was taught through the C programming language. Most of our assignments were focused on understanding key programming concepts, fundamentals of the C programming language and becoming familiar with the most commonly used functions and libraries in C. While the assignments focused very much on the basics; as I progressed through the module, I saw the potential for more interesting programs. So over the Christmas holidays that year, I decided to do a project in C. I only had basic C programming knowledge at the time so I didn't know how interesting the program would be, but I had something in mind.

Out of nowhere, I remembered people in some tv shows and movies that calculated the day of the week for a given date in a year. I had always wondered how they did this. It sparked my curiosity whenever I saw it happen. Then I put two things together and went in search for an answer. I searched on Google "How to calculate the day of the week for any date in the year". At first, I sifted through some cumbersome methods then I found the doomsday algorithm.It sounded interesting, even just the name of the algorithm. I knew that I had found something special. I read through a description of the algorithm on Wikipedia and read about John Conway for some background knowledge. I had found my project. 

- - - -

## Challenges ##
```C
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
```
The above code block exhibits the case where the day I am looking for is before the doomsday of a month. I have to count back from the doomsday of the month to the day I am looking for.

When the program was counting backwards to find dates that precede the doomsday in a month, I would end up with an incorrect result upon program execution. This was because the modulo operator in C doesn't produce the correct result when dealing with negative numbers. It doesn't operate like the modulo in Mathematics. The value in the difference variable would end up being greater than the value in doomsday depending on how far back the date was from the doomsday.

Here is an example of what happened;

Ex.

```C
//Suppose we are calculating the day of the week for 4/10/2017

doomsday = 2; //The doomsday for 2017 is Tuesday
day = 4;
month = 10;
year = 2017;

doomsdate[month - 1] = 10; // The 10/10 is the doomsday for October.10/10/17 is a Tuesday.

if(day < doomsdates[month - 1])
{
	tmp_1 = day - doomsdates[month - 1]; // 4 - 10 = -6
	difference = abs(tmp_1); // difference = 6
	dayoftheweek = (doomsday - (difference) % 7) % 7;
}

/* This is how the calculation was done.*/

/* (2 - (6) % 7) % 7
	 (2 - 6) % 7
	 -4 % 7
	 -4 //This is an incorrect result.The answer should be 3 to give Wednesday. */

```

To solve this problem, I exploited the congruence property of the modulo operation. I created an array of seven numbers which were congruent to the remainders on division by seven. e.g. (0 1 2 3 4 5 6) == (7 8 9 10 11 12 13). This allowed me to overcome the challenge and obtain the correct result.

However, I have since created a function in C which computes the modulo operation the correct way. This can be found in my correctModulo repository, along with an example application of the function usng the doomsday algorithm.

- - - - 

## Findings ##
- I was impressed by the algorithm and found it to be quite enlightening compared to other methods of calculating the day of the week.
For example, before I found this algorithm, I didn't know that there was a particular date in every month that falls on the same day of the week every year and each of these dates also fall on the same day of the week every year.This day of the week is called the doomsday. 

- I didn't know that the Gregorian calendar had such an interesting property. I now understood how each unique date in each month(date of doomsday for month) was used as a reference point to calculate the day of the week for other dates in the year.It was modular arithmetic and the doomsdays at work.

- The algorithm is also fairly easy to execute without a computer when you get the hang of it. John Conway is able to calculate the day of the week for any date in a matter of seconds. 

I enjoyed implementing this algorithm.It was a great learning experience. I hope you found this interesting and if you would like to read more about the algorihm, here is a link to the Wikipedia page.

[Doomsday algorithm](https://en.wikipedia.org/wiki/Doomsday_rule)
