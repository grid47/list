
+++
authors = ["Crafted by Me"]
title = "Leetcode 1712: Ways to Split Array Into Three Subarrays"
date = "2020-02-25"
description = "In-depth solution and explanation for Leetcode 1712: Ways to Split Array Into Three Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

