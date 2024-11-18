
+++
authors = ["grid47"]
title = "Leetcode 1700: Number of Students Unable to Eat Lunch"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1700: Number of Students Unable to Eat Lunch in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Queue","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "d_cvtFwnOZg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countStudents(vector<int>& A, vector<int>& B) {
        int count[] = {0, 0}, n = A.size(), k;
        for (int a : A)
            count[a]++;
        for (k = 0; k < n && count[B[k]] > 0; ++k)
            count[B[k]]--;
        return n - k;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1700.md" >}}
---
{{< youtube d_cvtFwnOZg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1701: Average Waiting Time](https://grid47.xyz/leetcode/solution-1701-average-waiting-time/) |
| --- |
