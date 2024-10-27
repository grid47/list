
+++
authors = ["Yasir"]
title = "Leetcode 1642: Furthest Building You Can Reach"
date = "2020-04-30"
description = "Solution to Leetcode 1642"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/furthest-building-you-can-reach/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:

    int furthestBuilding(vector<int>& h, int bri, int lad) {
        int n = h.size();
        vector<int> bc(n - 1, 0);
        
        for(int i = 0; i < n - 1; i++) {
            bc[i] = h[i + 1] - h[i] < 0 ? 0: h[i + 1] - h[i];
            // cout << bc[i] << " ";
        }
 
        // cout << "\n";
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0, sum = 0;
        for(; i < n - 1; i++) {

            if(bc[i] == 0) continue;
            
            if(pq.size() < lad) {
                pq.push(bc[i]);
            } else {
                pq.push(bc[i]);
                if(sum + pq.top() <= bri)
                sum += pq.top();
                else return i;
                pq.pop();
            }
            
        }
        // cout << sum << " " << bri << " " << i;
        return n - 1;
        // Use ladders first
        // when ladders are over
        // check are them could be replaced with bricks
        // if yes, continue to assigning released ladder
        // else return where it had overflown
    }
};
{{< /highlight >}}

