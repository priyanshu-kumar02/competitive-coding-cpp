    void mergeSort(int ss, int se, vector<int>& nums) {
        if(ss>=se) return; 
        int mid = (ss+se) >> 1;
        mergeSort(ss, mid, nums);
        mergeSort(mid+1, se, nums);
        int l=ss, r=mid+1;
        vector<int> sorted;
        
        while(l<=mid || r<=se) {
            if(l>mid) sorted.push_back(nums[r++]);
            else if(r>se || nums[l]<nums[r]) sorted.push_back(nums[l++]);
            else sorted.push_back(nums[r++]);
        }
        for(int i=ss; i<=se; i++) 
            nums[i]=sorted[i-ss];
    }
