
+++
authors = ["Crafted by Me"]
title = "Leetcode 2904: Shortest and Lexicographically Smallest Beautiful String"
date = "2016-11-20"
description = "Solution to Leetcode 2904"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        string ans = "";
        int j = 0, cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') cnt++;

            while( j < n && cnt == k )
            {
                string tmp = s.substr(j, i - j + 1);

                if(ans.size()==0 || tmp.size() < ans.size()) ans = tmp;
                else if(tmp.size() == ans.size()) ans = min(ans, tmp);

                if(s[j] == '1') cnt--;

                j++;
            }
        }

        return ans;        
        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

