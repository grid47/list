
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1348: Tweet Counts Per Frequency"
date = "2021-02-20"
description = "Solution to Leetcode 1348"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

