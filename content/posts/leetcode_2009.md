
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2009: Minimum Number of Operations to Make Array Continuous"
date = "2019-05-02"
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
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

