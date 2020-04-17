vector<int> dsu(SZ);

int root(int x) {
    return (x==dsu[x]) ? x : dsu[x] = root(dsu[x]);
}

void connect(int u, int v) {
    dsu[root(u)] = root(v);
}

void initialise() {
   for(int i=1; i<=n; i++) dsu[i]=i;
}
