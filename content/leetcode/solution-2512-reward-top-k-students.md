
+++
authors = ["grid47"]
title = "Leetcode 2512: Reward Top K Students"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2512: Reward Top K Students in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "-ZE6ZmNU6KQ"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2512.md" >}}
---
{{< youtube -ZE6ZmNU6KQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2513: Minimize the Maximum of Two Arrays](https://grid47.xyz/leetcode/solution-2513-minimize-the-maximum-of-two-arrays/) |
| --- |
