
+++
authors = ["grid47"]
title = "Leetcode 2815: Max Pair Sum in an Array"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2815: Max Pair Sum in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-pair-sum-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        vector<vector<int>> ids(10);
        
        for(int x: nums) {
            int val = x;
            int f = x % 10;
            while(x > 0) {
                f = max(f, x % 10);
                x /= 10;
            }
            ids[f].push_back(val);            
        }
        int ans = -1;
        for(int i = 0; i < ids.size(); i++) {
            sort(ids[i].begin(), ids[i].end());
            int n = ids[i].size();
            if(ids[i].size() >= 2) {
                // cout << ids[i][n - 1] << " " << ids[i][n - 2] << " "<< ids[i][n - 1] + ids[i][n - 2] << "\n";
                ans = max(ans, ids[i][n - 1] + ids[i][n - 2]);
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2815.md" >}}
---
{{< youtube DUrmIZhrj4o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2816: Double a Number Represented as a Linked List](https://grid47.xyz/leetcode/solution-2816-double-a-number-represented-as-a-linked-list/) |
| --- |
