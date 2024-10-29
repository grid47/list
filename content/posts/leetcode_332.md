
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 332: Reconstruct Itinerary"
date = "2023-12-03"
description = "Solution to Leetcode 332"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reconstruct-itinerary/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<string, priority_queue<string, vector<string>, greater<string>>> gph;
    list<string> res;
    vector<string> findItinerary(vector<vector<string>>& tcks) {

        gph.clear();
        for(auto it: tcks) {
            gph[it[0]].push(it[1]);
        }
        dfs("JFK");

        vector<string> ans;
        for(auto it: res)
            ans.push_back(it);
        return ans;
    }
    
    void dfs(string from) {

        while(gph.count(from) && !gph[from].empty()) {
            string x = gph[from].top();
            gph[from].pop();
            dfs(x);
        }
        res.push_front(from);        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/332.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

