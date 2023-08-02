#include<stdio.h>
#include<stdlib.h>

#define N 500
#define SCALING_FACTOR 1000
#define SHIFTING_VALUE 1000

int base(int);

main()
{
	int rn[N],i,j;
	int two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0,ten=0;
	printf("\n\t%d random numbers ->\n\n\t\t",N);
	for(i=0;i<N;i++)
	{
		rn[i]=rand()%SCALING_FACTOR + SHIFTING_VALUE;
		printf("%d ",rn[i]);
	}
	printf("\n\n\tFrequency of Integers belonging to each base ->\n");
	for(i=0;i<N;i++)
	{
		if(base(rn[i])==0 || rn[i]==1)
		two++;
	
	 	if(base(rn[i])==2)
		three++;
		
		if(base(rn[i])==3)
		four++;
		
		if(base(rn[i])==4)
		five++;
		
		if(base(rn[i])==5)
		six++;
		
		if(base(rn[i])==6)
		seven++;
		
		if(base(rn[i])==7)
		eight++;
		
		if(base(rn[i])==8)
		nine++;
		
		if(base(rn[i])==9)
		ten++;
	}
	
	int b[9]={two,three,four,five,six,seven,eight,nine,ten};
	int s;
	for(i=0;i<9;i++)
	{
		printf("\n\t\tBase %d -> %d",i+2,b[i]);
	}
	
	int max=0;
	for(i=0;i<9;i++)
	{
	    if(max<b[i])
	    max=b[i];
	}
	printf("\n\n\tthe Frequency Distribution over different bases on x-axis -->\n");
	while(max)
	{
		printf("\t\t");
		for(i=0;i<9;i++)
		{
			if(b[i]>=max)
			printf("* ");
			else
			printf("  ");
		}
		printf("\n");
		max--;
	}
	printf("\t\t");
	for(i=2;i<=10;i++)
	printf("%d ",i);
	
	printf("\n\n\t\t\tBASE");
		
	return 0;
}

int base(int n)
{
	int i,r,b=0;
	while(n)
	{
		r=n%10;
		if(b<r)
			b=r;
		n=n/10;
	}
	return b;
}
