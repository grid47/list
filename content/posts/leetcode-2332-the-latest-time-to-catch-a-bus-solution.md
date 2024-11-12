
+++
authors = ["grid47"]
title = "Leetcode 2332: The Latest Time to Catch a Bus"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2332: The Latest Time to Catch a Bus in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2332.md" >}}
---
{{< youtube TAbfqi-5Zm0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2333: Minimum Sum of Squared Difference](https://grid47.xyz/posts/leetcode-2333-minimum-sum-of-squared-difference-solution/) |
| --- |
