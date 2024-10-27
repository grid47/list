
+++
authors = ["Yasir"]
title = "Leetcode 2418: Sort the People"
date = "2018-03-16"
description = "Solution to Leetcode 2418"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-the-people/description/)

---

**Code:**

{{< highlight html >}}
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

