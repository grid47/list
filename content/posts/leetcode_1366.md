
+++
authors = ["Crafted by Me"]
title = "Leetcode 1366: Rank Teams by Votes"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1366: Rank Teams by Votes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rank-teams-by-votes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> count(26, vector<int> (27));
        for(char &c: votes[0])
        count[c - 'A'][26] = c;

        for(string& vote: votes)
        for(int i =0; i < vote.size(); i++)
        --count[vote[i] - 'A'][i];
        
        sort(count.begin(), count.end());
        string res;
        for(int i = 0; i < votes[0].length(); i++)
            res += count[i][26];
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1366.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1367: Linked List in Binary Tree](https://grid47.xyz/posts/leetcode_1367) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

