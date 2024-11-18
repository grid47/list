
+++
authors = ["grid47"]
title = "Leetcode 2293: Min Max Game"
date = "2024-03-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2293: Min Max Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "ZDZ4KQsbnbc"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/min-max-game/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1) return nums[0];  // Base case
        vector<int> newNum(n/2); 
        for(int i=0; i<n/2; i++) { 
            if(i%2==0) newNum[i] = min(nums[2 * i], nums[2 * i + 1]); 
            else newNum[i] = max(nums[2 * i], nums[2 * i + 1]); 
        } 
        int res = minMaxGame(newNum); // Recursive call
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2293.md" >}}
---
{{< youtube ZDZ4KQsbnbc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2295: Replace Elements in an Array](https://grid47.xyz/leetcode/solution-2295-replace-elements-in-an-array/) |
| --- |
