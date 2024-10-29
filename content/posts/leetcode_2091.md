
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2091: Removing Minimum and Maximum From Array"
date = "2019-02-08"
description = "Solution to Leetcode 2091"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int xi = 0, ni = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[xi] < nums[i])
                xi = i;
            if(nums[ni] > nums[i])
                ni = i;
        }
        if(xi == ni) return 1;
        int mx = (xi < ni)? ni: xi;
        int mn = (xi < ni)? xi: ni;

        int ans = (mx - 0 + 1);
        
        ans = min(ans, (n - mn));
        
        ans = min(ans, (n - mx) + (mn - 0 + 1));
                
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

