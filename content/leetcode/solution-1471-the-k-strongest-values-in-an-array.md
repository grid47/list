
+++
authors = ["grid47"]
title = "Leetcode 1471: The k Strongest Values in an Array"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1471: The k Strongest Values in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "5Hie-4QPNtI"
youtube_upload_date="2020-06-07"
youtube_thumbnail="https://i.ytimg.com/vi/5Hie-4QPNtI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/the-k-strongest-values-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class cmp {
    public:
     bool operator() (pair<float,int> &a, pair<float, int> &b) {
        if(a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        float m;
        if(n & 1) {
            m = arr[n / 2];
        } else {
            m = arr[n/2-1];
        }
        priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> pq;
        
        for(int i = 0; i < n; i++) {
            // cout << abs(arr[i] - m) << " " << arr[i] << " ";
            pq.push({abs(arr[i] - m), arr[i]});
        }
        vector<int> res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1471.md" >}}
---
{{< youtube 5Hie-4QPNtI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1472: Design Browser History](https://grid47.xyz/leetcode/solution-1472-design-browser-history/) |
| --- |