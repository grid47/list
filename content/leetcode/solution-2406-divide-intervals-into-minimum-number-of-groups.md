
+++
authors = ["grid47"]
title = "Leetcode 2406: Divide Intervals Into Minimum Number of Groups"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2406: Divide Intervals Into Minimum Number of Groups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting","Heap (Priority Queue)","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FVjKrhdMutc"
youtube_upload_date="2024-10-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FVjKrhdMutc/maxresdefault.webp"
comments = true
+++



---
You are given a 2D array of intervals, where each interval is represented as a pair of integers [left, right], denoting an inclusive range. Your task is to divide these intervals into the minimum number of groups such that no two intervals within the same group overlap. Two intervals overlap if there is at least one common number between them.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array `intervals` where each element `intervals[i]` is an array of two integers, left and right, representing the start and end of an interval.
- **Example:** `intervals = [[1, 5], [6, 10], [3, 7], [8, 12], [15, 18]]`
- **Constraints:**
	- 1 <= intervals.length <= 10^5
	- Each interval is represented by two integers where 1 <= lefti <= righti <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of groups required to partition the intervals such that no two intervals within the same group overlap.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of groups while ensuring that no two intervals within the same group overlap.

- 1. Sort the intervals by their start times.
- 2. Use a priority queue (min-heap) to track the end times of intervals in each group.
- 3. For each interval, check if it can be added to an existing group (i.e., its start time is greater than the smallest end time in the heap).
- 4. If it can, update the group's end time; otherwise, start a new group.
- 5. Keep track of the maximum number of groups at any time.
{{< dots >}}
### Problem Assumptions ✅
- Intervals are inclusive of both left and right endpoints.
- The input list will not contain empty intervals.
{{< dots >}}
## Examples 🧩
- **Input:** `intervals = [[5, 10], [6, 8], [1, 5], [2, 3], [1, 10]]`  \
  **Explanation:** We can divide the intervals into the following groups: Group 1: [1, 5], [6, 8]; Group 2: [2, 3], [5, 10]; Group 3: [1, 10]. Thus, 3 groups are needed.

- **Input:** `intervals = [[1, 3], [5, 6], [8, 10], [11, 13]]`  \
  **Explanation:** Since none of the intervals overlap, all intervals can be placed in one group.

- **Input:** `intervals = [[1, 4], [3, 5], [5, 6], [7, 8]]`  \
  **Explanation:** The optimal partition is: Group 1: [1, 4], [5, 6]; Group 2: [3, 5], [7, 8]. We need 2 groups.

{{< dots >}}
## Approach 🚀
We will use a greedy approach, sorting the intervals and using a priority queue (min-heap) to track the current end times of intervals in each group. By efficiently managing the end times, we can minimize the number of groups.

### Initial Thoughts 💭
- Sorting the intervals will allow us to process them in order of their start times.
- Using a priority queue will allow us to efficiently manage and track the end times of intervals in each group.
- A greedy strategy works well here, as we only need to track the end times and adjust the groups accordingly.
{{< dots >}}
### Edge Cases 🌐
- Empty input is not possible as per the problem constraints, but handling zero intervals would result in zero groups.
- For large inputs with up to 10^5 intervals, the solution should perform efficiently in O(n log n) time due to sorting and priority queue operations.
- Intervals with the same start and end time (e.g., [1, 1], [1, 1]) should be handled correctly as separate intervals.
- The solution must efficiently handle intervals where the length of the list is large (up to 10^5).
{{< dots >}}
## Code 💻
```cpp
int minGroups(vector<vector<int>>& list) {
    sort(list.begin(), list.end());
    
    int res = 1, cnt = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
            
    int n = list.size();
    
    pq.push(list[0][1]);
    
    if(n == 1) return 1;
    for(int i = 1; i < n; i++) {
        int next = list[i][0];            
        while(!pq.empty() && next > pq.top()) {
            pq.pop();
            cnt--;
        }
        pq.push(list[i][1]);
        cnt++;
        res = max(res, cnt);
    }
    return res;
}
```

This function calculates the minimum number of meeting groups that can be formed given a list of meeting time intervals. It sorts the intervals and uses a priority queue to manage the intervals and calculate the maximum number of overlapping meetings at any point in time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minGroups(vector<vector<int>>& list) {
	```
	Define the function `minGroups` which takes a vector of vectors representing meeting time intervals and returns the minimum number of meeting groups.

2. **Sorting**
	```cpp
	    sort(list.begin(), list.end());
	```
	Sort the meeting intervals based on their start times to facilitate easier management of overlapping intervals.

3. **Variable Declaration**
	```cpp
	    int res = 1, cnt = 1;
	```
	Initialize the result variable `res` to 1 and the counter `cnt` to 1, representing the number of ongoing meetings.

4. **Priority Queue**
	```cpp
	    priority_queue<int, vector<int>, greater<int>> pq;
	```
	Define a priority queue `pq` to store the end times of the ongoing meetings in ascending order.

5. **Size Calculation**
	```cpp
	    int n = list.size();
	```
	Get the size of the list of meeting intervals, `n`, to determine the number of intervals.

6. **First Interval Push**
	```cpp
	    pq.push(list[0][1]);
	```
	Push the end time of the first meeting interval into the priority queue.

7. **Early Return**
	```cpp
	    if(n == 1) return 1;
	```
	If there is only one interval, return 1 as only one group is needed.

8. **Main Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Start a loop to iterate over the remaining intervals starting from index 1.

9. **Next Start Time**
	```cpp
	        int next = list[i][0];            
	```
	Get the start time of the next meeting interval.

10. **While Loop**
	```cpp
	        while(!pq.empty() && next > pq.top()) {
	```
	While the priority queue is not empty and the next start time is greater than the earliest ending meeting time, pop meetings from the queue.

11. **Priority Queue Pop**
	```cpp
	            pq.pop();
	```
	Pop the earliest ending meeting time from the priority queue.

12. **Decrease Counter**
	```cpp
	            cnt--;
	```
	Decrement the ongoing meetings count since one meeting has ended.

13. **Push End Time**
	```cpp
	        pq.push(list[i][1]);
	```
	Push the end time of the current meeting interval into the priority queue.

14. **Increase Counter**
	```cpp
	        cnt++;
	```
	Increment the ongoing meetings count as a new meeting has started.

15. **Update Maximum**
	```cpp
	        res = max(res, cnt);
	```
	Update the result to keep track of the maximum number of overlapping meetings.

16. **Return Result**
	```cpp
	    return res;
	```
	Return the result, which is the maximum number of overlapping meetings.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the number of intervals, due to sorting.
- **Average Case:** O(n log n), as sorting dominates the time complexity.
- **Worst Case:** O(n log n), as the sorting step is the most time-consuming operation.

The solution efficiently handles large inputs due to the O(n log n) time complexity.

### Space Complexity 💾
- **Best Case:** O(n), as we always need space for storing the intervals and their end times.
- **Worst Case:** O(n), where n is the number of intervals, as we store the intervals and the priority queue.

The space complexity is linear due to the storage of intervals and the priority queue used to manage the end times.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/)

---
{{< youtube FVjKrhdMutc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
