lli binarySearch(lli A[], lli left, lli right, lli item) {
    lli mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (A[mid] >= item) 
            right = mid;
        else
            left = mid;
    }
    cout<<left<<","<<right<<endl;
    
    if(A[right]<item)
    return right;
    else if(A[left]<item)
    return left;
    else 
    return -1;
}
