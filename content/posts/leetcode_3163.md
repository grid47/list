
+++
authors = ["Crafted by Me"]
title = "Leetcode 3163: String Compression III"
date = "2015-03-06"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

