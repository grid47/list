
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 981: Time Based Key-Value Store"
date = "2022-02-22"
description = "Solution to Leetcode 981"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
