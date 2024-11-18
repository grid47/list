
+++
authors = ["grid47"]
title = "Leetcode 376: Wiggle Subsequence"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 376: Wiggle Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/wiggle-subsequence/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/376.webp" 
    alt="A sequence of numbers gently moving into a wiggle pattern, each step softly highlighted as they align."
    caption="Solution to LeetCode 376: Wiggle Subsequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int wiggleMaxLength(vector<int> nums) {
        if(nums.size() == 0) return 0;
        
        int n = nums.size();
        
        vector<int> up(n, 0);
        vector<int> down(n, 0);        
        
        up[0] = 1;
        down[0] = 1;
        
        for(int i = 1; i < n; i++) {
                 if(nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else if(nums[i] > nums[i - 1]) {            
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];                
            }
            else {
                down[i] = down[i - 1];
                up[i]   =   up[i - 1];                
            }
        }
        
        return max(down[n - 1], up[n - 1]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/376.md" >}}
---
{{< youtube IpWoZvKzpug >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #377: Combination Sum IV](https://grid47.xyz/leetcode/solution-377-combination-sum-iv/) |
| --- |
