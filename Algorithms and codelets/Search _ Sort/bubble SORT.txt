 void bubble_sort( lli A[ ], lli n ) {
      lli temp;
      for(lli k = 0; k< n-1; k++) {
           // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

           for(lli i = 0; i < n-k-1; i++) {
                     
		       if(A[ i ] > A[ i+1] ) 
                       swap(A[i],A[i+1]);
                   
           }
     }
 }