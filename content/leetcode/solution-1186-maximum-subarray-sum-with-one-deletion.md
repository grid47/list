
+++
authors = ["grid47"]
title = "Leetcode 1186: Maximum Subarray Sum with One Deletion"
date = "2024-07-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1186: Maximum Subarray Sum with One Deletion in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EWCdm1cKtrA"
youtube_upload_date="2024-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/EWCdm1cKtrA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = 0, n = arr.size();
        int curr_mx = arr[0], overall_mx = arr[0];
        vector<int> f(n), b(n);
        f[0] = arr[0];
        for(int i = 1; i < n; i++) {
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(curr_mx, overall_mx);
            f[i] = curr_mx;
        }
        
        curr_mx = overall_mx = b[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(overall_mx, curr_mx);
            b[i] = curr_mx;
        }
        
        res = overall_mx;
        for(int i = 1; i < n-1; i++) {
            res = max(res, f[i-1]+b[i+1]);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1186.md" >}}
---
{{< youtube EWCdm1cKtrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1190: Reverse Substrings Between Each Pair of Parentheses](https://grid47.xyz/leetcode/solution-1190-reverse-substrings-between-each-pair-of-parentheses/) |
| --- |