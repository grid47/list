
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1122: Relative Sort Array"
date = "2021-10-04"
description = "Solution to Leetcode 1122"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
