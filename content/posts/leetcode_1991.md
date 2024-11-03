
+++
authors = ["Crafted by Me"]
title = "Leetcode 1991: Find the Middle Index in Array"
date = "2019-05-22"
description = "In-depth solution and explanation for Leetcode 1991: Find the Middle Index in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-middle-index-in-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; i++)
            sum[i + 1] = nums[i] + sum[i];
        
        int net = sum[n];
        
        for(int i = 0; i < n; i++) {
            if(net - sum[i + 1] == sum[i]) return i;
        }
        return -1;
    }
};
{{< /highlight >}}


---


"| 1992: Find All Groups of Farmland |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

