
+++
authors = ["grid47"]
title = "Leetcode 2225: Find Players With Zero or One Losses"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2225: Find Players With Zero or One Losses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2225.md" >}}
---
{{< youtube rHZD8NrMq5s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2226: Maximum Candies Allocated to K Children](https://grid47.xyz/posts/leetcode-2226-maximum-candies-allocated-to-k-children-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
