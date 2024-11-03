
+++
authors = ["Crafted by Me"]
title = "Leetcode 2558: Take Gifts From the Richest Pile"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2558: Take Gifts From the Richest Pile in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
  long long pickGifts(vector<int>& g, int k) {
    make_heap(g.begin(), g.end());
    while(k--) {
        pop_heap(begin(g), end(g));
        g.back() = sqrt(g.back());
        push_heap(begin(g), end(g));
    }
    return accumulate(begin(g), end(g), 0LL);
  }
};
{{< /highlight >}}


---
{{< youtube _Nh-PvC1Wkg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2559: Count Vowel Strings in Ranges](https://grid47.xyz/posts/leetcode_2559) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

