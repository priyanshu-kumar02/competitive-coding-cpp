lli binarySearch(lli A[], lli left, lli right, lli item) {
    lli mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (A[mid] <= item) 
            left = mid;
        else
            right = mid;
    }
    cout<<left<<","<<right<<endl;
    
    //now we are just left with elements {arr[left],arr[right]},either answer is in this set or DNE
    if(A[left]>item)
    return left;
    else if(A[right]>item)
    return right;
    else 
    return -1;
}
