
+++
authors = ["Crafted by Me"]
title = "Leetcode 2483: Minimum Penalty for a Shop"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2483: Minimum Penalty for a Shop in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-penalty-for-a-shop/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int bestClosingTime(string a) {
        int s = a.size();
        vector<int> y,n;
        y.push_back(0);
        n.push_back(0);
        int cnt = 0;
        for (int i = 0; i < s; i++) {
            if(a[i] == 'N') cnt++;
            n.push_back(cnt);
        }
        cnt = 0;
        for (int i = s -1; i >= 0; i--) {
            if(a[i] == 'Y') cnt++;
            y.push_back(cnt);
        }
        
        reverse (y.begin(), y.end());
        int ans = INT_MAX, ind = 0;
        for(int i = 0; i < s +1; i++) {
            int h = n[i] + y[i];
            if(h<ans) {
                ans = h;
                ind = i;
            }
        }
        return ind;        
    }
};
{{< /highlight >}}


---
{{< youtube 0d7ShRoOFVE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2484: Count Palindromic Subsequences](https://grid47.xyz/posts/leetcode_2484) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

