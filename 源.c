#include<stdio.h>
#include<malloc.h>
#define N 10
//���õ��Ƕ�����Ǹ���
typedef struct node {
	int adjvex;			//�����ڽӵ�洢λ��
	struct node* next;
}edge;
typedef struct {
	char data;			//����ķ���
	edge* first;		//ָ���һ����
}vex;
typedef struct {
	int vexnum;			//���������
	int arcnum;			//�ߵ�����
	vex adj[N];			//���������
}Graph;
int locate(Graph, char);
void Traverse(Graph* g);
int main() {
	Graph G;
	int i, judeg;
	edge* s;
	printf("��������ͼ��ѡ��1,��������ͼ��ѡ��0:");
	if (scanf("%d", &judeg)) {}
	printf("�����붥�����:");
	if (scanf("%d", &G.vexnum) != 1) {
		printf("Wrong");
	}
	printf("������ߵĸ���:");
	if (scanf("%d", &G.arcnum) != 1) {
		printf("Wrong");
	}
	printf("������%d������:", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {
		if (scanf(" ")) {}
		if (scanf("%c", &G.adj[i].data) != 1) {
			printf("Wrong");
		}
	}
	//������ĳ�ʼ��
	for (int i = 0; i < G.vexnum; i++)
	{
		G.adj[i].first = NULL;
	}
	//�ߵ�¼�빤��
	printf("������%d����:", G.arcnum);
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
		printf("����%c�Ķ���%d\n", g->adj[i].data, n);
	}
}
