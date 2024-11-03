
+++
authors = ["Crafted by Me"]
title = "Leetcode 752: Open the Lock"
date = "2022-10-12"
description = "In-depth solution and explanation for Leetcode 752: Open the Lock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/752.md" >}}
---
{{< youtube Pzg3bCDY87w >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

