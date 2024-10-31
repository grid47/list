
+++
authors = ["Crafted by Me"]
title = "Leetcode 1750: Minimum Length of String After Deleting Similar Ends"
date = "2020-01-17"
description = "Solution to Leetcode 1750"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumLength(string s) {
        vector<int> pre(3, 0), suf(3, 0);
        
        int i = 0, j = s.size() - 1, len = s.size();
        while(i < j && s[i] == s[j]) {
            char c = s[i];
            while(i < j && s[i] == c) i++;
            while(i < j && s[j] == c) j--;

            len = min(len, j == i? s[i-1]!=s[j]: (j - i + 1));
        }
        return len;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

