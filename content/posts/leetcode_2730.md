
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2730: Find the Longest Semi-Repetitive Substring"
date = "2017-05-09"
description = "Solution to Leetcode 2730"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        vector<int> sem(10, 0);
        int cnt = 0;
        
        int j = 0, len = 1;        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
                sem[s[i] - '0']++;
            }
            while(cnt > 1 && j < i) {
                if(s[j] == s[j + 1]) {
                    sem[s[j] - '0']--;
                    cnt--;
                }
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

