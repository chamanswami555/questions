#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool Prime(int);
bool Odd(int);

int main() 
{	
    int rn[100];
    int on[100];
    int pn[100];
    int oc=0;
    int pc=0;
    int i;
    
    printf("\n\t100 Random Numbers :-\n");
    
    for(i=0;i<100;i++)
	{		
        rn[i]=rand()%50;   // Generate random numbers from 1 to 50
        
        printf("%d ",rn[i]);

        if(Odd(rn[i]))
		{
            on[oc]=rn[i];
            oc++;
        }

        if(Prime(rn[i]))
		{
            pn[pc]=rn[i];
            pc++;
        }
    }

    printf("\n\n\tOdd Numbers :-\n");
    
    for(i=0;i<oc;i++)
	{
        printf("%d ",on[i]);
    }

    printf("\n\n\tPrime Numbers :-\n");
    
    for(i=0;i<pc;i++)
	{
        printf("%d ",pn[i]);
    }

    return 0;
    
}



bool Prime(int num)
{
	
	int i;
	
    if(num<=1)
    {
    	return false;
	}
	
	for(i=2;i<=sqrt(num);i++)
	{
        if (num%i==0)
        return false;
    }
    
    return true;
    
}


bool Odd(int num)
{
	
	if(num%2!=0)
	{
		return true;
	}
	
	else
	{
		return false;
	}
	
}

//                  ~ chamanswami
