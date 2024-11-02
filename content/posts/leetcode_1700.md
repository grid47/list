
+++
authors = ["Crafted by Me"]
title = "Leetcode 1700: Number of Students Unable to Eat Lunch"
date = "2019-03-08"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

