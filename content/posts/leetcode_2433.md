
+++
authors = ["Crafted by Me"]
title = "Leetcode 2433: Find The Original Array of Prefix Xor"
date = "2018-03-06"
description = "In-depth solution and explanation for Leetcode 2433: Find The Original Array of Prefix Xor in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size());
        res[0] = pref[0];
        for(int i = 1; i < pref.size(); i++)
            res[i] = pref[i] ^ pref[i - 1];
        
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube idcT-p_DDrI >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

