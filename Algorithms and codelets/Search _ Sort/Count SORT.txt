//A[n],Aux[max],Out[n],n->size of array,max->maximum element of array

void counting_sort (lli A[ ],lli Aux[ ] ,lli Out[ ],lli n,lli max) {
         for(lli i = 0 ; i <= max ; i ++ ) 
                Aux[ i ] = 0 ;

    
           for( lli j = 0; j < n ;j++ ) 
                Aux[ A [ j ] ] ++ ;

    lli start=0;
           for(lli i = 0; i <=max ;i++ )       //for descending use: for(lli i = max; i >=0 ;i-- ) 
          {
		  	for(lli j=1;j<=Aux[i];j++)
		  	Out[start++]=i;
		  }
}