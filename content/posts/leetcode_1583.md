
+++
authors = ["Crafted by Me"]
title = "Leetcode 1583: Count Unhappy Friends"
date = "2020-07-02"
description = "Solution to Leetcode 1583"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-unhappy-friends/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        vector<vector<int>> rnk(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < pref.size(); i++) {
            for(int j = 0; j < pref[i].size(); j++) {
                rnk[i][pref[i][j]] = j;                
            }
        }
        int cnt = 0;
        set<int> items;
        for(int i = 0; i < pairs.size(); i++) {
            for(int j = i + 1; j < pairs.size(); j++) {
                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];
                if((rnk[x][y] > rnk[x][u]) && (rnk[u][x] < rnk[u][v])) {
                    items.insert(x);
                    items.insert(u);
                }
                if((rnk[x][y] > rnk[x][v]) && (rnk[v][x] < rnk[v][u])) {
                    items.insert(x);
                    items.insert(v);
                }
                if((rnk[y][x] > rnk[y][u]) && (rnk[u][y] < rnk[u][v])) {
                    items.insert(y);
                    items.insert(u);
                }
                if((rnk[y][x] > rnk[y][v]) && (rnk[v][y] < rnk[v][u])) {
                    items.insert(y);
                    items.insert(v);
                }
            }
        }
        return items.size();
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

