
+++
authors = ["grid47"]
title = "Leetcode 636: Exclusive Time of Functions"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 636: Exclusive Time of Functions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/exclusive-time-of-functions/description/)

---
**Code:**

{{< highlight cpp >}}
struct Log {
    int id;
    string status;
    int time;
};
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<Log> stk;
        for(string log : logs) {
            stringstream ss(log);
            string num, adj, time;
            getline(ss, num,  ':');
            getline(ss, adj,  ':');
            getline(ss, time, ':');
            Log item = { stoi(num), adj, stoi(time) };

            if(item.status == "start") {
                stk.push(item);
            } else {
                assert(stk.top().id == item.id);
                int t = item.time - stk.top().time +1;
                ans[item.id] += t;
                stk.pop();
                if(!stk.empty()){
                    assert(stk.top().status == "start");
                    ans[stk.top().id] -= t;
                }
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/636.md" >}}
---
{{< youtube Rjcwy-Q2uDo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #638: Shopping Offers](https://grid47.xyz/posts/leetcode-636-exclusive-time-of-functions-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
