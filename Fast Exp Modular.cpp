
//*******RECURSIVE*******

lli power(lli x, lli y,lli m)
{
    lli temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2,m);
    if (y%2 == 0)
        return (temp%m*temp%m)%m;
    else
        return (x%m*temp%m*temp%m)%m;
}


//convert b into binary form to understand this
//complex: log(b)


//*********ITERATIVE*******/ when m=1e9+7
lli exp(lli a,lli b,lli m)
{
 lli ans=1;
 
	while (b>0)
	{
		if(b&1)
		ans=(ans*a)%m;
		
		a=(a*a)%m;
		b=b>>1;
	}
	
	return ans;
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
