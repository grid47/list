
+++
authors = ["Crafted by Me"]
title = "Leetcode 1737: Change Minimum Characters to Satisfy One of Three Conditions"
date = "2020-01-31"
description = "In-depth solution and explanation for Leetcode 1737: Change Minimum Characters to Satisfy One of Three Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> ca(26, 0), cb(26, 0);
        for(int i = 0; i < m; i++) {
            ca[a[i] - 'a']++; }
        for(int j = 0; j < n; j++) {
            cb[b[j] - 'a']++; }
        
        int res = m + n;
        for(int i = 0; i < 26; i++) {
            res = min(res, m + n - ca[i] - cb[i]);
            if(i > 0) {

         ca[i] += ca[i - 1];
         cb[i] += cb[i - 1];
                }
            if(i < 25) {
res = min(res, m - ca[i] + cb[i]);
res = min(res, n - cb[i] + ca[i]);

            }
            
            }
        return res;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #1738: Find Kth Largest XOR Coordinate Value](https://grid47.xyz/posts/leetcode_1738) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

