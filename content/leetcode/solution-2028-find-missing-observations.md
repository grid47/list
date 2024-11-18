
+++
authors = ["grid47"]
title = "Leetcode 2028: Find Missing Observations"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2028: Find Missing Observations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "86yKkaNi3sU"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2028.md" >}}
---
{{< youtube 86yKkaNi3sU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2029: Stone Game IX](https://grid47.xyz/leetcode/solution-2029-stone-game-ix/) |
| --- |
