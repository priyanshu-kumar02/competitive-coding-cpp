/* For cost function defined on descrete integers */

int ternary_search_minima(int l, int r) {
    while(r-l > 3) {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if(f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    int minima = __LONG_LONG_MAX__;
    for(int i = l; i <=r ; i++) {
        minima = min(minima, f(i));
    }
    return minima;
}

/* For continous function on real numbers */

double ternary_search_minima(double l, double r) {
    int iterations = 300;
    while(iterations--) {
        double m1 = l + (r-l)/3.0;
        double m2 = r - (r-l)/3.0;
        if(f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    return f(l);
}
