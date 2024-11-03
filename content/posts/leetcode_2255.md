
+++
authors = ["Crafted by Me"]
title = "Leetcode 2255: Count Prefixes of a Given String"
date = "2018-08-31"
description = "In-depth solution and explanation for Leetcode 2255: Count Prefixes of a Given String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-prefixes-of-a-given-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(string x: words) {
            if(x.size() > s.size()) continue;
            bool flag = true;
            for(int i = 0; i < x.size(); i++) {
                if(x[i] != s[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2256: Minimum Average Difference](https://grid47.xyz/posts/leetcode_2256) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

