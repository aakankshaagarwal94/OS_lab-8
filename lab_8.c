#include<stdio.h>

int index_free[4][2] = {{0,1},{1,1},{3,1},{6,1}};
int last;

int bestFit(int b_size)
{
	int j;
	int temp=0;
	if(b_size>0 && b_size<=100)
	{
		j=0;
	}
	else if(b_size>100 && b_size<=200)
	{
		j=1;
	}
	else if(b_size>200 && b_size<=300)
	{
		j=2;
	}
	else if(b_size>300 && b_size<=400)
	{
		j=3;
	}
	else
	{
		printf("\nEnter a valid size of memory block(100, 200, 300, 400): ");
		return 0;
	}
	while(j!=4)
	{
		if(index_free[j][1]==1 && ((j+1)*100>=b_size))
		{
			index_free[j][1]=0;
			temp=1;			
			//index for next fit
			last=j;
			break;
		}
		j++;
	}
	if(temp==1)
		return 1;
	else 
		return 0;
}

int worstFit(int b_size)
{
	int j=3,temp=0;
	if(b_size<0 || b_size>400)
	{
		printf("\nEnter a valid size of memory block(100, 200, 300, 400): ");
		return 0;
	}
	while(j>=0)
	{
		printf("%d",index_free[j][1]);
		if(index_free[j][1]==1 && ((j+1)*100>=b_size))
		{
			index_free[j][1]=0;
			temp=1;			
			//index for next fit
			last=j;
			break;
		}
		j--;
	}
	if(temp==1)
		return 1;
	else 
		return 0;
}

int firstFit(int b_size)
{
	int j=0,temp=0;
	if(b_size<0 || b_size>400)
	{
		printf("\nEnter a valid size of memory block(100, 200, 300, 400): ");
		return 0;
	}
	while(j!=4)
	{
		if(index_free[j][1]==1 && ((j+1)*100>=b_size))
		{
			index_free[j][1]=0;
			temp=1;			
			//index for next fit			
			last=j;
			break;
		}
		j++;
	}	
	if(temp==1)
		return 1;	
	else 
		return 0;
}

int nextFit(int b_size)
{
	int j=last+1, i=4, temp=0;
	if(b_size<0 || b_size>400)
	{
		printf("\nEnter a valid size of memory block(100, 200, 300, 400): ");
		return 0;
	}
	while(i)
	{
		if((index_free[j%4][1]==1) && (((j%4)+1)*100>=b_size))		{
			index_free[j%4][1]=0;
			temp=1;			
			last=j;
			break;
		}
		j++;
		i--;
	}
	if(temp==1)
		return 1;
	else 
		return 0;	
}

void current()
{
	int i;
	
	for(i=0;i<4;i++)
	{		
		
		if(index_free[i][1]==1)
			printf("\nThe %dKB block is available",(i+1)*100);
		else
			printf("\nThe %dKB block is unavailable",(i+1)*100);
	}
}

void release()
{
	int rel, mem_Size;
	do
	{
		current();
		printf("\nDo you want to release some memory?(1/0)");
		scanf("%d",&rel);
		if(rel)
		{
			printf("\nEnter the block size(KBs) which you want to release(100, 200, 300, 400): ");
			scanf("%d",&mem_Size);
			switch(mem_Size)
			{
				case 100:
					index_free[0][1]=1;
					break;
				case 200:
					index_free[1][1]=1;
					break;
				case 300:
					index_free[2][1]=1;
					break;
				case 400:
					index_free[3][1]=1;
					break;
				default:
					printf("\nEnter valid block size (100, 200, 300, 400): ");
			}
		}
	}while(rel);
	return;
}

int main()
{
	int mem_Size;
	index_free[0][1] = 0;
	index_free[1][1] = 0;
	current();	

	//Checking the first fit algorithm
	printf("\n******** First Fit ********\n");	
	
	do
	{		
		printf("\nEnter the memory required: ");
		scanf("%d",&mem_Size);
		if(firstFit(mem_Size))
			printf("\nMemory allocated successfully!");
		else
			printf("\nMemory cannot be allocated successfully!");
		current();
		printf("\nDo you want to allocate more memory?(1/0): ");
		scanf("%d",&mem_Size);
		if(!mem_Size)
			break;
	}while(1);
	release();

	//Checking the best fit algorithm
	printf("\n******** Best Fit ********\n");
	
	do
	{
		printf("\nEnter the memory required: ");
		scanf("%d",&mem_Size);
		if(bestFit(mem_Size))
			printf("\nMemory allocated successfully!");
		else
			printf("\nMemory cannot be allocated successfully!");
		current();
		printf("\nDo you want to allocate more memory?(1/0): ");
		scanf("%d",&mem_Size);
		if(!mem_Size)
			break;
	}while(1);
	release();

	//Checking the Next fit algorithm
	printf("\n******** Next Fit ********\n");
	
	do
	{
		printf("\nEnter the memory required: ");
		scanf("%d",&mem_Size);
		if(nextFit(mem_Size))
			printf("\nMemory allocated successfully!");
		else
			printf("\nMemory cannot be allocated successfully!");
		current();
		printf("\nDo you want to allocate more memory?(1/0): ");
		scanf("%d",&mem_Size);
		if(!mem_Size)
			break;
	}while(1);
	release();

	//Checking the worst fit algorithm
	printf("\n******** Worst Fit ********\n");
	
	do
	{
		printf("\nEnter the memory required: ");
		scanf("%d",&mem_Size);
		if(worstFit(mem_Size))
			printf("\nMemory allocated successfully!");
		else
			printf("\nMemory cannot be allocated successfully!");
		current();
		printf("\nDo you want to allocate more memory?(1/0): ");
		scanf("%d",&mem_Size);
		if(!mem_Size)
			break;
	}while(1);
	release();

	return 0;
}
