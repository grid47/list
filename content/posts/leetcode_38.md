
+++
authors = ["Crafted by Me"]
title = "Leetcode 38: Count and Say"
date = "2024-09-25"
description = "Solution to Leetcode 38"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-and-say/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string tmp = countAndSay(n-1);
        string ans = "";

        for(int i = 0; i < tmp.size(); ) {

            char ch = tmp[i];
            int cnt = 0;

            while(tmp[i] == ch && i < tmp.size()) {
                cnt++;
                i++;
            }

            ans.push_back(cnt+'0');
            ans.push_back(tmp[i-1]);
        }

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/38.md" >}}
---
{{< youtube 4PFCdoSOsiA >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

