
+++
authors = ["Crafted by Me"]
title = "Leetcode 1869: Longer Contiguous Segments of Ones than Zeros"
date = "2019-09-21"
description = "In-depth solution and explanation for Leetcode 1869: Longer Contiguous Segments of Ones than Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkZeroOnes(string s) {
        int z = 0, o = 0, gz = 0, oz = 0, res = 1;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') z++;
            else z = 0;
            if(s[i] == '1') o++;
            else o = 0;
            gz = max(gz, z);
            oz = max(oz, o);
        }
        return oz > gz;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

