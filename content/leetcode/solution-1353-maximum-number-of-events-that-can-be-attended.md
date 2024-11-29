
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
comments = true
+++



---
You are given a list of events where each event is represented by a pair [startDay, endDay]. Your task is to find the maximum number of events you can attend, ensuring that you attend only one event per day.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of events, where each event is represented by a pair of integers indicating the start and end day of the event.
- **Example:** `For example, [[1, 2], [2, 3], [3, 4]] where each pair represents an event that lasts from start to end day.`
- **Constraints:**
	- 1 <= events.length <= 10^5
	- events[i].length == 2
	- 1 <= startDay[i] <= endDay[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the maximum number of events you can attend.
- **Example:** `For the input [[1, 2], [2, 3], [3, 4]], the output should be 3.`
- **Constraints:**
	- The result will always be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the number of events that can be attended by scheduling them on non-overlapping days.

- 1. Sort the events based on their start day. If two events start on the same day, sort by the end day.
- 2. Use a priority queue (min-heap) to keep track of the end days of events that are currently active.
- 3. Iterate through the days and for each day, add any events that start on that day and remove events that have ended.
- 4. Track the maximum number of events that can be attended at any point in time.
{{< dots >}}
### Problem Assumptions ✅
- Events do not overlap by default, but they may share common days.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: [[1, 2], [2, 3], [3, 4]]`  \
  **Explanation:** In this case, you can attend all three events by selecting one event per day.

- **Input:** `Example 2: [[1, 2], [2, 3], [3, 4], [1, 2]]`  \
  **Explanation:** In this case, you can attend all four events by choosing the best days.

{{< dots >}}
## Approach 🚀
The approach involves sorting the events and using a priority queue to keep track of the events and manage overlaps efficiently.

### Initial Thoughts 💭
- Sorting the events by start day helps in managing overlaps.
- Using a priority queue allows us to quickly remove events that have ended.
- We should aim to minimize the number of overlapping events while maximizing the number of events we can attend.
{{< dots >}}
### Edge Cases 🌐
- No events: The result should be 0.
- Handling up to 10^5 events efficiently without performance degradation.
- Events that start and end on the same day: Handle these events appropriately.
- The solution should run in O(n log n) time due to sorting.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a function that finds the maximum number of events that can be attended, where each event has a start and end day. It sorts the events by their start day and uses a priority queue to track the end days of events to optimize the attendance calculation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Comparator Function**
	```cpp
	static bool cmp(vector<int> &a, vector<int> &b) {
	```
	We define a comparator function to sort the events. If two events have the same start day, they are sorted by their end day in ascending order.

2. **Comparator Logic**
	```cpp
	    if(a[0] == b[0]) return a[1] < b[1];
	```
	If two events start on the same day, we return true if the first event ends earlier than the second.

3. **Comparator Logic**
	```cpp
	    else return a[0] < b[0];
	```
	If the start days are different, we return true if the first event starts earlier than the second.

4. **Function Declaration**
	```cpp
	int maxEvents(vector<vector<int>>& e) {
	```
	The 'maxEvents' function is declared, which takes a vector of events, each represented as a pair of start and end days.

5. **Event Count Initialization**
	```cpp
	    int n = e.size();
	```
	We initialize 'n' to the number of events, which is the size of the vector 'e'.

6. **Sort Events**
	```cpp
	    sort(e.begin(), e.end(), cmp);
	```
	We sort the events by their start day (and end day if the start days are equal) using the 'cmp' comparator.

7. **Priority Queue Declaration**
	```cpp
	    priority_queue<int, vector<int>, greater<int>> pq;
	```
	We declare a priority queue to store the end days of events, sorted in ascending order.

8. **Counter Initialization**
	```cpp
	    int i = 0, cnt = 0;
	```
	We initialize two variables: 'i' to track the index of events and 'cnt' to count the number of events that can be attended.

9. **Day Loop**
	```cpp
	    for(int d = 1; d <= 100000; d++) {
	```
	We loop over each day from 1 to 100000, representing the possible days on which an event can take place.

10. **Pop Expired Events**
	```cpp
	        while(!pq.empty() && pq.top() < d) {
	```
	We remove events from the priority queue that have already ended before the current day 'd'.

11. **Pop Expired Event**
	```cpp
	            pq.pop();
	```
	We remove the event with the earliest end day from the priority queue.

12. **Add New Events**
	```cpp
	        while(i < n && e[i][0] == d) {
	```
	We add all events starting on the current day 'd' to the priority queue.

13. **Push Event to Queue**
	```cpp
	            pq.push(e[i++][1]);
	```
	We push the end day of the current event into the priority queue and move to the next event.

14. **Attend Event**
	```cpp
	        if(!pq.empty()) {
	```
	If there are events available to attend, we proceed to attend one.

15. **Pop Attended Event**
	```cpp
	            pq.pop();
	```
	We pop the event with the earliest end day from the priority queue, as it is the event we will attend.

16. **Increment Event Count**
	```cpp
	            cnt++;
	```
	We increment the event count as we have successfully attended an event.

17. **Return Result**
	```cpp
	    return cnt;
	```
	We return the total count of events that can be attended.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for sorting the events.
- **Average Case:** O(n log n) due to sorting and priority queue operations.
- **Worst Case:** O(n log n), where n is the number of events.

The time complexity is dominated by sorting the events.

### Space Complexity 💾
- **Best Case:** O(1) if there are no events.
- **Worst Case:** O(n) for the priority queue and input storage.

The space complexity is O(n) due to the storage of events and the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/)

---
{{< youtube EKZhEN9P2-I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
