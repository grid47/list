
+++
authors = ["Crafted by Me"]
title = "Leetcode 1662: Check If Two String Arrays are Equivalent"
date = "2020-04-15"
description = "In-depth solution and explanation for Leetcode 1662: Check If Two String Arrays are Equivalent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto x:word1)
            a += x;
        for(auto x:word2)
            b += x;
       
        if(a == b)
            return 1;
        
        return 0;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #1663: Smallest String With A Given Numeric Value](https://grid47.xyz/posts/leetcode_1663) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

