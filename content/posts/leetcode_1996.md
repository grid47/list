
+++
authors = ["Yasir"]
title = "Leetcode 1996: The Number of Weak Characters in the Game"
date = "2019-05-13"
description = "Solution to Leetcode 1996"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/)

---

**Code:**

{{< highlight html >}}

class Solution {

    public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        } else return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prpt) {
        sort(prpt.begin(), prpt.end(), comp);
        
        int mn = INT_MIN;
        int ans = 0;
        
        for(int i = prpt.size() - 1; i >= 0; i--) {
            if(prpt[i][1] < mn) ans++;
            mn = max(mn, prpt[i][1]);
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

