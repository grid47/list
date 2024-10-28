
+++
authors = ["Yasir"]
title = "Leetcode 911: Online Election"
date = "2022-05-02"
description = "Solution to Leetcode 911"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/online-election/description/)

---

**Code:**

{{< highlight html >}}
class TopVotedCandidate {
public:
    map<int, int> mp;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size(), lead = -1;
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            lead = ++cnt[persons[i]] >= cnt[lead]? persons[i] : lead;
            mp[times[i]] = lead;
        }
            
    }
    
    int q(int t) {
        return (--mp.upper_bound(t))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

