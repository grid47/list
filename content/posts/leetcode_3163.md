
+++
authors = ["Yasir"]
title = "Leetcode 3163: String Compression III"
date = "2016-03-02"
description = "Solution to Leetcode 3163"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-compression-iii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string compressedString(string word) {
        
        int i = 0, n = word.size();
        char cur;
        
        string res = "";
        while(i < n) {
            int cnt = 0;
            cur = word[i];
            while(i < n && cnt < 9 && cur == word[i])
                cnt++, i++;
            res += to_string(cnt) + cur;
        }
        return res;
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

