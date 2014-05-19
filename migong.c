#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int x;
	int y;
	struct stack* next;
};
typedef struct stack stack_link;
typedef stack_link* plink;

plink push(plink s, int x, int y)
{
	plink new_node;
	new_node = (plink)malloc(sizeof(stack_link));
	if(!new_node)
	{
		printf("Error!\n");
		exit(-1);
	}
	new_node->x = x;
	new_node->y = y;
	new_node->next = s;
	s = new_node;
	return s;
}

plink pop(plink s, int* x, int* y)
{
	plink top;
	if(s != NULL)
	{
		top = s;
		s = s->next;
		*x = top->x;
		*y = top->y;
		free(top);
	}
	else
	{
		*x = -1;
	}

	return s;
}

void stack_maze(int a[][10], plink s, int x, int y)
{
	int i, j;
	while(x > 1 || y > 1)
	{
		a[x][y] = 2;
		if(a[x-1][y] <= 0)
		{
			x = x - 1;
			s = push(s, x, y);
		}
		else if(a[x+1][y] <= 0)
		{
			x = x + 1;
			s = push(s, x, y);
		}
		else if(a[x][y+1] <= 0)
		{
			y = y + 1;
			s = push(s, x, y);
		}
		else if(a[x][y-1] <= 0)
		{
			y = y - 1;
			s = push(s, x, y);
		}
		else
		{
			a[x][y] = 3;
			s = pop(s, &x, &y);
		}
	}
	a[x][y] = 2;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int i, j;
	plink s = NULL;
	int migong[10][10] =
		 	    {
		 	        {1,1,1,1,1,1,1,1,1,1},
		            {1,0,0,0,0,0,0,1,1,1},
     	 	        {1,0,1,1,1,1,1,0,0,1},
		 	        {1,0,1,0,0,0,0,0,0,1},
		 	        {1,0,0,0,1,0,1,1,1,1},
		 	        {1,1,1,1,0,0,1,1,1,1},
		 	        {1,0,0,0,0,1,1,1,1,1},
		 	        {1,0,1,1,0,0,1,1,1,1},
		 	        {1,0,0,0,0,0,0,0,0,1},
			        {1,1,1,1,1,1,1,1,1,1}
		 	    };
	printf("before walk on the maze:\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
	    	printf("%d",migong[i][j]);
        }
	        printf("\n");
    }
    printf("\n");
    printf("we start walk on the maze\n");
    stack_maze(migong,s,8,8);

	return 0;
}
