
+++
authors = ["grid47"]
title = "Leetcode 2895: Minimum Processing Time"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2895: Minimum Processing Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-processing-time/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minProcessingTime(vector<int>& t, vector<int>& v) {
        int n=v.size();
        sort(t.begin(),t.end());
        sort(v.begin(),v.end());
        int j=n-1;
        int m=t.size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int c=0;
            while(c<4)
            {
                ans=max(ans,t[i]+v[j]);
                c++;
                j--;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2895.md" >}}
---
{{< youtube Ju6ArOqNhxM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2899: Last Visited Integers](https://grid47.xyz/posts/leetcode-2899-last-visited-integers-solution/) |
| --- |
