nclude <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 999999
#define n 9
int parent(int i)
{
		return i / 2;
}

int left(int i)
{
		return 2 * i;
}

int right(int i)
{
		return 2 * i + 1;
}

void swap(int *heap, int a, int b)
{
		int temp = heap[a];
		heap[a] = heap[b];
		heap[b] = temp;
}

int heap_size(int *heap)
{
		return heap[0];
}

void min_heapify(int *heap, int *key, int root)
{
		int l = left(root);
		int r = left(root);

		int smallest;
		if(l < heap_size(heap) && key[heap[l]] < key[heap[root]])
		{
				smallest = l;
		}
		else
		{
				smallest = root;
		}
		if(r < heap_size(heap) && key[heap[r]] < heap[heap[smallest]])
		{
				smallest = r;
		}

		if(smallest != root)
		{
				swap(heap, root, smallest);
				min_heapify(heap, key, smallest);
		}
}

int extract_min(int *heap)
{
		int result = heap[1];
		swap(heap, 1, heap_size(heap));
		heap[0]--;
		return result;
}

void build_heap(int *heap, int *key)
{
		int i;
		for(i = heap_size(heap) / 2; i > 0; i--)
		{
				min_heapify(heap, key, i);
		}
}

int Prim_shortest(int m[][n + 1], int *heap, int *key, int source)
{
		int i;
		int longest = 0;
		for(i = 1; i < key[0]; i++)
		{
				key[i] = MAX;
		}

		for(i = 1; i < heap[0]; i++)
		{
				heap[i] = i;
		}

		key[source] = 0;
		build_heap(heap, key);

		while(heap_size(heap) != 0)
		{
				int u = extract_min(heap);
				if(key[u] > longest)
				{
						longest = key[u];
				}
				int j;
				for(j = 1; j <= heap_size(heap); j++)
				{
						if(key[heap[j]] > m[u][heap[j]])
						{
								key[heap[j]] = m[u][heap[j]];
						}
				}
				build_heap(heap, key);
		}

		return longest;
}

/*
   void init_matrix(int **m, int row)
   {
   int i, j;
   for(i = 1; i <= row; i++)
   for(j = 1; j <= row; j++)
   {
   if(i == j)
   {
   m[i][j] = 0;
   }
   else
   {
   m[i][j] = MAX;
   }
   }
   }
   */

int main(int argc, char *argv[])
{

		int en[n + 1][n + 1] = {
				{MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},
				{MAX,MAX,4,MAX,MAX,MAX,MAX,MAX,8,MAX},
				{MAX,4,MAX,8,MAX,MAX,MAX,MAX,11,MAX},
				{MAX,MAX,8,MAX,7,MAX,4,MAX,MAX,2},
				{MAX,MAX,MAX,7,MAX,9,14,MAX,MAX,MAX},
				{MAX,MAX,MAX,MAX,9,MAX,10,MAX,MAX,MAX},
				{MAX,MAX,MAX,4,14,10,MAX,2,MAX,MAX},
				{MAX,MAX,MAX,MAX,MAX,MAX,2,MAX,1,6},
				{MAX,8,11,MAX,MAX,MAX,MAX,1,MAX,7},
				{MAX,MAX,MAX,2,MAX,MAX,MAX,6,7,MAX}};
		int heap[10];
		heap[0] = n;
		int key[10];
		key[0] = n;

		int path_length = Prim_shortest(en, heap, key, 1);
		cout<<path_length;
		return 0;
}
