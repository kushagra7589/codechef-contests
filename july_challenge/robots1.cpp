#include <bits/stdc++.h>

using namespace std;

const int MAX_VERTICES = 1e4 + 10;
const int MAX_SIZE = 110;
const int INF = 1e5;

typedef struct queue1{
	int A[MAX_VERTICES];
	int front;
	int rear;
}queue1;

int isempty(queue1 *q){
	if(q->front == -1)
		return 1;
	return 0;
}

void enqueue1(queue1 *q, int x){
	if(isempty(q))
		q->front = q->rear = 0;
	else
		q->rear += 1;
	q->A[q->rear] = x;
}

int dequeue1(queue1 *q){
	if(isempty(q))
		return -1;
	int x = q->A[q->front];
	if(q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front += 1;
	return x;
}

struct Node{
	int ver;
	struct Node *next; 
};

struct vertex{
	int color;
	int distance;
	struct Node *next;
};

typedef struct Node Node;
typedef struct vertex vertex;

bool arr[MAX_SIZE][MAX_SIZE];

Node * create_node(int a){
	Node *z = (Node *)malloc(sizeof(Node));
	z->ver = a;
	z->next = NULL;
	return z;
}

void create_edge(vertex V[],int x, int y){
	Node *z = create_node(y);
	z->next = V[x].next;
	V[x].next = z;
}

void bfs(vertex V[], int n, int s, queue1 *q){
	int i;
	for(i=0; i<n; i++){
		V[i].color = 0;
		V[i].distance = INF;
	}
	V[s].color = 1;
	V[s].distance = 0;
	enqueue1(q, s);
	while(!isempty(q)){
		int u = dequeue1(q);
		Node *temp = V[u].next;
		while(temp){
			if(V[temp->ver].color == 0){
				V[temp->ver].color = 1;
				V[temp->ver].distance = V[u].distance + 1;
				enqueue1(q, temp->ver);
			}
			temp = temp->next;
		}
		V[u].color = 2;
	}
}

void initialise(vertex V[], int size){
	for(int i=0; i<size; i++){
		V[i].color = 0;
		V[i].distance = INF;
		V[i].next = NULL;
	}
}

int convert_to_1d(int i, int j, int m){
	return i*m + j;
}

void create_connection(vertex V[], int xi, int yi, int xf, int yf, int n, int m){
	int ver = convert_to_1d(xi, yi, m);
	int edge_end;
	if(xi + xf < n && yi + yf < m && arr[xi+xf][yi + yf] == false){
		edge_end = convert_to_1d(xi+xf, yi+yf, m);
		create_edge(V, ver, edge_end);
	}
	if(xi - xf >= 0 && yi + yf < m && arr[xi-xf][yi + yf] == false){
		edge_end = convert_to_1d(xi-xf, yi+yf, m);
		create_edge(V, ver, edge_end);
	}
	if(xi + xf < n && yi - yf >= 0 && arr[xi+xf][yi - yf] == false){
		edge_end = convert_to_1d(xi+xf, yi-yf, m);
		create_edge(V, ver, edge_end);
	}
	if(xi - xf >= 0 && yi - yf >= 0 && arr[xi-xf][yi - yf] == false){
		edge_end = convert_to_1d(xi-xf, yi-yf, m);
		create_edge(V, ver, edge_end);
	}
}

void create_graph(vertex V[], int n, int m, int sum){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == false){
				for(int total = 1; total<=sum; total++){
					for(int x=0; x<=total; x++){
						create_connection(V, i, j, x, total-x, n, m);
					}
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n, m, k1, k2;
	queue1 q;
	q.front = -1;
	q.rear = -1;
	while(t--){
		cin>>n>>m>>k1>>k2;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
			}
		}
		vertex graph1[MAX_VERTICES], graph2[MAX_VERTICES];
		initialise(graph1, MAX_VERTICES);
		initialise(graph2, MAX_VERTICES);
		create_graph(graph1, n, m, k1);
		create_graph(graph2, n, m, k2);
		bfs(graph1, n*m, convert_to_1d(0, 0, m), &q);
		bfs(graph2, n*m, convert_to_1d(0, m-1, m), &q);
		// vector<int> dis;
		int min_max = INF;
		for(int i=0; i<n*m; i++){
			// cout<<"i : "<<i<<" ";
			// cout<<"graph 1: "<<graph1[i].distance<<"\tgraph 2: "<<graph2[i].distance<<endl;
			int max_dis = max(graph1[i].distance, graph2[i].distance);
			if(max_dis < min_max)
				min_max = max_dis;
		}
		if(min_max == INF)
			min_max = -1;
		cout<<min_max<<endl;
	}
}

