/* For cost function defined on descrete integers */

int ternary_search_minima(int l, int r) {
    while(r-l > 3) {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if(cost(m1) < cost(m2)) r = m2;
        else l = m1;
    }
    int minima = __LONG_LONG_MAX__;
    for(int i = l; i <=r ; i++) {
        minima = min(minima, cost(i));
    }
    return minima;
}
