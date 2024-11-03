
+++
authors = ["Crafted by Me"]
title = "Leetcode 1234: Replace the Substring for Balanced String"
date = "2021-06-17"
description = "In-depth solution and explanation for Leetcode 1234: Replace the Substring for Balanced String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int balancedString(string s) {
        map<char, int> ma;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
        }
        int k = s.size() / 4, j = 0, res = s.size();
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]--;
        while(j < s.size() && ma['Q'] <= k && ma['W'] <= k && ma['E'] <= k && ma['R'] <= k) {
                ma[s[j]]++;
                res = min(res, i - j + 1);
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1234.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1235: Maximum Profit in Job Scheduling](https://grid47.xyz/posts/leetcode_1235) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

