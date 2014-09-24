#include <iostream>
#include <queue>
#include <limits.h>
#include <stack>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

#define N 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2

queue<int> Q;
stack<int> S;
struct Vertex;
struct Edge
{
	int start;
	int end;
	int value;
	Edge *next;
	Edge(int s, int e, int v):start(s), end(e), value(v), next(NULL){}
};
struct Vertex
{
	int color;
	int d;
	int pie;
	Edge *head;
	Vertex():head(NULL), color(WHITE), d(INT_MAX), pie(0){}
};
class Link_Graph
{
public:
	int n;
	Vertex *v;
	Link_Graph(int num):n(num)
	{
		v = new Vertex[n + 1];
	}
	~Link_Graph()
	{
		delete []v;
	}

	void AddSingleEdge(int start, int end, int value = 1)
	{
		Edge *newEdge = new Edge(start, end, value);
		/*
		 添加新的边，start都是相同的，按照end的大小来进行边的插入
		*/
		if(v[start].head == NULL || v[start].head->end > end) //直接在头部插入
		{
			newEdge->next = v[start].head;
			v[start].head = newEdge;
		}
		else
		{
			Edge *e = v[start].head;
			Edge *pre = e;
			while(e != NULL && e->end < end)
			{
				pre = e;
				e = e->next;
			}
			if(e != NULL && e->end == end)//重复插入，直接返回
			{
				delete newEdge;
				return;
			}
			newEdge->next = e;
			pre->next = newEdge;
		}
	}

	void AddDoubleEdge(int a, int b, int value)
	{
		AddSingleEdge(a, b, value);
		AddSingleEdge(b, a, value);
	}

	void DeleteSingleEdge(int start, int end)
	{
		Edge *e = v[start].head;
		Edge *pre = e;
		while(e != NULL || e->end < end)
		{
			pre = e;
			e = e->next;
		}
		if(e == NULL || e->end > end) return;
		if(e == v[start].head)
		{
			v[start].head = e->next;
		}
		else
		{
			pre->next = e->next;
		}
		delete e;
	}

	void BFS(int s);
	void print_path(int s, int v);
	void DFS(int s);
};

void Link_Graph::BFS(int s)
{
	int i;
	for(int i = 1; i <= n; i++)
	{
		v[i].color = WHITE;
		v[i].d = INT_MAX;
		v[i].pie = 0; 
	}
	v[s].color = GRAY;
	v[s].d = 1;
	v[s].pie = 0;
	Q.push(s);
	while(!Q.empty())
	{
		int u, v1;
		u = Q.front();
		Q.pop();
		Edge *e = v[u].head;
		while(e)
		{
			v1 = e->end;
			if(v[v1].color == WHITE)
			{
				v[v1].color = GRAY;
				v[v1].pie = u;
				v[v1].d = v[u].d + 1;
				Q.push(v1);
			}
			e = e->next;
		}
		v[u].color = BLACK;
	}
}

void Link_Graph::print_path(int s, int u)
{
	BFS(s);
	if(s == u)
		cout<<' ';
	else
	{
		if(v[u].pie == 0)
			cout<<"NO patt";
		else
		{
			print_path(s, v[u].pie);
			cout<<u;
		}
	}
}

void Link_Graph::DFS(int s)
{
	v[s].color = GRAY;
	v[s].d = 1;
	v[s].pie = 0;
	S.push(s);
	while(!S.empty())
	{
		int u, v1;
		u = S.top();
		Edge *e = v[u].head;
		cout<<u<<"\t"<<v[u].d<<"\t"<<v[u].pie<<endl;
		while(e)
		{
			v1 = e->end;
			if(v[v1].color == WHITE)
			{
				v[v1].color = GRAY;
				v[v1].pie = u;
				v[v1].d = v[u].d + 1;
				S.push(v1);
				break;
			}
			e = e->next;
		}
		if(e == NULL)
		{
			S.pop();
			v[u].color = BLACK;
			//printf("%d\t", u);
			//cout<<u<<"\t"<<v[u].d<<"\t"<<v[u].pie<<endl;
		}
	}
}
ifstream& open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}
int main(int argc, char *argv[])
{
	Link_Graph *G = new Link_Graph(6);
	int i = 0, a, b;
	ifstream infile;
	open_file(infile, string("data.txt"));
	string line;
	while(getline(infile, line))
	{
		istringstream linestream(line);
		linestream>>a>>b;
		//cout<<a<<b<<endl;
		G->AddSingleEdge(a, b);
	}
	/*
	for(i = 1; i <= 8; i++)
	{
		cin>>a>>b;
		G->AddSingleEdge(a, b);	
	}
	*/
	G->DFS(1);
	//G->BFS(2);
	/*
	for(i = 1; i <= 6; i++)
	{
		cout<<G->v[i].d<<' ';
	}
	*/
	return 1;
}
