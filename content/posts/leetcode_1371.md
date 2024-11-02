
+++
authors = ["Crafted by Me"]
title = "Leetcode 1371: Find the Longest Substring Containing Vowels in Even Counts"
date = "2020-01-31"
description = "Solution to Leetcode 1371"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char, int> id = {
            {'a' , 1},
            {'e' , 2},
            {'i' , 3},
            {'o' , 4},
            {'u' , 5},
            };
        int res = 0, msk = 0;
        map<int, int> mp;
 
        mp[0] = -1;
        for (int i = 0; i < s.length(); i++) {
            int x = id[s[i]];
            
            if(x != 0)
            msk ^= (1 << x);
            if(mp.count(msk)) {
            res = max(res, i - mp[msk]);
                }
            else {
            mp[msk] = i;}
        }
        
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

