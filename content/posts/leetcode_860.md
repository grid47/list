
+++
authors = ["Crafted by Me"]
title = "Leetcode 860: Lemonade Change"
date = "2022-06-26"
description = "In-depth solution and explanation for Leetcode 860: Lemonade Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

