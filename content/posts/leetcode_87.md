
+++
authors = ["Crafted by Me"]
title = "Leetcode 87: Scramble String"
date = "2023-08-07"
description = "Solution to Leetcode 87"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/scramble-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<pair<string, string>, bool> m;
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
            
        if (m.count(make_pair(s1, s2))) {
            return m[make_pair(s1, s2)];
        }

        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
        
        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        m[make_pair(s1, s2)] = false;
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/87.md" >}}
---
{{< youtube 0ugQof_dTOU >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

