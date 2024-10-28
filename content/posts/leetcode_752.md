
+++
authors = ["Yasir"]
title = "Leetcode 752: Open the Lock"
date = "2022-10-08"
description = "Solution to Leetcode 752"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/open-the-lock/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<string> q({"0000"});
        
        for(int turn = 0;!q.empty(); turn++) {
            for(int i = q.size(); i > 0; i--) {
                auto curr = q.front(); q.pop();
                cout << curr << ' ' << target << endl;
                if (curr == target) return turn;
                for(auto it : neighbours(curr)) {
                    if(dead.count(it)) continue;
                    dead.insert(it);
                    q.push(it);
                }
            }
        }
        return -1;
    }

    vector<string> neighbours(const string &code) {
        vector<string> res;
        for(int i = 0; i < 4; i++) {
            for(int diff = -1; diff <= 1; diff++) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                res.push_back(nei);
            }
        }
        return res;
    }

};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

