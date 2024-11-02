
+++
authors = ["Crafted by Me"]
title = "Leetcode 2790: Maximum Number of Groups With Increasing Length"
date = "2016-03-13"
description = "Solution to Leetcode 2790"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool possible(vector<int>& nums, int x) {
        priority_queue<int, vector<int>> pq;
        int n = nums.size();
        for(int x: nums) pq.push(x);
        int cur = 0;
        while(x > 0) {
            int req = x;
            while(req > 0) {
                if(cur == 0) {
                    if(pq.empty()) return false;
                    // cout << pq.top();
                    cur = min(x, pq.top());
                    pq.pop();

                }
                int ded = min(req, cur);
                // cout << x << " " << cur << " "<< ded << ", ";
                req -= ded;

                if(req == 0 && ded < cur) {
                    
                }
                cur -= ded;
            }
            x--;
        }
        return true;
    }

    int dump(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int l = 1, r = n, ans = 1;

        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            
            if(possible(nums, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
        
    }
    
    int maxIncreasingGroups(vector<int>& nums) {
        
        
        
        sort(nums.begin(), nums.end());
        long bar = 0, net = 0;
        
        for(int x: nums) {
            
            
            net += x;
            if( net >= ((bar + 1) * (bar + 2) / 2))
                bar++;
        }
        return bar;
    }
};

{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

