    void quickSort(int ss, int se, vector<int>& nums) {
        if(ss>=se) return;
        int idx=ss+1;
        
        for(int i=ss+1; i<=se; i++) 
            if(nums[i]<nums[ss]) 
                swap(nums[i], nums[idx++]);
        idx--;
        swap(nums[ss], nums[idx]);
        quickSort(ss, idx-1, nums);
        quickSort(idx+1, se, nums);
    }
