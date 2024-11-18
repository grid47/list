
+++
authors = ["grid47"]
title = "Leetcode 2012: Sum of Beauty in the Array"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2012: Sum of Beauty in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "pOb_fN_-rzo"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-beauty-in-the-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> left(n), right(n);

        left[0] = make_pair(nums[0], 0);
        for(int i = 1; i < n; i++)
            if(nums[i] >= left[i - 1].first) {
                left[i] = make_pair(nums[i], i);
            } else left[i] = left[i - 1];
        
        right[n-1] = make_pair(nums[n - 1], n - 1);
        for(int i = n - 2; i >= 0; i--)
            if(nums[i] <= right[i + 1].first) {
                right[i] = make_pair(nums[i], i);
            } else right[i] = right[i + 1];
        
        int sum = 0;
        for(int i = 1; i < n - 1; i++) {
            if(left[i - 1].first < nums[i] && right[i + 1].first > nums[i])
                sum += 2;
            else if(nums[i-1] < nums[i] && nums[i + 1] > nums[i])
                sum += 1;
            else sum += 0;
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2012.md" >}}
---
{{< youtube pOb_fN_-rzo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2013: Detect Squares](https://grid47.xyz/leetcode/solution-2013-detect-squares/) |
| --- |
