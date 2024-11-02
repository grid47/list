
+++
authors = ["Crafted by Me"]
title = "Leetcode 1024: Video Stitching"
date = "2021-01-12"
description = "Solution to Leetcode 1024"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/video-stitching/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int res = 0;
        for(auto i = 0, st = 0, end = 0; st < time; st=end, ++res){
            for(; i < clips.size() && clips[i][0] <= st; ++i)
                end = max(end, clips[i][1]);
            if(st == end) return -1;
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

