// some necessary header files 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// some macros that help when we make any change
#define N 500
/*This line defines a constant N with the value 500,
 representing the number of random numbers to be generated.*/

#define SCALING_FACTOR 100
#define SHIFTING_VALUE 1000

int base(int); // Function prototype

 // Main function
main()
{
	int rn[N],i; // Declare and initialize variables
	
//Declares an array rn to store N random numbers and an integer variable i used in the loops.
	int one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0,ten=0;
	
	srand((unsigned int)time(NULL)); // Seed the random number generator
	// in simple words with this help we have always generate new random numbers
	
	/*Seeds the random number generator using the current time as a seed,
	 ensuring different sequences of random numbers on each program run. */

	printf("\n\trandom numbers ->\n\n");
	for(i=0;i<N;i++)
	{
		rn[i]=rand()% SCALING_FACTOR + SHIFTING_VALUE;
		printf("%d ",rn[i]);
	}
	
	// Count occurrences of each base in the generated random numbers
	for(i=0;i<N;i++)
	{
		if(base(rn[i])==0 || base(rn[i])==1)
		two++;
	
	 	else if(base(rn[i])==2)
		three++;
		
		else if(base(rn[i])==3)
		four++;
		
		else if(base(rn[i])==4)
		five++;
		
		else if(base(rn[i])==5)
		six++;
		
		else if(base(rn[i])==6)
		seven++;
		
		else if(base(rn[i])==7)
		eight++;
		
		else if(base(rn[i])==8)
		nine++;
		
		else if(base(rn[i])==9)
		ten++;
	}
	
	// Store the frequency distribution of each base in an array
	int b[9]={two,three,four,five,six,seven,eight,nine,ten};
	
	// Print the frequency distribution for each base
	printf("\n\n\trandom numbers base ->\n");
	for(i=0;i<9;i++)
	{
		printf("\n\t\tBase %d -> %d",i+2,b[i]);
	}
	
	/* Find the maximum frequency for
	 plot (print) the Frequency Distribution over different bases on x-axis */
	int max=0;
	for(i=0;i<9;i++)
	{
	    if(max<b[i])
	    max=b[i];
	}
	
	// Print the frequency distribution over different bases on x-axis
	printf("\n\n\tthe Frequency Distribution over different bases on x-axis -->\n\n");
	
	while(max)
	{
		printf("\t\t");
		for(i=0;i<9;i++)
		{
// Print an asterisk (*) if the frequency of the current base is greater than or equal to 'max'	
			if(b[i]>=max)
			printf("* ");
// Print a space if the frequency is less than 'max', to maintain spacing			
			else
			printf("  ");
		}
		printf("\n");
		max--;
	}
	
	// Print the base numbers on the x-axis
	printf("\t\t");
	for(i=2;i<=10;i++)
	printf("%d ",i);
	
	// Print the label for the BASE on the y-axis
	printf("\n\n\t\t      BASE");
		
	return 0;
}

// Function to find the largest digit in a number (base of the number)
int base(int n)
{
	int i,r,m=0;
	while(n)
	{
		r=n%10;
		if(m<r)
		m=r;
		n=n/10;
	}
	return m;
}

/*
         overview
This program generates random numbers,
finds the base of each number,
and then creates a frequency distribution
and graph to visualize the occurrences of each base.
The histogram is printed using asterisks,
where the height of each column represents the frequency of each base.
*/

/*
      the time complexity of each part:-
      
    ~ Some of loops that run a fixed number of times (not dependent on N),
	  so they have constant time complexity (O(1)).
	~ Some of loop runs N times,
	  where N is the constant defined as #define N 500.
	  The time complexity of this loop is O(N) 
	  because the time taken is directly proportional to the value of N.
	  
	Overall,
	the time complexity of the entire code is dominated by the loop to generate
	and print random numbers, which is O(N).
	The rest of the operations have constant time complexity,
	so they do not significantly affect the overall time complexity.
	
	Therefore, the correct time complexity of the entire code is O(N).  
*/
//                  ~chamanswami
