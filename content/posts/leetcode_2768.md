
+++
authors = ["Crafted by Me"]
title = "Leetcode 2768: Number of Black Blocks"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2768: Number of Black Blocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-black-blocks/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> cnt;
        vector<long long> res = {(n - 1L) * (m - 1), 0, 0, 0, 0};
        for (auto& c: coordinates)
            for (int i = c[0]; i < c[0] + 2; ++i)
                for (int j = c[1]; j < c[1] + 2; ++j)
                    if (0 < i && i < m && 0 < j && j < n) {
                        res[cnt[i * 100000L + j]]--;
                        cnt[i * 100000L + j]++;
                        res[cnt[i * 100000L + j]]++;
                    }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube qnbzbMmLK8Q >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2769: Find the Maximum Achievable Number](https://grid47.xyz/posts/leetcode_2769) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

