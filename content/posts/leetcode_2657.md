
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2657: Find the Prefix Common Array of Two Arrays"
date = "2017-07-23"
description = "Solution to Leetcode 2657"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> a, b, c;
        int n = A.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            if(a.count(B[i])) {
                c.insert(B[i]);
            } 
            if(b.count(A[i])) {
                c.insert(A[i]);                
            } 
            if(A[i] == B[i]) {
                c.insert(A[i]);                
            }
            a.insert(A[i]);
            b.insert(B[i]);
            ans[i] = c.size();
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

