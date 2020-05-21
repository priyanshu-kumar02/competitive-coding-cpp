/*********ITERATIVE******* when m=1e9+7 */
//convert b into binary form to understand this
//complex: log(b)

int exp(int a,int b,int m) {
    int ans=1;
	while (b) {
		if(b & 1LL)
		ans = (ans * a) % m;
		a = (a * a) % m;
		b = b>>1LL;
	}
	return ans;
}

/*******RECURSIVE*******/
int pow(int x, int y,int m) {
    if( y == 0) return 1;
    int half = pow(x, y/2, m);
    int full = (half * half) % m;
    return y%2 ? (x * full) % m : full;
}




//******** RECURSIVE FOR MOD=1E18**********/

ulli MM(ulli a,ulli b,ulli m)  //returns (a*b)%c  when a*b>lli_MAX 
{
	if(b==1) return a%m;
	
	ulli tmp=MM(2*a,b/2,m);
	if(b%2==0) 
	return tmp;
	
	else
	return (a%m+tmp%m)%m;		
}

ulli power(ulli x,ulli y,ulli m)
{
	if(y==0) return 1;
	
	ulli tmp=power(x,y/2,m);
	ulli tmp2=MM(tmp,tmp,m);
	
	if(y&1)
	return MM( x, tmp2 , m );
	else
	return tmp2;
}

//IDEA for MM: keep dividing b by 2 and multiply a by 2 for MM

