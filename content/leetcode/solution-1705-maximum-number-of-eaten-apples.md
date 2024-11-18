
+++
authors = ["grid47"]
title = "Leetcode 1705: Maximum Number of Eaten Apples"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1705: Maximum Number of Eaten Apples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1vRYTJqaZ8s"
youtube_upload_date="2020-12-27"
youtube_thumbnail="https://i.ytimg.com/vi/1vRYTJqaZ8s/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-eaten-apples/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        
        int n = days.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int res = 0, i = 0;
        
        while(i < n || !pq.empty()) {

            if(i < n && apples[i] > 0) pq.push({i + days[i] - 1, apples[i]});
            
            while(!pq.empty() && pq.top()[0] < i)
                pq.pop();
            
            if(!pq.empty()) {
                res++;
                auto it = pq.top();
                pq.pop();
                if(it[1] > 1) pq.push({it[0], it[1] - 1});
            }
            i++;
        }
            
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1705.md" >}}
---
{{< youtube 1vRYTJqaZ8s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1706: Where Will the Ball Fall](https://grid47.xyz/leetcode/solution-1706-where-will-the-ball-fall/) |
| --- |
