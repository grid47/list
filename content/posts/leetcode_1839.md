
+++
authors = ["Crafted by Me"]
title = "Leetcode 1839: Longest Substring Of All Vowels in Order"
date = "2019-10-20"
description = "Solution to Leetcode 1839"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestBeautifulSubstring(string s) {
        map<char, int> idx;
        idx['a'] = 0;
        idx['e'] = 1;
        idx['i'] = 2;
        idx['o'] = 3;
        idx['u'] = 4;
        
        int j = 0, res = 0, n = s.size();
        int id = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                if(id != 0) {                 
                    j = i;
                }
                id = 0;
            }else if((idx[s[i]] < id) || (idx[s[i]] - id > 1)) {
                id = -1;
                j = i;
            } else if(idx[s[i]] - id == 1) {
                id = idx[s[i]];
                
            }
            
            if(id == 4) {
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

