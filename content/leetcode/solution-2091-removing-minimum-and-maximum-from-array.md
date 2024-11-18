
+++
authors = ["grid47"]
title = "Leetcode 2091: Removing Minimum and Maximum From Array"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2091: Removing Minimum and Maximum From Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "OsaRrf_jDn4"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int xi = 0, ni = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[xi] < nums[i])
                xi = i;
            if(nums[ni] > nums[i])
                ni = i;
        }
        if(xi == ni) return 1;
        int mx = (xi < ni)? ni: xi;
        int mn = (xi < ni)? xi: ni;

        int ans = (mx - 0 + 1);
        
        ans = min(ans, (n - mn));
        
        ans = min(ans, (n - mx) + (mn - 0 + 1));
                
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2091.md" >}}
---
{{< youtube OsaRrf_jDn4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2095: Delete the Middle Node of a Linked List](https://grid47.xyz/leetcode/solution-2095-delete-the-middle-node-of-a-linked-list/) |
| --- |
