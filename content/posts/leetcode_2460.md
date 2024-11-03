
+++
authors = ["Crafted by Me"]
title = "Leetcode 2460: Apply Operations to an Array"
date = "2018-02-07"
description = "In-depth solution and explanation for Leetcode 2460: Apply Operations to an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-operations-to-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
vector<int> applyOperations(vector<int>& A) {
    for (int i = 0, j = 0; i < size(A); ++i){
        if (i + 1 < size(A) and A[i] == A[i + 1]){
            A[i] *= 2;
            A[i + 1] = 0;
        }
        if (A[i]) swap(A[j++], A[i]);
    }   
    return A;
}
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2461: Maximum Sum of Distinct Subarrays With Length K](https://grid47.xyz/posts/leetcode_2461) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

