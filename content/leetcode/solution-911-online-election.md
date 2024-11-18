
+++
authors = ["grid47"]
title = "Leetcode 911: Online Election"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 911: Online Election in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6lmMcTr9gbo"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/6lmMcTr9gbo/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/online-election/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/911.md" >}}
---
{{< youtube 6lmMcTr9gbo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #915: Partition Array into Disjoint Intervals](https://grid47.xyz/leetcode/solution-915-partition-array-into-disjoint-intervals/) |
| --- |
