
+++
authors = ["Crafted by Me"]
title = "Leetcode 3120: Count the Number of Special Characters I"
date = "2016-04-17"
description = "Solution to Leetcode 3120"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-special-characters-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> ch;
        for(char x: word)
                ch.insert(x);
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(ch.count('a' + i) && ch.count('A' + i))
                cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

