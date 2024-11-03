
+++
authors = ["Crafted by Me"]
title = "Leetcode 2418: Sort the People"
date = "2018-03-21"
description = "In-depth solution and explanation for Leetcode 2418: Sort the People in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


"| 2419: Longest Subarray With Maximum Bitwise AND |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

