
+++
authors = ["Crafted by Me"]
title = "Leetcode 2778: Sum of Squares of Special Elements "
date = "2017-03-26"
description = "Solution to Leetcode 2778"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-squares-of-special-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            if(n % (i + 1) == 0) ans += nums[i] * nums[i];
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

