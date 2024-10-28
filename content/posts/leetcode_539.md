
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 539: Minimum Time Difference"
date = "2023-05-09"
description = "Solution to Leetcode 539"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-difference/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMinDifference(vector<string>& time) {
        
        sort(time.begin(), time.end());
        
        int n = time.size(), mindiff = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            
            int diff = abs(timeDiff(time[(i - 1 +n)%n], time[i]));
            
            diff = min(diff, 1440 - diff); // 1440 = 24h in minutes
            mindiff = min(mindiff, diff);
        }
        
        return mindiff;
    }
    
    int timeDiff(string t1, string t2) {
        // cout << t1 << t2;
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

