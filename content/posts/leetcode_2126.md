
+++
authors = ["Yasir"]
title = "Leetcode 2126: Destroying Asteroids"
date = "2019-01-02"
description = "Solution to Leetcode 2126"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/destroying-asteroids/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        int n = ast.size();
        long long mss = mass;
        for(int i = 0;i < n; i++) {
            if(mss >= ast[i])
                mss += ast[i];
            else return false;
        }
        return true;
    }
};
{{< /highlight >}}

