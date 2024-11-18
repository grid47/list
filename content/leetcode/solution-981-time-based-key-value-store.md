
+++
authors = ["grid47"]
title = "Leetcode 981: Time Based Key-Value Store"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 981: Time Based Key-Value Store in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Binary Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eVi4gDimCoo"
youtube_upload_date="2021-01-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/eVi4gDimCoo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/time-based-key-value-store/description/)

---
**Code:**

{{< highlight cpp >}}
class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int ts) {
        if(!mp.count(key)) return "";
        // vector<pair<int, string>> v = &mp[key];
        int l = 0, r = mp[key].size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(ts > mp[key][m].first) {
                if(m == r || ts < mp[key][m + 1].first)
                    return mp[key][m].second;
                l = m + 1;
            } else if(ts < mp[key][m].first)
                r = m - 1;
            else return mp[key][m].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/981.md" >}}
---
{{< youtube eVi4gDimCoo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #983: Minimum Cost For Tickets](https://grid47.xyz/leetcode/solution-983-minimum-cost-for-tickets/) |
| --- |
