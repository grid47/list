
+++
authors = ["Yasir"]
title = "Leetcode 502: IPO"
date = "2023-06-14"
description = "Solution to Leetcode 502"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ipo/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        vector<pair<int, int>> arr;
        priority_queue<int> pq;
        int n = capital.size();
        for(int i = 0; i < n; i++) {
            if(capital[i] <= w) {
                pq.push(profit[i]);
            } else {
                arr.push_back({capital[i], profit[i]});                
            }
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        int sum = w;
        while(k-- && !pq.empty()) {
            sum += pq.top();
            pq.pop();
            while(i < arr.size() && arr[i].first <= sum) {
                pq.push(arr[i].second);
                i++;
            }
        }
        return sum;
        /*
        
            i have a current capital
            i can pick all the the projects with lesser capital required
            
            from set of all projects available to pick
            choose the one with highest profit
            
            if that adds more possibilities expand the serach space
            
            then again choose the top guy
            
            repeat last two steps,
        
        */
        
        
    }
};
{{< /highlight >}}

