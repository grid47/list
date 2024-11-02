
+++
authors = ["Crafted by Me"]
title = "Leetcode 2255: Count Prefixes of a Given String"
date = "2017-08-30"
description = "Solution to Leetcode 2255"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-prefixes-of-a-given-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(string x: words) {
            if(x.size() > s.size()) continue;
            bool flag = true;
            for(int i = 0; i < x.size(); i++) {
                if(x[i] != s[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

