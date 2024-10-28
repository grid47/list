
+++
authors = ["Yasir"]
title = "Leetcode 996: Number of Squareful Arrays"
date = "2022-02-06"
description = "Solution to Leetcode 996"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-squareful-arrays/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        pmt(A, 0, ans);
        return ans;
    }
    void pmt(vector<int> &A, int idx, int& ans) {
        if (idx >= A.size()) {
            ++ans;
        }
        unordered_set<int> seen; 
        for (int i = idx; i < A.size(); ++i) {
            if (seen.find(A[i])!=seen.end()) continue;
            seen.insert(A[i]);
            swap(A[i], A[idx]);
            if ((idx == 0) || (idx > 0 && isSquare(A[idx] + A[idx - 1]))) {
                pmt(A, idx + 1, ans);
            }
            swap(A[i], A[idx]);            
        }
    }
    bool isSquare(int v) {
        int r = sqrt(v);
        return r * r == v;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

