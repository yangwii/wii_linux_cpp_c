#include <stdio.h>
#include <stdlib.h>

#define n 9
#define max 100

struct _edge{
		int u;
		int v;
		int value;
}e[max];

int p[max];
int father[n];
int rank[n];

typedef struct _edge edge;

int cmp(const void *a, const void *b)
{
		return (*(edge *)a).value > (*(edge *)b).value ? 1 : -1;
}

void makeset()
{
		for(int i = 0; i < n; i++)
		{
				father[i] = i;
				rank[i] = 0;
		}
}

int findset(int x)
{
		if(x != father[x])
		{
				father[x] = findset(father[x]);
		}

		return father[x];
}

void unionset(int x, int y)
{
		if(rank[x] > rank[y])
		{
				father[y] = x;
		}
		else if(rank[x] < rank[y])
		{
				father[x] = y;
		}
		else
		{
				rank[y]++;
				father[x] = y;
		}
}

int main(int argc, char *argv[])
{
		int i, j, x, y, h = 0, sum = 0, k = 0;
		int en[n][n] = {{0,4,0,0,0,0,0,8,0},
				{4,0,8,0,0,0,0,11,0},
				{0,8,0,7,0,4,0,0,2},
				{0,0,7,0,9,14,0,0,0},
				{0,0,0,9,0,10,0,0,0},
				{0,0,4,14,10,0,2,0,0},
				{0,0,0,0,0,2,0,1,6},
				{8,11,0,0,0,0,1,0,7},
				{0,0,2,0,0,0,6,7,0},
		};

		for(i = 0; i < n; i++)
		{
				for(j = 0; j <= i ; j++)
				{
						if(en[i][j] != 0)
						{
								e[k].u = i;
								e[k].v = j;
								e[k].value = en[i][j];
								k++;
						}
				}
		}

		makeset();
		qsort(e, k, sizeof(edge), cmp);
		for(i = 0; i < k; i++)
		{
				x = findset(e[i].u);//判断u，v是否属于同一个树
				y = findset(e[i].v);//如果不属于， 则加入，如果是，如果加入，将形成环
				if(x != y)
				{
						unionset(x, y);
						sum += e[i].value;
						p[h++] = i;
				}
		}
		printf("The value of MST is:%d.\n", sum);
		for(i = 0; i < h; i++)
		{
				printf("Edge %c - %c, value:%d.\n", e[p[i]].u + 'a', e[p[i]].v + 'a', e[p[i]].value);
		}
		return 0;
}
