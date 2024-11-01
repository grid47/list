
+++
authors = ["Crafted by Me"]
title = "Leetcode 11: Container With Most Water"
date = "2024-10-22"
description = "Solution to Leetcode 11"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/container-with-most-water/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() -1;
        
        while(i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j])
                i++;
            else j--;
        }
        return res;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/11.md" >}}
- by gpt
        
---
{{< youtube Y_4_or0Sc7I >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

