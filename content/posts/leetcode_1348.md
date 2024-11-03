
+++
authors = ["Crafted by Me"]
title = "Leetcode 1348: Tweet Counts Per Frequency"
date = "2021-02-23"
description = "In-depth solution and explanation for Leetcode 1348: Tweet Counts Per Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/tweet-counts-per-frequency/description/)

---

**Code:**

{{< highlight cpp >}}
class TweetCounts {
    unordered_map<string, vector<int>> mp;
    unordered_map<string, int> frq = {
        {"minute", 60}, {"hour", 3600}, {"day", 86400}
    };
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string name, int time) {
        mp[name].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string fq, string name, int start, int end) {
        vector<int> res;
        for(int i = 0; i <= (end - start) / frq[fq]; i++)
            res.push_back(0);
        
        for(int i = 0; i < mp[name].size(); i++) {
            int t = mp[name][i];
            if(t >= start && t <= end) {
            int idx = (t - start) / frq[fq];
            res[idx]++;
            }
        }
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1348.md" >}}
---
{{< youtube jpK7Bpf8wgk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1349: Maximum Students Taking Exam](https://grid47.xyz/posts/leetcode_1349) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

