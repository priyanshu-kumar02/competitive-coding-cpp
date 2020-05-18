/*
fenwick require functions to be invertible
eg. Add, Subtract, multiply etc
Non-invertible functions like max, min, gcd etc require segtree 
*/

int bit[200001];
//int n = 100005;

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
