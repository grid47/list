
+++
authors = ["Crafted by Me"]
title = "Leetcode 433: Minimum Genetic Mutation"
date = "2023-08-27"
description = "In-depth solution and explanation for Leetcode 433: Minimum Genetic Mutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-genetic-mutation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st{bank.begin(), bank.end()};
        if(!st.count(endGene)) return -1;

        queue<string> q;
        q.push(startGene);
        int step = 0, s;
        string cur, t;
        while(!q.empty()) {
            s = q.size();
            while(s--) {
                cur = q.front();
                q.pop();
                if(cur == endGene) return step;
                st.erase(cur);
                for(int i= 0; i < 8; i++) {
                    t = cur;
                    t[i] = 'A';
                    if(st.count(t)) q.push(t);
                    t[i] = 'T';
                    if(st.count(t)) q.push(t);
                    t[i] = 'G';
                    if(st.count(t)) q.push(t);
                    t[i] = 'C';
                    if(st.count(t)) q.push(t);                    
                }
            }
            step++;
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/433.md" >}}
---
{{< youtube XLvyInrFjm4 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

