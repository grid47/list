
+++
authors = ["Crafted by Me"]
title = "Leetcode 1849: Splitting a String Into Descending Consecutive Values"
date = "2019-10-11"
description = "In-depth solution and explanation for Leetcode 1849: Splitting a String Into Descending Consecutive Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s;
    bool splitString(string s) {
        this->s = s;
        double tmp = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            tmp = tmp * 10 + (s[i] - '0');
            if(bt(i + 1, tmp)) return true;
        }
        return false;
    }
    
    bool bt(int idx, double prv) {

        if(idx == s.size()) return true;
        
        double tmp = 0;
        for(int i = idx; i < s.size(); i++) {
            tmp = tmp * 10 + (s[i] - '0');
            if(tmp - prv > -1) break;
            if(tmp - prv == -1) {
                if(bt(i + 1, tmp))
                    return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}


---
{{< youtube eDtMmysldaw >}}
| Next : [LeetCode #1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number](https://grid47.xyz/posts/leetcode_1850) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

