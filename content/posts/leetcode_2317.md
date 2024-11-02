
+++
authors = ["Crafted by Me"]
title = "Leetcode 2317: Maximum XOR After Operations "
date = "2017-06-29"
description = "Solution to Leetcode 2317"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-after-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        
        int mask = 0;
        
        for(auto it : nums) {
            mask |= it;
        }
        
        return mask;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

