
+++
authors = ["Crafted by Me"]
title = "Leetcode 2178: Maximum Split of Positive Even Integers"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2178: Maximum Split of Positive Even Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> ans;
    vector<long long> maximumEvenSplit(long long sum) {
        vector<long long> tmp;
        if(sum % 2 == 1) return ans;
        
        int cur = 2;
        while(sum >= cur) {
            ans.push_back(cur);
            sum -= cur;
            cur += 2;
        }
        if(sum > 0) ans[ans.size() - 1] += sum;
        
        return ans;
    }
    
};
{{< /highlight >}}


---
{{< youtube fM7MJFhrm-8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2179: Count Good Triplets in an Array](https://grid47.xyz/posts/leetcode_2179) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

