
+++
authors = ["grid47"]
title = "Leetcode 1348: Tweet Counts Per Frequency"
date = "2024-06-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1348: Tweet Counts Per Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Binary Search","Design","Sorting","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jpK7Bpf8wgk"
youtube_upload_date="2021-04-05"
youtube_thumbnail="https://i.ytimg.com/vi/jpK7Bpf8wgk/maxresdefault.jpg"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1351: Count Negative Numbers in a Sorted Matrix](https://grid47.xyz/leetcode/solution-1351-count-negative-numbers-in-a-sorted-matrix/) |
| --- |
