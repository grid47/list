
+++
authors = ["grid47"]
title = "Leetcode 1845: Seat Reservation Manager"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1845: Seat Reservation Manager in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ahobllKXEEY"
youtube_upload_date="2021-05-01"
youtube_thumbnail="https://i.ytimg.com/vi/ahobllKXEEY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/seat-reservation-manager/description/)

---
**Code:**

{{< highlight cpp >}}
class SeatManager {
public:
    int i, n;
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        i = 1;
        this->n = n;
    }
    
    int reserve() {
        if(pq.empty() && i > n) {
            return -1;
        }
        if(pq.empty()) {
            i++;
            return i - 1;
        }
        int tmp = pq.top();
        pq.pop();
        return tmp;
    }
    
    void unreserve(int no) {
        if(no == i - 1) {
            i--;
            return;
        }
        pq.push(no);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1845.md" >}}
---
{{< youtube ahobllKXEEY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1846: Maximum Element After Decreasing and Rearranging](https://grid47.xyz/leetcode/solution-1846-maximum-element-after-decreasing-and-rearranging/) |
| --- |