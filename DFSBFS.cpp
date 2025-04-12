#include <iostream>
#include <cstring> // For memset()
using namespace std;
int cost[10][10], n, qu[10], front = 0, rear = 0,
visit[10], visited[10];
int stk[10], top = 0, visit1[10], visited1[10];
void bfs(int start) {
 cout << "\nThe BFS of the Graph is: ";
 memset(visited, 0, sizeof(visited)); // Reset
visited array
 visited[start] = 1;
 cout << start << " ";
 qu[rear++] = start;
 while (front != rear) {
 int v = qu[front++];
 for (int j = 0; j < n; j++) {
 if (cost[v][j] == 1 && visited[j] == 0) {
 visited[j] = 1;
 cout << j << " ";
 qu[rear++] = j;
 }
 }
 }
}
void dfs(int start) {
 cout << "\nThe DFS of the Graph is: ";
 memset(visited1, 0, sizeof(visited1)); // Reset visited array
visited1[start] = 1;
 cout << start << " ";
 stk[top++] = start;
 while (top > 0) {
 int v = stk[--top];
 for (int j = n - 1; j >= 0; j--) { //
Process in descending order for distinct DFS output
 if (cost[v][j] == 1 && visited1[j] == 0)
{
 visited1[j] = 1;
 cout << j << " ";
 stk[top++] = v; // Push current node
back to stack for backtracking
 stk[top++] = j; // Push next node to
visit
 break;
 }
 }
 }
}
int main() {
 int m, i, j;
 cout << "Enter number of vertices: ";
 cin >> n;
 cout << "Enter number of edges: ";
 cin >> m;
 // Initialize adjacency matrix and arrays
memset(cost, 0, sizeof(cost));
 cout << "\nEnter edges (format: i j):\n";
 for (int k = 0; k < m; k++) {
 cin >> i >> j;
 cost[i][j] = 1;
 cost[j][i] = 1;
 }
 cout << "\nThe adjacency matrix of the graph
is:\n";
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 cout << " " << cost[i][j];
 }
 cout << endl;
 }
 int start;
 cout << "\nEnter initial vertex for BFS: ";
 cin >> start;
 bfs(start);
 cout << "\n\nEnter initial vertex for DFS: ";
 cin >> start;
 dfs(start);
 cout << endl;
 return 0;
}
