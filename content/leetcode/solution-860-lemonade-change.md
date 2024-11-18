
+++
authors = ["grid47"]
title = "Leetcode 860: Lemonade Change"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 860: Lemonade Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "mSVAw0AUZgA"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/lemonade-change/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int x : bills) {
                 if (x == 5) five++;
            else if (x == 10) {
                     if (five > 0) five--, ten++;
                else return false;
            } else {
                     if (five > 0 && ten > 0) five--, ten--;
                else if (five > 2) five -= 3;
                else return false;
            }
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/860.md" >}}
---
{{< youtube mSVAw0AUZgA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #861: Score After Flipping Matrix](https://grid47.xyz/leetcode/solution-861-score-after-flipping-matrix/) |
| --- |
