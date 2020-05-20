/* point-update, range-query */

int tree[4*SZ];
 
void update(int i, int ss, int se, int pos, int val) {
    if(ss > se || pos < ss || pos > se) return;
    if(ss == se)  { tree[i] = val; return; }
    int m = (ss + se) >> 1;
    update(2*i, ss, m, pos, val);
    update(2*i+1, m+1, se, pos, val);
    tree[i] = min(tree[2*i], tree[2*i+1]);
}
 
int query(int i, int ss, int se, int l, int r) {
    if(ss > se || l > se || r < ss) return __LONG_LONG_MAX__;
    if(ss >= l && se <= r) return tree[i];
    int m = (ss + se) >> 1;
    int l_min = query(2*i, ss, m, l, r);
    int r_min = query(2*i+1, m+1, se, l, r);
    return min(l_min, r_min);
}
