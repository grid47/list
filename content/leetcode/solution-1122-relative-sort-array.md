
+++
authors = ["grid47"]
title = "Leetcode 1122: Relative Sort Array"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1122: Relative Sort Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting Sort"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "OPvcR1e4lfg"
youtube_upload_date="2024-06-11"
youtube_thumbnail="https://i.ytimg.com/vi/OPvcR1e4lfg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/relative-sort-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(), n2=arr2.size();
        int a2i[1001];

        fill(a2i, end(a2i), n2);
        for(int i=0; i<n2; i++)
            a2i[arr2[i]]=i;

        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if (a2i[x]==a2i[y]) return x<y;
            return a2i[x]<a2i[y];
        });
        return arr1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1122.md" >}}
---
{{< youtube OPvcR1e4lfg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1123: Lowest Common Ancestor of Deepest Leaves](https://grid47.xyz/leetcode/solution-1123-lowest-common-ancestor-of-deepest-leaves/) |
| --- |
