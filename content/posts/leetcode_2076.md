
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2076: Process Restricted Friend Requests"
date = "2019-02-23"
description = "Solution to Leetcode 2076"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/process-restricted-friend-requests/description/)

---

**Code:**

{{< highlight cpp >}}
class UF {
    vector<int> dads;
public:
    
    UF(int n) {
        dads.resize(n, 0);
        for(int i = 0; i < n; i++)
            dads[i] = i;
    }
    void print() {
        for(int i = 0; i < dads.size(); i++)
            cout << dads[i] << " ";
        cout<< endl;
    }
    bool join(int x, int y) {
        int p = find(x);
        int q = find(y);
        if(p != q) {
            dads[p] = q;
            return true;
        }
        return false;
    }
    int find(int x) {
        return dads[x] == x? x : (dads[x] = find(dads[x]));
    }
    
    bool pairs(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& rxns, vector<vector<int>>& reqs) {

        // UF rxn = UF(n);
        UF req = UF(n);

        // for(vector<int> node : rxns)
        // rxn.join(node[0], node[1]);
        
        // rxn.print();

        vector<bool> ans(reqs.size(), false);
        for(int i = 0; i < reqs.size(); i++) {

            vector<int> node = reqs[i];
            bool valid = true;
            if(!req.pairs(node[0], node[1]))
            {
                int p = req.find(node[0]);
                int q = req.find(node[1]);

                for(auto& e : rxns) {
                    int x = req.find(e[0]);
                    int y = req.find(e[1]);
                    
                    if ((x == p && y == q) ||
                        (y == p && x == q) ) {
                        valid = false;
                        break;
                    }
                }
            }
            ans[i] = valid;
            if(valid) req.join(node[0], node[1]);
        }

        return ans;        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
