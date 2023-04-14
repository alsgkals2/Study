#include <iostream>

using namespace std;
const int MAXV = 201;
struct graph {
	int degree[MAXV];
	int edges[MAXV][MAXV];
	int verteies = 0;
};

int inputGraph(graph*);
void initializeG(graph*);
void dfs(graph*,int ,int);

int ColorBoard[MAXV] = { 0 }; //1 :빨간색 2:검정색


bool finished = false;
void dfs(graph* g,int v,int color)
{
	if (finished) return;
	ColorBoard[v] = color;

	for (int i = 0; i < g->degree[v]; i++) {
		int index = g->edges[v][i];
		if (ColorBoard[index] == 0)
		{
			dfs(g, index, (color) % 2 + 1); //color값은 1아니면 2
		}
		else {
			if (ColorBoard[index] == ColorBoard[v]) {
				finished = true;
			}
		} //색깔이 있는경우

		if (finished) return;
	}
}

int inputGraph(graph* g) {
	int n, l;
	int x, y;
	cin >> n;
	if (n == 0) return -1;
	cin >> l;//모서리갯수

	for (int i = 0; i < l; i++) {
		cin >> x >> y;
		if (g->degree[x] == 0) g->verteies++;
		if (g->degree[y] == 0) g->verteies++;

		g->edges[x][g->degree[x]] = y;
		g->degree[x] ++;
		g->edges[y][g->degree[y]] = x;
		g->degree[y] ++;
	}
}

void initializeG(graph* g)
{
	finished = false;
	g->verteies = 0;
	for (int i = 0; i < MAXV; i++)
	{
		g->degree[i] = 0;
		ColorBoard[i] = 0;
	}
}

int main()
{
	graph* g = new graph();
	while (1) {
		
		initializeG(g);
		if (inputGraph(g) == -1) break;
		dfs(g, 0, 1);
		if (finished) cout << "NOT BICOLORABLE." << '\n';
		else cout << "BICOLORABLE." << '\n';
	}
    return 0;
}

