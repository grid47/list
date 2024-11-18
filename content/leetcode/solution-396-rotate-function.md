
+++
authors = ["grid47"]
title = "Leetcode 396: Rotate Function"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 396: Rotate Function in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "GzBK8dxblaw"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/396.webp"
+++



[`Problem Link`](https://leetcode.com/problems/rotate-function/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/396.webp" 
    alt="A glowing array where elements rotate, with each rotation step softly highlighted."
    caption="Solution to LeetCode 396: Rotate Function Problem"
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
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0, fn = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            fn += i * nums[i];
        }

        long l = 1, r;
        long newfn = fn;

        while(l < n) {
            r = l + n - 1;
            long removed = (l - 1) *nums[l -1];
            long added = r * nums[r % n];

            newfn = newfn - removed + added - sum;

            fn = max(fn, newfn);
            l++;
        }
        return fn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/396.md" >}}
---
{{< youtube GzBK8dxblaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #397: Integer Replacement](https://grid47.xyz/leetcode/solution-397-integer-replacement/) |
| --- |
