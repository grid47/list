
+++
authors = ["Yasir"]
title = "Leetcode 1700: Number of Students Unable to Eat Lunch"
date = "2020-03-03"
description = "Solution to Leetcode 1700"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)

---

**Code:**

{{< highlight html >}}
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

