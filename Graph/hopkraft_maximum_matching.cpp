/* See full solution at: https://cses.fi/problemset/result/471528/  */

#define NIL 0
#define INF (1<<28)

vector< int > adj[SZ];
int n, m, match[SZ], dist[SZ];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// adj = NIL[0] ∪ adj1[adj[1---n]] ∪ adj2[adj[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue<int> Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            for(int v: adj[u]) {
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        for(int v: adj[u]) {
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp_max_match() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in adj
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}




// helper to print
void print_matching() {
    for(int i = 1; i <=n ; i++) {
        if(match[i] != NIL)
        cout << i << " " << match[i]-n << endl;
    }
} 
