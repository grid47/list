
+++
authors = ["grid47"]
title = "Leetcode 451: Sort Characters By Frequency"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 451: Sort Characters By Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting","Heap (Priority Queue)","Bucket Sort","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-characters-by-frequency/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/451.webp" 
    alt="A string where characters are sorted by frequency, with the most frequent characters glowing brightly."
    caption="Solution to LeetCode 451: Sort Characters By Frequency Problem"
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
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(bucket[i].size())
                res.append(bucket[i]);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/451.md" >}}
---
{{< youtube JTdpTHaGQoA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #452: Minimum Number of Arrows to Burst Balloons](https://grid47.xyz/posts/leetcode-452-minimum-number-of-arrows-to-burst-balloons-solution/) |
| --- |
