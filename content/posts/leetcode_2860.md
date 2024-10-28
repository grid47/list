
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2860: Happy Students"
date = "2016-12-30"
description = "Solution to Leetcode 2860"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/happy-students/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0, n = nums.size();
        int selected = 0;
        if(nums[0]!=0) ans = 1; // Not Selecting AnyOne
        for(int i=0;i<n;i++) {
            selected++;
            if(selected>nums[i]) {  // No. of Selected Students is strictly greater than nums[i].
                if(i+1<n && selected<nums[i+1]) // Considering from (i+1) to n Students is not Selected.
                    ans++; 
                else if(i+1==n) ans++;  // Last Student
            }
        }
        return ans;
    }

};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

