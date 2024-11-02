
+++
authors = ["Crafted by Me"]
title = "Leetcode 2009: Minimum Number of Operations to Make Array Continuous"
date = "2018-05-03"
description = "Solution to Leetcode 2009"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int m = 1;
        for(int i = 1; i < n; i++)
            if(nums[i] != nums[i - 1])
                nums[m++] = nums[i];
        
        int j = 0, ans = n;
        
        for(int i = 0; i < m; i++) {
            while(j < m && nums[j] - nums[i] <= n - 1) j++;
            
            ans = min(ans, n - (j - i));
        }
        
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

