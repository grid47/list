
+++
authors = ["Crafted by Me"]
title = "Leetcode 719: Find K-th Smallest Pair Distance"
date = "2022-11-13"
description = "Solution to Leetcode 719"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];
        
        for(int cnt = 0; l < r; cnt = 0) {
            int m = l + (r - l) / 2;
            
            for(int i = 0, j = 0; i < n; i++) {
                while(j < n && nums[j] <= nums[i] + m) j++;
                cnt += (j - i - 1);
            }
            
            if(cnt < k) {
                l = m + 1;
            } else r = m;
        }
        
        return l;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/719.md" >}}
---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

