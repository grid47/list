
+++
authors = ["grid47"]
title = "Leetcode 2558: Take Gifts From the Richest Pile"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2558: Take Gifts From the Richest Pile in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "_Nh-PvC1Wkg"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2558.md" >}}
---
{{< youtube _Nh-PvC1Wkg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2559: Count Vowel Strings in Ranges](https://grid47.xyz/leetcode/solution-2559-count-vowel-strings-in-ranges/) |
| --- |
