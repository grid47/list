
+++
authors = ["Yasir"]
title = "Leetcode 2225: Find Players With Zero or One Losses"
date = "2018-09-26"
description = "Solution to Leetcode 2225"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> u;
        map<int, int> ff;
        int n = matches.size();
        for(int i = 0; i < n; i++) {
            u.insert(matches[i][0]);
            u.insert(matches[i][1]);
            ff[matches[i][1]]++;
        }
        vector<vector<int>> arr(2);
        for(auto it = u.begin(); it != u.end(); it++) {
            if(!ff.count(*it)) arr[0].push_back(*it);
            else if(ff[*it] == 1) arr[1].push_back(*it);
        }
        sort(arr[0].begin(), arr[0].end());
        sort(arr[1].begin(), arr[1].end());
        return arr;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

