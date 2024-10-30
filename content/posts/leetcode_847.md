
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 847: Shortest Path Visiting All Nodes"
date = "2022-07-07"
description = "Solution to Leetcode 847"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/)

---

**Code:**

{{< highlight cpp >}}
class Node {
public:
    int mask, cur, cost;
    Node(int msk, int cu, int cos) {
        mask = msk;
        cur = cu;
        cost = cos;
    }
    int eq(Node *n) {
        return n->mask == this->mask &&
             n->cur == this->cur &&
             n->cost == this->cost;
    }
    int hash() {
        return 1331 * this->mask+ 
               7193 * this->cur + 
                727 * this->cost;
    }
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& gph) {
        set<int> s;
        queue<Node*> q;
        for(int i = 0; i < gph.size(); i++) {
            Node* tmp = new Node(1 << i, i, 0);
            s.insert(tmp->hash());
            q.push(tmp);
        }
        
        while(!q.empty()) {
            
            Node* tmp = q.front();
            q.pop();
            if(tmp->mask == (1 << gph.size()) - 1)
                return tmp->cost;
            
            for(auto x : gph[tmp->cur]) {
                int msk = tmp->mask;
                msk |= (1 << x);
                Node* t = new Node(msk, x, 0);
                if(!s.count(t->hash())) {
                    q.push(new Node(msk, x, tmp->cost + 1));
                    s.insert(t->hash());
                }
            }
            
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/847.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

