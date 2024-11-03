
+++
authors = ["Crafted by Me"]
title = "Leetcode 2028: Find Missing Observations"
date = "2019-04-15"
description = "In-depth solution and explanation for Leetcode 2028: Find Missing Observations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-missing-observations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<map<int, bool>> memo;
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        
        int sum = 0;
        for(int i = 0; i < m; i++)
            sum += rolls[i];
        
        int net = mean * (m + n);
        
        sum = net - sum;
        
        // create an array of size n with sum = sum and elements 1 - 6
        
        if(sum < n || sum > 6 * n) return vector<int>{};

        int x = sum / n, rem = sum % n;
        vector<int> res(n, x);
        
        for(int i = 0; i < rem; i++) {
            res[i]++;
        }

        return res;
    }
    
};
{{< /highlight >}}


---
{{< youtube 86yKkaNi3sU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2029: Stone Game IX](https://grid47.xyz/posts/leetcode_2029) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

