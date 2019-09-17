#include<stdio.h>
#include<malloc.h>
#define N 10
//设置的是顶点的那个条
typedef struct node {
	int adjvex;			//设置邻接点存储位置
	struct node* next;
}edge;
typedef struct {
	char data;			//顶点的符号
	edge* first;		//指向第一条边
}vex;
typedef struct {
	int vexnum;			//顶点的数量
	int arcnum;			//边的数量
	vex adj[N];			//顶点的数组
}Graph;
int locate(Graph, char);
void Traverse(Graph* g);
int main() {
	Graph G;
	int i, judeg;
	edge* s;
	printf("输入有向图请选择1,输入无向图请选择0:");
	if (scanf("%d", &judeg)) {}
	printf("请输入顶点个数:");
	if (scanf("%d", &G.vexnum) != 1) {
		printf("Wrong");
	}
	printf("请输入边的个数:");
	if (scanf("%d", &G.arcnum) != 1) {
		printf("Wrong");
	}
	printf("请输入%d个顶点:", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {
		if (scanf(" ")) {}
		if (scanf("%c", &G.adj[i].data) != 1) {
			printf("Wrong");
		}
	}
	//边链表的初始化
	for (int i = 0; i < G.vexnum; i++)
	{
		G.adj[i].first = NULL;
	}
	//边的录入工作
	printf("请输入%d条边:", G.arcnum);
	for (i = 0; i < G.arcnum; i++) {
		char ch1, ch2;
		int m, n;
		int Use = 0;
		if (scanf(" ")) {}
		if (scanf("%c%c", &ch1, &ch2)!=2) {
			printf("Wrong");
		}
		
		if (judeg == 1) {
			
			m = locate(G, ch1);
			n = locate(G, ch2);
			s = (edge*)malloc(sizeof(edge));
			if (!s) {
				exit(0);
			}
				s->adjvex = n;
				s->next = G.adj[m].first;
				G.adj[m].first = s;
			
		}
		else {
			m = locate(G, ch1);
			n = locate(G, ch2);
			s = (edge*)malloc(sizeof(edge));
			if (!s) {
				exit(0);
			}
			s->adjvex = n;
			s->next = G.adj[m].first;
			G.adj[m].first = s;

			s = (edge*)malloc(sizeof(edge));
			if (!s)
				exit(0);
			s->adjvex = m;
			s->next = G.adj[n].first;
			G.adj[n].first = s;
		}
	}
	Traverse(&G);
	return 0;
}
int locate(Graph g, char ch) {
	int i;
	for (i = 0; i < g.vexnum; i++) {
		if (g.adj[i].data == ch)
			return i;
	}
}
void Traverse(Graph* g) {
	edge* s;
	s = (edge*)malloc(sizeof(edge));
	if (s == NULL)
		exit(0);
	int n = 0;
	for (int i = 0; i < g->vexnum; i++) {
		n = 0;
		s = g->adj[i].first;
		while (s) {
			n++;
			s = s->next;
		}
		printf("顶点%c的度是%d\n", g->adj[i].data, n);
	}
}
