// O(_/n)  1<= n <= 1e16
int euler_totient(int n) {
    int result = n;

    for(int p = 2; p*p <= n; p++) {
        if(n % p == 0) {
            result -= result/p;
            while(n % p == 0)
            n = n/p;
        }
    }
    if(n > 1) // a prime greater than _/n
        result -= result/n;
    return result;    
}
