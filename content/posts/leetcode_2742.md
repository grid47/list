
+++
authors = ["Crafted by Me"]
title = "Leetcode 2742: Painting the Walls"
date = "2017-05-01"
description = "In-depth solution and explanation for Leetcode 2742: Painting the Walls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/painting-the-walls/description/)

---

**Code:**

{{< highlight cpp >}}
class cmp {
    public:
    bool operator()(vector<float> &a, vector<float> &b) {
        if(a[0] == b[0]) {
            return a[1] < b[1]; // longer time
        }
        return a[0] > b[0];
    }
};

class PQ {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        /*
        
        min cost
        max time
        
        cost / time less
        
        if equal, max time should get preference
        
        */
        
        priority_queue<vector<float>, vector<vector<float>>, cmp> pq;
        int n = cost.size();
        for(int i = 0; i < n; i++) {
            pq.push({(float)cost[i] / time[i], (float)time[i], (float)cost[i]});
        }
        int res = 0;
        while(n > 0) {
            auto cur = pq.top();
            res += (int)cur[2];
            n--;
            n -= (int)cur[1];
            pq.pop();
        }
        return res;
    }
};

class Solution {
public:
    int n;
    vector<int> cost;
    vector<int> time;
    vector<vector<int>> mem;

    int dp(int i, int rm) {
        
        
        if(rm <= 0) return 0;
        if(i == n) return INT_MAX;
        
        if(mem[i][rm] != -1) return mem[i][rm];
        
        
        int ans = dp(i + 1, rm);
        
        int ret = dp(i + 1, rm - 1 - time[i]);
        
        ans = min(ans, ret == INT_MAX? ret: ret + cost[i]);
        
        return mem[i][rm] = ans;
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        this->cost = cost;
        this->time = time;
        
        // PQ a1 = new PQ();
        // return a1.paintWalls(cost, time);

        mem.resize(n, vector<int>(n + 1, -1));
        return dp(0, n);
    
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

