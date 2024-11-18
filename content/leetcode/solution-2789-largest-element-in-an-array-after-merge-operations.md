
+++
authors = ["grid47"]
title = "Leetcode 2789: Largest Element in an Array after Merge Operations"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2789: Largest Element in an Array after Merge Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wbXDrozEtOs"
youtube_upload_date="2023-07-23"
youtube_thumbnail="https://i.ytimg.com/vi/wbXDrozEtOs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxArrayValue(vector<int>& in) {

        int n = in.size();        
        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
            nums[i] = in[i];

        long long res = nums[n - 1];
        
        for(int i = n - 1; i >= 0; i--) {
            res = max(res, (long long)nums[i]);
            if(i > 0 && nums[i] >= nums[i - 1]) {
                nums[i - 1] += nums[i];
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2789.md" >}}
---
{{< youtube wbXDrozEtOs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2798: Number of Employees Who Met the Target](https://grid47.xyz/leetcode/solution-2798-number-of-employees-who-met-the-target/) |
| --- |
