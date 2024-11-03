
+++
authors = ["Crafted by Me"]
title = "Leetcode 781: Rabbits in Forest"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 781: Rabbits in Forest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Hash Table","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rabbits-in-forest/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for(int i: answers)
        c[i]++;
        int res = 0;
        for(auto i : c) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/781.md" >}}
---
{{< youtube leiSa1i-QrI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #782: Transform to Chessboard](https://grid47.xyz/posts/leetcode_782) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

