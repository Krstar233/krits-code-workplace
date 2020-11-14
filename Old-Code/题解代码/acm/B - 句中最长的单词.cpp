#include <stdio.h>
#include <string.h>
int main()
{
	char sentence[45];
	int i,start,end,max_lon;
	int mstart,mend;
	
	start = -1;
	end = 0;
	max_lon=0;
	gets (sentence);
	for (i=0;i<strlen(sentence);i++)
	{
		if (sentence[i]!=' ')	end = i;
		else start = i;
		if (max_lon < end - start)
		{
			max_lon = end - start;
			mstart = start;
			mend = end;
		}
	}
	for (i=mstart+1;i<=mend;i++)
	{
		printf ("%c",sentence[i]);
	}
}
