
+++
authors = ["Crafted by Me"]
title = "Leetcode 970: Powerful Integers"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 970: Powerful Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/powerful-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i = 1; i <= bound; i *= x) {
            for(int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/970.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #971: Flip Binary Tree To Match Preorder Traversal](https://grid47.xyz/posts/leetcode_971) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

