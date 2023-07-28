#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool Prime(int);
bool Odd(int);

int main()
{
    int *rn=(int*)malloc(100*sizeof(int));
    int *on=NULL;
    int *pn=NULL;
    int oc=0;
    int pc=0;
    int i;
    
    printf("\n\t100 Random Numbers :-\n");

    for(i=0;i<100;i++)
	{		
        rn[i]=rand()%50;  // Generate random numbers from 1 to 1000

        printf("%d ",rn[i]);

        if(Odd(rn[i]))
		{
            oc++;
            on=(int*)realloc(on,oc*sizeof(int));
            on[oc-1]=rn[i];
        }

        if(Prime(rn[i]))
		{
            pc++;
            pn=(int*)realloc(pn,pc*sizeof(int));
            pn[pc-1]=rn[i];
        }
    }

    printf("\n\n\tOdd Numbers :-\n");
    
    for (i=0;i<oc;i++)
	{
        printf("%d ",*(on+i));
    }

    printf("\n\n\tPrime Numbers:\n");
    
    for (i=0;i<pc;i++)
	{
        printf("%d ",*(pn+i));
    }

    // Free dynamically allocated memory
    
    free(rn);
    free(on);
    free(pn);

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
