
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2609: Find the Longest Balanced Substring of a Binary String"
date = "2017-09-08"
description = "Solution to Leetcode 2609"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zr = 0, ans = 0;
        int cnt[2] = {};
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                if(cnt[1]) {
                    cnt[0] = 0;
                    cnt[1] = 0;                    
                }
                cnt[0]++;
            } else {
                if(cnt[1] < cnt[0]) cnt[1]++;
                else {
                    cnt[0] = 0;
                    cnt[1] = 0;
                }
                ans = max(cnt[1] * 2, ans);
            }
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
