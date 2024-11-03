
+++
authors = ["Crafted by Me"]
title = "Leetcode 2606: Find the Substring With Maximum Cost"
date = "2017-09-14"
description = "In-depth solution and explanation for Leetcode 2606: Find the Substring With Maximum Cost in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char, int> mp;
        for(int i = 0; i < chars.size(); i++) {
            mp[chars[i]] = vals[i];
        }
        for(int i = 0; i < 26; i++) {
            char x = 'a' + i;
            if(mp.count(x)) continue;
            mp[x] = i + 1;
        }
        
        int lmax = 0, gmax = 0;
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] < lmax + mp[s[i]]) {
                lmax = lmax + mp[s[i]];
            } else lmax = mp[s[i]];
            
            gmax = max(gmax, lmax);
        }
        return gmax;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2607: Make K-Subarray Sums Equal](https://grid47.xyz/posts/leetcode_2607) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

