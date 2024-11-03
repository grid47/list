
+++
authors = ["Crafted by Me"]
title = "Leetcode 2511: Maximum Enemy Forts That Can Be Captured"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2511: Maximum Enemy Forts That Can Be Captured in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
int captureForts(vector<int>& forts) {
    int res = 0;
    for (int i = 0, j = 0; i < forts.size(); ++i)
        if (forts[i] != 0) {
            if (forts[j] == -forts[i])
                res = max(res, i - j - 1);
            j = i;
        }
    return res;
}
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2512: Reward Top K Students](https://grid47.xyz/posts/leetcode_2512) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

