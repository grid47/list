
+++
authors = ["grid47"]
title = "Leetcode 743: Network Delay Time"
date = "2024-08-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 743: Network Delay Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Heap (Priority Queue)","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/743.webp"
youtube = "Bp7STMWMMQw"
youtube_upload_date="2024-05-23"
youtube_thumbnail="https://i.ytimg.com/vi/Bp7STMWMMQw/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/network-delay-time/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/743.webp" 
    alt="A network of nodes where the delay time is calculated, with the shortest delay glowing softly as it’s found."
    caption="Solution to LeetCode 743: Network Delay Time Problem"
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, map<int, int>> mp;
        
        for(int i = 0; i < times.size(); i++) {
            mp[times[i][0]][times[i][1]] = times[i][2];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n + 1, 0);
        pq.push(make_pair(0, k));
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if(vis[it.second]) continue;
            vis[it.second] = true;
            n--;
            if(n == 0) return it.first;
            
            if(mp.count(it.second))
                for(auto [key, val]: mp[it.second]) {
                    pq.push(make_pair(val + it.first, key));
                }
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/743.md" >}}
---
{{< youtube Bp7STMWMMQw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #744: Find Smallest Letter Greater Than Target](https://grid47.xyz/leetcode/solution-744-find-smallest-letter-greater-than-target/) |
| --- |