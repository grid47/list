
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 433: Minimum Genetic Mutation"
date = "2023-08-23"
description = "Solution to Leetcode 433"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

