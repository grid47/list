
+++
authors = ["Crafted by Me"]
title = "Leetcode 2670: Find the Distinct Difference Array"
date = "2017-07-12"
description = "In-depth solution and explanation for Leetcode 2670: Find the Distinct Difference Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-distinct-difference-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        map<int, int> l, r;
        for(int i = 0; i < n; i++) {
            r[nums[i]]++;
        }

        for(int i = 0; i < n; i++) {
            r[nums[i]]--;
            if(r[nums[i]] == 0) r.erase(nums[i]);
            l[nums[i]]++;
            ans[i] = l.size() - r.size();
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube ikDNBcVaq6Y >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2671: Frequency Tracker](https://grid47.xyz/posts/leetcode_2671) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

