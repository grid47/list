
+++
authors = ["grid47"]
title = "Leetcode 2406: Divide Intervals Into Minimum Number of Groups"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2406: Divide Intervals Into Minimum Number of Groups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting","Heap (Priority Queue)","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FVjKrhdMutc"
youtube_upload_date="2024-10-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FVjKrhdMutc/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minGroups(vector<vector<int>>& list) {
        sort(list.begin(), list.end());
        
        int res = 1, cnt = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
                
        int n = list.size();
        
        pq.push(list[0][1]);
        
        if(n == 1) return 1;
        for(int i = 1; i < n; i++) {
            int next = list[i][0];            
            while(!pq.empty() && next > pq.top()) {
                pq.pop();
                cnt--;
            }
            pq.push(list[i][1]);
            cnt++;
            res = max(res, cnt);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2406.md" >}}
---
{{< youtube FVjKrhdMutc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2409: Count Days Spent Together](https://grid47.xyz/leetcode/solution-2409-count-days-spent-together/) |
| --- |