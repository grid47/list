
+++
authors = ["Crafted by Me"]
title = "Leetcode 1347: Minimum Number of Steps to Make Two Strings Anagram"
date = "2021-02-23"
description = "Solution to Leetcode 1347"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26, 0);
        for(int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        int step = 0;
        for(int num : count)
            if(num > 0) step += num;
        return step;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

