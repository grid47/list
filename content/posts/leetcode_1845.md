
+++
authors = ["Crafted by Me"]
title = "Leetcode 1845: Seat Reservation Manager"
date = "2019-10-15"
description = "In-depth solution and explanation for Leetcode 1845: Seat Reservation Manager in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


---
{{< youtube ahobllKXEEY >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

