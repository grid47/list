
+++
authors = ["Crafted by Me"]
title = "Leetcode 1712: Ways to Split Array Into Three Subarrays"
date = "2020-02-24"
description = "Solution to Leetcode 1712"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1000000007;
public:
    int waysToSplit(vector<int>& nums) {
        
        int n = nums.size(), res=0;

        partial_sum(nums.begin(), nums.end(), nums.begin());
        
        for(int i = 0, j = 0, k = 0; i < n - 2; i++) {

            j = max(i + 1, j);
            while(j < n - 1 && 2 * nums[i] > nums[j]) j++;

            k = max(j, k);
            while(k < n - 1 && nums[k] - nums[i] <= nums[n - 1] - nums[k]) k++;

            res = (res + (k - j)) % mod;
        }
        return res;            
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

