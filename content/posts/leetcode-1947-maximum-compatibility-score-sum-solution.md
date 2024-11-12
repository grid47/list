
+++
authors = ["grid47"]
title = "Leetcode 1947: Maximum Compatibility Score Sum"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1947: Maximum Compatibility Score Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-compatibility-score-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> pos;
        int ans = 0;
        for(int i = 0; i < students.size(); i++)
            pos.push_back(i);
        do {

            int curr = 0;
            for(int i = 0; i < students.size(); i++)
            for(int j = 0; j < students[pos[i]].size(); j++)
                curr += (students[pos[i]][j] == mentors[i][j]);
            ans = max(ans, curr);

        } while(next_permutation(pos.begin(), pos.end()));
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1947.md" >}}
---
{{< youtube HinLw7adoH8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1952: Three Divisors](https://grid47.xyz/posts/leetcode-1952-three-divisors-solution/) |
| --- |
