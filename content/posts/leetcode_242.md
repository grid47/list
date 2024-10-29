
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 242: Valid Anagram"
date = "2024-03-02"
description = "Solution to Leetcode 242"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-anagram/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ch(26, 0);
        for(char x: s) ch[x - 'a']++;
        for(char x: t) ch[x - 'a']--;
        for(int x: ch) if(x != 0) return false;
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/242.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

