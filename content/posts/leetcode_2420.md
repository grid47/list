
+++
authors = ["Crafted by Me"]
title = "Leetcode 2420: Find All Good Indices"
date = "2018-03-19"
description = "Solution to Leetcode 2420"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-good-indices/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp1(n + 1, 1), dp2(n + 1, 1), ans;

        for(int i = 1; i < n; i++)
            if(a[i -1] >= a[i]) dp1[i] = dp1[i - 1]+1;
        for(int i = n -2; i > 0; i--)
            if(a[i] <= a[i +1]) dp2[i] = dp2[i +1]+1;

        for(int i = k; i< n-k; i++)
        if(dp1[i-1] >= k && dp2[i+1] >=k)
        ans.push_back(i);

        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

