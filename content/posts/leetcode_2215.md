
+++
authors = ["Crafted by Me"]
title = "Leetcode 2215: Find the Difference of Two Arrays"
date = "2017-10-09"
description = "Solution to Leetcode 2215"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> s1, s2;
        for(int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            s2.insert(nums2[i]);
        }
        for(int x: s1) {
            if(!s2.count(x))
                ans[0].push_back(x);
        }
        for(int x: s2) {
            if(!s1.count(x))
                ans[1].push_back(x);
        }        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube oypp_RzI69w >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

