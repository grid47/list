
+++
authors = ["Crafted by Me"]
title = "Leetcode 1734: Decode XORed Permutation"
date = "2020-02-03"
description = "In-depth solution and explanation for Leetcode 1734: Decode XORed Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-xored-permutation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> decode(vector<int>& enc) {
        int n = enc.size() + 1;
        vector<int> ans(n, 0);
        
        int x = 0;
        for(int i = 1; i < n + 1; i++)
            x ^= i;
        
        ans[0] = x;
        for(int i = 1; i < enc.size(); i += 2)
            ans[0] ^= enc[i];
        
        for(int i = 1; i < n; i++)
            ans[i] = ans[i - 1] ^ enc[i - 1];
        
        return ans;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1735: Count Ways to Make Array With Product](https://grid47.xyz/posts/leetcode_1735) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

