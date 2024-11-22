
+++
authors = ["grid47"]
title = "Leetcode 1353: Maximum Number of Events That Can Be Attended"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1353: Maximum Number of Events That Can Be Attended in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EKZhEN9P2-I"
youtube_upload_date="2020-07-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EKZhEN9P2-I/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    
    int maxEvents(vector<vector<int>>& e) {
        
        int n = e.size();
        sort(e.begin(), e.end(), cmp);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0, cnt = 0;
        for(int d = 1; d <= 100000; d++) {
            while(!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            while(i < n && e[i][0] == d) {
                pq.push(e[i++][1]);
            }
            if(!pq.empty()) {
                pq.pop();
                cnt++;
            }
        }

        return cnt;
    }
};
{{< /highlight >}}
---



### Problem Statement
The goal of this problem is to maximize the number of events that can be attended given a list of events, where each event has a start and an end date. You can attend one event per day, and your objective is to find out how many events you can attend in total. Each event is represented as a pair of integers `[start, end]`, where `start` is the starting day of the event, and `end` is the ending day of the event.

### Approach
To solve the problem effectively, the approach is as follows:

1. **Sorting Events**: First, sort the events based on their start time. If two events start on the same day, sort them by their end time. This allows for efficient processing of events as we iterate through each day.
   
2. **Using a Min-Heap (Priority Queue)**: A priority queue (min-heap) is employed to keep track of the end times of events that are available to be attended on a given day. This allows for quick access to the event that finishes the earliest, maximizing the potential to attend subsequent events.

3. **Iterating Through Days**: Iterate through each day from `1` to `100,000` (as specified in the problem constraints). For each day:
   - Remove events from the heap that have already ended.
   - Add new events starting on that day to the heap.
   - If there are any events available to attend, select the one that ends the earliest (using the priority queue), thus allowing room for more future events.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
```
- The `cmp` function is a comparator for sorting events. It sorts events first by their start day. If two events start on the same day, it sorts them by their end day to facilitate easy management of the events in the priority queue.

```cpp
    int maxEvents(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end(), cmp); // Sort the events based on start and end times
```
- The `maxEvents` function starts by determining the number of events `n` and sorts the events using the previously defined comparator.

```cpp
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, cnt = 0; // `i` tracks the current event and `cnt` counts attended events
```
- A priority queue `pq` is initialized to store the end times of the events that can be attended. The variables `i` and `cnt` track the index of the current event being processed and the count of events attended, respectively.

```cpp
        for(int d = 1; d <= 100000; d++) {
            while(!pq.empty() && pq.top() < d) {
                pq.pop(); // Remove events that have already ended
            }
            while(i < n && e[i][0] == d) {
                pq.push(e[i++][1]); // Add events starting on day `d`
            }
```
- The loop iterates through each day from `1` to `100,000`. The inner loop first removes any events from the priority queue that have ended before the current day. Then, it adds all events that start on the current day to the priority queue.

```cpp
            if(!pq.empty()) {
                pq.pop(); // Attend the event that ends the earliest
                cnt++; // Increment the count of attended events
            }
        }
```
- After processing the events for the current day, if the priority queue is not empty, it pops the event that ends first, indicating that one event has been attended, and the count is incremented.

```cpp
        return cnt; // Return the total count of attended events
    }
};
```
- Finally, the total count of attended events `cnt` is returned.

### Complexity Analysis
- **Time Complexity**: 
  - Sorting the events takes \(O(n \log n)\).
  - The overall processing involves iterating through `100,000` days. Each day can involve operations with the priority queue, which takes \(O(\log n)\). Therefore, the total time complexity is \(O(n \log n + d \log n)\), where \(d\) is `100,000`. Given that \(n\) is generally smaller than `d`, we can simplify this to \(O(n \log n)\).

- **Space Complexity**: 
  - The space complexity is \(O(n)\) for storing the events in the priority queue and any additional space used by the vector of events.

### Conclusion
The `maxEvents` function efficiently determines the maximum number of events that can be attended given their start and end days. By utilizing a combination of sorting and a priority queue, the algorithm ensures optimal event management, allowing for quick access to the next available event to attend.

This approach demonstrates a solid understanding of greedy algorithms and data structures, particularly how priority queues can optimize decision-making processes in time-based problems. The clear structure and efficiency of this implementation make it a strong solution to the problem, suitable for competitive programming and interview settings.

By breaking down each part of the code and the overall logic, this explanation serves as a valuable resource for those learning about algorithms related to scheduling and event management, providing insights that can be applied to similar problems in various contexts.


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/)

---
{{< youtube EKZhEN9P2-I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
