
+++
authors = ["grid47"]
title = "Leetcode 3163: String Compression III"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3163: String Compression III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3163.md" >}}
---
{{< youtube RWQ8Q_ID23c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #3168: Minimum Number of Chairs in a Waiting Room](https://grid47.xyz/posts/leetcode-3168-minimum-number-of-chairs-in-a-waiting-room-solution/) |
| --- |
