
+++
authors = ["grid47"]
title = "Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "uV_JsPPLK9o"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        int sum = 0, lsize = INT_MAX, result = INT_MAX;
        mp[0] = -1;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            mp[sum] = i;
        }
        sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(mp.count(sum - target)) 
            lsize = min(lsize, i - mp[sum-target]);

            if(mp.count(sum + target) && lsize < INT_MAX)
            result = min(result, mp[sum + target] -i +lsize);


        }

        return result == INT_MAX ? -1: result;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1477.md" >}}
---
{{< youtube uV_JsPPLK9o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1480: Running Sum of 1d Array](https://grid47.xyz/leetcode/solution-1480-running-sum-of-1d-array/) |
| --- |
