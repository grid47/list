
+++
authors = ["grid47"]
title = "Leetcode 433: Minimum Genetic Mutation"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 433: Minimum Genetic Mutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/433.webp"
youtube = "XLvyInrFjm4"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/XLvyInrFjm4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-genetic-mutation/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/433.webp" 
    alt="A series of genes evolving through mutations, with each valid mutation softly glowing as it occurs."
    caption="Solution to LeetCode 433: Minimum Genetic Mutation Problem"
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
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st{bank.begin(), bank.end()};
        if(!st.count(endGene)) return -1;

        queue<string> q;
        q.push(startGene);
        int step = 0, s;
        string cur, t;
        while(!q.empty()) {
            s = q.size();
            while(s--) {
                cur = q.front();
                q.pop();
                if(cur == endGene) return step;
                st.erase(cur);
                for(int i= 0; i < 8; i++) {
                    t = cur;
                    t[i] = 'A';
                    if(st.count(t)) q.push(t);
                    t[i] = 'T';
                    if(st.count(t)) q.push(t);
                    t[i] = 'G';
                    if(st.count(t)) q.push(t);
                    t[i] = 'C';
                    if(st.count(t)) q.push(t);                    
                }
            }
            step++;
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/433.md" >}}
---
{{< youtube XLvyInrFjm4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #435: Non-overlapping Intervals](https://grid47.xyz/leetcode/solution-435-non-overlapping-intervals/) |
| --- |
