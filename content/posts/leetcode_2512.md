
+++
authors = ["Crafted by Me"]
title = "Leetcode 2512: Reward Top K Students"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2512: Reward Top K Students in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reward-top-k-students/description/)

---

**Code:**

{{< highlight cpp >}}
class cmp {
    public:
    bool operator()(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& pos, vector<string>& neg, vector<string>& report, vector<int>& id, int k) {
        set<string> p, n;
        for(auto it: pos) {
            p.insert(it);
        }
        for(auto it: neg) {
            n.insert(it);
        }
        
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        
        int sz = report.size();
        for(int i = 0; i < sz; i++) {
            string s = report[i];
            int prv = 0;
            int sum = 0;
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == ' ' || j == s.size() - 1) {
                    string str = s.substr(prv, (j == s.size() - 1? s.size(): j) - prv);
                    // cout << str << " ";
                    prv = j + 1;
                    if(p.count(str)) sum += 3;
                    if(n.count(str)) sum -= 1;
                }
            }
            // cout << sum << " " << id[i] << "\n";
            pq.push({sum, id[i]});
        }
        cout << "\n";
        vector<int> ans;
        while(!pq.empty() && k--) {
            cout << pq.top()[0] << " " << pq.top()[1] << "\n";
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube -ZE6ZmNU6KQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2513: Minimize the Maximum of Two Arrays](https://grid47.xyz/posts/leetcode_2513) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

