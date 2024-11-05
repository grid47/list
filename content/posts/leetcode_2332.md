
+++
authors = ["Crafted by Me"]
title = "Leetcode 2332: The Latest Time to Catch a Bus"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2332: The Latest Time to Catch a Bus in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-latest-time-to-catch-a-bus/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size();
        int m = passengers.size();
        queue<int> q;
        set<int> st;
        
        for(auto a: passengers) {
            q.push(a);
            st.insert(a);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int curbus = buses[i];
            int count = 0;
            int x ;

            while(!q.empty() && count < capacity && q.front() <= curbus) {
                x = q.front();
                q.pop();
                if(st.find(x - 1) == st.end()) ans = x - 1;
                count++;
            }

            if(count < capacity) {
                while(st.find(curbus) != st.end())
                 curbus--;
                ans = max(ans, curbus);
            }
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube TAbfqi-5Zm0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2333: Minimum Sum of Squared Difference](https://grid47.xyz/posts/leetcode_2333) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

