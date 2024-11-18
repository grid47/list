
+++
authors = ["grid47"]
title = "Leetcode 1887: Reduction Operations to Make the Array Elements Equal"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1887: Reduction Operations to Make the Array Elements Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "1etc9Ip8Xm8"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        int ops = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n - 2; i >= 0; i--) {
            
            if(nums[i] == nums[i + 1]) continue;
            ops += (n - 1 - i);
            
        }
        
        return ops;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1887.md" >}}
---
{{< youtube 1etc9Ip8Xm8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1888: Minimum Number of Flips to Make the Binary String Alternating](https://grid47.xyz/leetcode/solution-1888-minimum-number-of-flips-to-make-the-binary-string-alternating/) |
| --- |
