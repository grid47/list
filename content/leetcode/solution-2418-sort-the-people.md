
+++
authors = ["grid47"]
title = "Leetcode 2418: Sort the People"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2418: Sort the People in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "Zv_gXqqslbw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/sort-the-people/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> A;
        int N = names.size();
        for(int i = 0; i < N; i++) {
            A.push_back({heights[i], names[i]});
        }

        sort(A.rbegin(), A.rend());

        vector<string> ans;
        for(int i = 0; i < N; i++) {
            ans.push_back(A[i].second);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2418.md" >}}
---
{{< youtube Zv_gXqqslbw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2419: Longest Subarray With Maximum Bitwise AND](https://grid47.xyz/leetcode/solution-2419-longest-subarray-with-maximum-bitwise-and/) |
| --- |
