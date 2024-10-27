
+++
authors = ["Yasir"]
title = "Leetcode 2856: Minimum Array Length After Pair Removals"
date = "2017-01-02"
description = "Solution to Leetcode 2856"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-array-length-after-pair-removals/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        if(maxi <= n/2){
            if(n%2){
                return 1;
            }
            else{
                return 0;
            }
        }
        return 2*maxi - n;
        
        
    }
};
{{< /highlight >}}

