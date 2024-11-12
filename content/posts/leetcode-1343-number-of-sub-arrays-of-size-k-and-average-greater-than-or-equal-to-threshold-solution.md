
+++
authors = ["grid47"]
title = "Leetcode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold"
date = "2024-06-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int cnt = 0, sum = 0;
        th = th * k;
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        cnt += sum >= th;
        for(int i = k; i < arr.size(); i++) {
            sum += arr[i];
            sum -= arr[i - k];
            if(sum >= th) cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1343.md" >}}
---
{{< youtube D8B4tKxMTnY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1344: Angle Between Hands of a Clock](https://grid47.xyz/posts/leetcode-1344-angle-between-hands-of-a-clock-solution/) |
| --- |
