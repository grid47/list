
+++
authors = ["Yasir"]
title = "Leetcode 2653: Sliding Subarray Beauty"
date = "2017-07-24"
description = "Solution to Leetcode 2653"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sliding-subarray-beauty/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    vector<int> cnt;
    
    int no(int x) {
        int sum = 0;
        for(int i = 0; i <= 50; i++) {
            sum += cnt[i];
            if(sum >= x)
                return i - 50;
        }
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        cnt.resize(101, 0);
        
        vector<int> ans;
        
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            cnt[nums[i] + 50]++;            
        }
        ans.push_back(no(x));

        for(int i = k; i < n; i++) {
            cnt[nums[i] + 50]++;
            cnt[nums[i - k] + 50]--;
            
            ans.push_back(no(x));
        }
        
        return ans;
    }
};
{{< /highlight >}}

