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
