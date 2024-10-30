
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1366: Rank Teams by Votes"
date = "2021-02-03"
description = "Solution to Leetcode 1366"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rank-teams-by-votes/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

