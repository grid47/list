
+++
authors = ["Yasir"]
title = "Leetcode 686: Repeated String Match"
date = "2022-12-13"
description = "Solution to Leetcode 686"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/repeated-string-match/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        for(int i = 0, j = 0; i < a.size(); i++) {
            for(j = 0; j < b.size() && a[(i + j) % a.size()] == b[j]; j++);
            if(j == b.size())
                return (j + i - 1)/ a.size() + 1;
            
        }
        return -1;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

