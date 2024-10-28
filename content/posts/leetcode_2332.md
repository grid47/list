
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2332: The Latest Time to Catch a Bus"
date = "2018-06-11"
description = "Solution to Leetcode 2332"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

