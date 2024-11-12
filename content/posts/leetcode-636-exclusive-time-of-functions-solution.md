
+++
authors = ["grid47"]
title = "Leetcode 636: Exclusive Time of Functions"
date = "2024-09-04"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #638: Shopping Offers](https://grid47.xyz/posts/leetcode-638-shopping-offers-solution/) |
| --- |
