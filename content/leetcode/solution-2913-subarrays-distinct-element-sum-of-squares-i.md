
+++
authors = ["grid47"]
title = "Leetcode 2913: Subarrays Distinct Element Sum of Squares I"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2913: Subarrays Distinct Element Sum of Squares I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vBSxcFdwcQU"
youtube_upload_date="2023-10-28"
youtube_thumbnail="https://i.ytimg.com/vi/vBSxcFdwcQU/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumCounts(vector<int>& ar) {
        int n=ar.size();
        int ans=0;
        map<int,int>fr;
        //sort(ar.begin(),ar.end());
        for(int i=0;i<n;i++){
            int val=0;
             map<int,int>fr;
            for(int j=i;j<n;j++){
                if(fr[ar[j]]==0) val++;
                fr[ar[j]]++;
                ans=ans+val*val;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2913.md" >}}
---
{{< youtube vBSxcFdwcQU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2914: Minimum Number of Changes to Make Binary String Beautiful](https://grid47.xyz/leetcode/solution-2914-minimum-number-of-changes-to-make-binary-string-beautiful/) |
| --- |
