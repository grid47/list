
+++
authors = ["grid47"]
title = "Leetcode 1366: Rank Teams by Votes"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1366: Rank Teams by Votes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1367: Linked List in Binary Tree](https://grid47.xyz/leetcode/solution-1367-linked-list-in-binary-tree/) |
| --- |
