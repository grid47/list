
+++
authors = ["Crafted by Me"]
title = "Leetcode 2171: Removing Minimum Number of Magic Beans"
date = "2018-11-23"
description = "In-depth solution and explanation for Leetcode 2171: Removing Minimum Number of Magic Beans in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long sum = accumulate(begin(beans), end(beans), 0L);
        sort(beans.begin(), beans.end());
        long long res = LLONG_MAX;
        for (int i = 0; i < n; i++)
            res = min(res, sum - (long long) (n - i) * beans[i]);
        
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2172: Maximum AND Sum of Array](https://grid47.xyz/posts/leetcode_2172) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

