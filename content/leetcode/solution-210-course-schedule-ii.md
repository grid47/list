
+++
authors = ["grid47"]
title = "Leetcode 210: Course Schedule II"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 210: Course Schedule II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "2cpihwDznaw"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/210.webp"
+++



[`Problem Link`](https://leetcode.com/problems/course-schedule-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/210.webp" 
    alt="A series of tasks gently forming a schedule, with dependencies softly highlighted as the courses unfold."
    caption="Solution to LeetCode 210: Course Schedule II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> gph(n);
        vector<int> incnt(n, 0);
        for(int i = 0; i < pre.size(); i++) {
            gph[pre[i][1]].push_back(pre[i][0]);
            incnt[pre[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(incnt[i] == 0)
                q.push(i);
        vector<int> ans;
        while(!q.empty()) {
            int y = q.front();
            ans.push_back(y);
            q.pop();
            for(auto x: gph[y]) {
                incnt[x]--;
                if(incnt[x] == 0)
                    q.push(x);
            }
        }
        return ans.size() == n? ans: vector<int>();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/210.md" >}}
---
{{< youtube 2cpihwDznaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #211: Design Add and Search Words Data Structure](https://grid47.xyz/leetcode/solution-211-design-add-and-search-words-data-structure/) |
| --- |
