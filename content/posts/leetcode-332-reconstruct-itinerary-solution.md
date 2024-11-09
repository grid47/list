
+++
authors = ["grid47"]
title = "Leetcode 332: Reconstruct Itinerary"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 332: Reconstruct Itinerary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Graph","Eulerian Circuit"]
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
---
{{< youtube ZyB_gQ8vqGA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #338: Counting Bits](https://grid47.xyz/posts/leetcode-332-reconstruct-itinerary-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
