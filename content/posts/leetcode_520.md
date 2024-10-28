
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 520: Detect Capital"
date = "2023-05-28"
description = "Solution to Leetcode 520"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/detect-capital/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.size(); i++) {
            if(isupper(word[1]) != isupper(word[i]) ||
              islower(word[0]) && isupper(word[i])) 
                return false;
        }
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

