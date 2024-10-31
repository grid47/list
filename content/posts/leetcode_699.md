
+++
authors = ["Crafted by Me"]
title = "Leetcode 699: Falling Squares"
date = "2022-12-03"
description = "Solution to Leetcode 699"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/falling-squares/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        vector<vector<int>> past;
        vector<int> ans;
        int h = 0;  
        for(vector<int> i: pos) {
            vector<int> cur = {i[0], i[0] + i[1] - 1, i[1]};
            int res = search(past, cur);
            h = max(h, res);
            ans.push_back(h);
        }
        return ans;
    }
    int search(vector<vector<int>> &past, vector<int> &cur) {
        int mx = 0;
        for(auto i: past) {
            if(cur[1] < i[0] || cur[0] > i[1]) continue;
            mx = max(mx, i[2]);
        }
        cur[2] += mx;
        past.push_back(cur);
        return cur[2];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/699.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

