/*
Fenwick require functions to be invertible
eg. Add, Subtract, multiply etc
Non-invertible functions like max, min, gcd etc require segtree 
*/


/* Point update && range-sum code: */


int bit[200001];
//int n = 200000;

void update(int i, int delta) {
    for(; i <= n; i += i&-i)
    bit[i] += delta;
}

int query(int i) {
    int sum = 0;
    for(; i > 0; i -= i&-i) 
        sum += bit[i];
    return sum;
}




/*
Range-update && range-sum code: 
Problem: https://cses.fi/problemset/task/1651/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios::sync_with_stdio(0);cin.tie(0)

int n, m, x, q, a, b, type, u, k;

/////////////////////////////////////////////////

int bit[200001];

void update(int i, int delta) {
    for(; i <= n; i += i&-i)
    bit[i] += delta;
}

int query(int i) {
    int sum = 0;
    for(; i > 0; i -= i&-i) 
        sum += bit[i];
    return sum;
}

void purple()
{
    cin >> n >> q;

    for(int i = 1; i <= n ; i++) {
        cin >> x;
        update(i, +x);
        update(i+1, -x);
    }
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> a >> b >> u;
            update( a , +u);
            update(b+1, -u);
        }
        else {
            cin >> k;
            cout << query(k) << endl;
        }
    }
}

signed main() {
    boost;
    int t=1;
    while(t--) purple();
}
