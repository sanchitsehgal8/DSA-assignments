#include <iostream>
using namespace std;

int n = 5;
int g[10][10];

void BFS(int s) {
    int q[50], f = 0, r = 0, vis[10];
    for(int i=0;i<n;i++) vis[i]=0;
    q[r++] = s;
    vis[s] = 1;
    while(f < r) {
        int u = q[f++];
        cout << u << " ";
        for(int v=0; v<n; v++) {
            if(g[u][v] != 0 && !vis[v]) {
                vis[v] = 1;
                q[r++] = v;
            }
        }
    }
    cout << endl;
}

void DFSrec(int u, int vis[]) {
    vis[u] = 1;
    cout << u << " ";
    for(int v=0; v<n; v++)
        if(g[u][v] != 0 && !vis[v])
            DFSrec(v, vis);
}

void DFS(int s) {
    int vis[10];
    for(int i=0;i<n;i++) vis[i]=0;
    DFSrec(s, vis);
    cout << endl;
}

int findp(int v, int parent[]) {
    if(parent[v] == v) return v;
    return parent[v] = findp(parent[v], parent);
}

void unionp(int a, int b, int parent[], int rank[]) {
    a = findp(a, parent);
    b = findp(b, parent);
    if(a != b) {
        if(rank[a] < rank[b]) parent[a] = b;
        else if(rank[b] < rank[a]) parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

void Kruskal() {
    int edges[50][3], k = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(g[i][j] != 0) {
                edges[k][0] = g[i][j];
                edges[k][1] = i;
                edges[k][2] = j;
                k++;
            }

    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++)
            if(edges[j][0] < edges[i][0]) {
                int t0 = edges[i][0], t1 = edges[i][1], t2 = edges[i][2];
                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];
                edges[j][0] = t0;
                edges[j][1] = t1;
                edges[j][2] = t2;
            }

    int parent[10], rank[10];
    for(int i=0;i<n;i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mst = 0;
    for(int i=0;i<k;i++) {
        int w = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];

        if(findp(u, parent) != findp(v, parent)) {
            mst += w;
            unionp(u, v, parent, rank);
        }
    }

    cout << mst << endl;
}

void Prim(int s) {
    int key[10], vis[10];
    for(int i=0;i<n;i++) {
        key[i] = 9999;
        vis[i] = 0;
    }
    key[s] = 0;
    int mst = 0;

    for(int c=0;c<n;c++) {
        int u = -1;
        for(int i=0;i<n;i++)
            if(!vis[i] && (u==-1 || key[i] < key[u]))
                u = i;

        vis[u] = 1;
        mst += key[u];

        for(int v=0;v<n;v++)
            if(g[u][v] != 0 && !vis[v] && g[u][v] < key[v])
                key[v] = g[u][v];
    }

    cout << mst << endl;
}

void Dijkstra(int s) {
    int dist[10], vis[10];
    for(int i=0;i<n;i++) {
        dist[i] = 9999;
        vis[i] = 0;
    }
    dist[s] = 0;

    for(int c=0;c<n;c++) {
        int u = -1;
        for(int i=0;i<n;i++)
            if(!vis[i] && (u==-1 || dist[i] < dist[u]))
                u = i;

        vis[u] = 1;

        for(int v=0;v<n;v++)
            if(g[u][v] != 0 && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    for(int i=0;i<n;i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main() {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j] = 0;

    g[0][1]=2; g[1][0]=2;
    g[0][2]=4; g[2][0]=4;
    g[1][2]=1; g[2][1]=1;
    g[1][3]=7; g[3][1]=7;
    g[2][4]=3; g[4][2]=3;
    g[3][4]=1; g[4][3]=1;

    BFS(0);
    DFS(0);
    Kruskal();
    Prim(0);
    Dijkstra(0);

    return 0;
}
