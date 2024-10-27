
+++
authors = ["Yasir"]
title = "Leetcode 835: Image Overlap"
date = "2022-07-16"
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

{{< highlight html >}}
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

