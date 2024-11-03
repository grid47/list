
+++
authors = ["Crafted by Me"]
title = "Leetcode 393: UTF-8 Validation"
date = "2023-10-06"
description = "In-depth solution and explanation for Leetcode 393: UTF-8 Validation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/utf-8-validation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for(auto c : data) {
            if(count == 0) {
                if((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if (c >> 7) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/393.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

