
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 835: Image Overlap"
date = "2022-07-17"
description = "Solution to Leetcode 835"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/image-overlap/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> la, lb;
        int n = img1.size();
        for(int i = 0; i < n*n; i++)
            if(img1[i/n][i%n] == 1)
            la.push_back(i/n*100+ i%n);
        for(int i = 0; i < n*n; i++)
            if(img2[i/n][i%n] == 1)
            lb.push_back(i/n*100+ i%n);
        unordered_map<int, int> mp;
        for(int i : la)
        for(int j : lb)
            mp[i-j]++;
        int res = 0;
        for(auto it: mp)
        res = max(res, it.second);
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

