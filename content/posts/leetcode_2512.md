
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2512: Reward Top K Students"
date = "2017-12-13"
description = "Solution to Leetcode 2512"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

