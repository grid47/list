
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1124: Longest Well-Performing Interval"
date = "2021-10-01"
description = "Solution to Leetcode 1124"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-well-performing-interval/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        
        int n = hours.size(), res = 0, score = 0;
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            
            score += (hours[i] > 8) ? 1 : -1;
            
            if(score > 0)res = i + 1;
            else {

                if  (!mp.count(score))    mp[score] = i;
                if  (mp.count(score - 1)) res = max(res, i - mp[score -1]);

            }
        
        }
        
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

