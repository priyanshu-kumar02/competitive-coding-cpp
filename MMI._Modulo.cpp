1. ( a + b ) % c = ( ( a % c ) + ( b % c ) ) % c
2. ( a * b ) % c = ( ( a % c ) * ( b % c ) ) % c
3. ( a – b ) % c = ( ( a % c ) – ( b % c ) ) % c ( see note )
4. ( a / b ) % c NOT EQUAL TO ( ( a % c ) / ( b % c ) ) % c


For 4...

The multiplicative inverse of a number y is z iff (z * y) == 1.

Eg. if M= 7 the MMI of 4 is 2 as ( 4 * 2 ) %7 ==1,
if M=11, the MMI of 7 is 8 as ( 7 * 8 )%11 ==1,
if M=13, the MMI of 7 is 2 as ( 7 * 2 ) % 13==1.



Now, (x/y)%M = x*MMI(y,M);

CODE TO FIND MMI USING FERMET THEOREM.
MMI(y,M)=[y^(m-2)]%M;

ll pow(ll x, ll y,ll m) {
    if( y == 0) return 1;
    ll half = pow(x, y/2, m);
    ll full = (half * half) % m;
    return y%2 ? (x * full) % m : full;
}

int findMMI_fermat(int n,int M) 
{
    return pow(n,M-2,M);
}

source:https://codeaccepted.wordpress.com/2014/02/15/output-the-answer-modulo-109-7/
