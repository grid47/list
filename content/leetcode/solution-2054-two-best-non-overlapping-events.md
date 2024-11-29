
+++
authors = ["grid47"]
title = "Leetcode 2054: Two Best Non-Overlapping Events"
date = "2024-04-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2054: Two Best Non-Overlapping Events in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eC62DF5PW6E"
youtube_upload_date="2021-10-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/eC62DF5PW6E/maxresdefault.webp"
comments = true
+++



---
Find the maximum sum of values you can achieve by attending at most two non-overlapping events.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A list of events where each event is represented by its start time, end time, and value.
- **Example:** `Input: events = [[2, 4, 5], [5, 6, 3], [1, 3, 4]]`
- **Constraints:**
	- 2 <= events.length <= 10^5
	- events[i].length == 3
	- 1 <= startTime_i <= endTime_i <= 10^9
	- 1 <= value_i <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** An integer representing the maximum value obtainable by attending at most two non-overlapping events.
- **Example:** `Output: 9 for the given input events.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the maximum value by attending up to two non-overlapping events.

- Sort the events by their end times.
- Iterate over the events in reverse to find the maximum value obtainable from a single event.
- Use a binary search to find the next non-overlapping event for each event.
- Compute the maximum sum of values for one and two events.
{{< dots >}}
### Problem Assumptions ✅
- Events are provided in arbitrary order.
- Two events are non-overlapping if the second event's start time is strictly greater than the first event's end time.
{{< dots >}}
## Examples 🧩
- **Input:** `events = [[2, 4, 5], [5, 6, 3], [1, 3, 4]]`  \
  **Explanation:** Attend events 0 and 1 for a sum of 5 + 3 = 9.

{{< dots >}}
## Approach 🚀
Use dynamic programming and binary search to maximize the value obtained by attending up to two non-overlapping events.

### Initial Thoughts 💭
- If only one event can be attended, the answer is the maximum value among all events.
- To attend two events, the second event must start after the first event ends.
- Binary search is useful to efficiently find the next non-overlapping event.
- Sort events by their end times to make searching for non-overlapping events easier.
- Iterate through the events while keeping track of the maximum value seen so far.
{{< dots >}}
### Edge Cases 🌐
- Input: events = [], Output: 0
- Input: events = [[1, 1000000000, 1000000], [1000000001, 2000000000, 1000000]], Output: 2000000
- Input: events = [[1, 2, 5], [3, 4, 5], [2, 3, 5]], Output: 10
- Input: events = [[1, 1, 1], [2, 2, 1]], Output: 2
{{< dots >}}
## Code 💻
```cpp

vector<vector<int>> eve;
vector<vector<unordered_map<int, int>>> memo;
int n;

int dp(int idx, int end, int k) {
    if(idx >= n || k == 0) return 0;
    
    if(memo[idx][k].count(end)) return memo[idx][k][end];
    
    int ans = dp(idx + 1, end, k);
    
    int l = idx + 1, r = n - 1, res = n;
    
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        
        if(eve[mid][0] > eve[idx][1]) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
        
    }
    
    ans = max(ans, eve[idx][2] + dp(res, eve[idx][1], k - 1));
    
    return memo[idx][k][end] = ans;
}

int ma(vector<vector<int>>& events) {
    sort(events.begin(), events.end());
    eve = events;
    n = eve.size();
    memo.resize(n, vector<unordered_map<int, int>>(3));
    return dp(0, 0, 2);        
}

int maxTwoEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());
    
    int ans = 0, mx = 0;
    map<int, int> mp;
    
    int size = events.size();
    
    while(size--) {
        auto it = mp.upper_bound(events[size][1]);
        mx = max(mx, events[size][2]);
        mp[events[size][0]] = mx;
        if(it == mp.end()) {
            ans = max(ans, mx);
        } else {
            ans = max(ans, events[size][2] + it->second);
        }
    }
    return ans;
}
```

This code solves the problem of selecting two non-overlapping events that maximize the total value. The dynamic programming (dp) function tracks the best possible outcome given the constraints, while the maxTwoEvents function iterates over the events to maximize the sum of event values while avoiding overlaps.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<vector<int>> eve;
	```
	Declare a 2D vector 'eve' to store event data (start time, end time, and value) for each event.

2. **Variable Declaration**
	```cpp
	vector<vector<unordered_map<int, int>>> memo;
	```
	Declare a 3D vector 'memo' used to store computed values for dynamic programming. The memoization technique will avoid redundant calculations.

3. **Variable Declaration**
	```cpp
	int n;
	```
	Declare an integer variable 'n' to hold the number of events.

4. **Function Declaration**
	```cpp
	int dp(int idx, int end, int k) {
	```
	Declare the dp function, which will recursively compute the maximum value achievable from a given index, end time, and remaining selections (k).

5. **Base Case**
	```cpp
	    if(idx >= n || k == 0) return 0;
	```
	The base case of the dp function: If the index exceeds the number of events or if no more selections are allowed (k == 0), return 0.

6. **Memoization Check**
	```cpp
	    if(memo[idx][k].count(end)) return memo[idx][k][end];
	```
	Check if the result for the current state (idx, k, end) has already been computed. If it has, return the stored result to avoid redundant calculations.

7. **Recursive Call**
	```cpp
	    int ans = dp(idx + 1, end, k);
	```
	Make a recursive call to explore the next event without selecting the current one.

8. **Binary Search Setup**
	```cpp
	    int l = idx + 1, r = n - 1, res = n;
	```
	Set up binary search bounds: 'l' starts from the next event after 'idx', 'r' is the last event, and 'res' holds the result index for the next event to select.

9. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Start a binary search loop to find the first event that does not overlap with the current event (eve[idx]).

10. **Binary Search Update**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Calculate the mid-point of the current binary search bounds.

11. **Binary Search Condition**
	```cpp
	        if(eve[mid][0] > eve[idx][1]) {
	```
	If the start time of the event at 'mid' is greater than the end time of the current event, update 'res' to be 'mid' and narrow the search range.

12. **Binary Search Update**
	```cpp
	            res = mid;
	```
	Update the result to the current 'mid' index where a valid non-overlapping event is found.

13. **Binary Search Update**
	```cpp
	            r = mid - 1;
	```
	Reduce the upper bound of the binary search to narrow down the search range.

14. **Binary Search Update**
	```cpp
	        } else l = mid + 1;
	```
	If the event at 'mid' overlaps with the current event, move the lower bound to the right.

15. **Max Calculation**
	```cpp
	    ans = max(ans, eve[idx][2] + dp(res, eve[idx][1], k - 1));
	```
	Calculate the maximum result by selecting the current event (eve[idx][2]) and adding the result of the next valid event (dp(res, eve[idx][1], k-1)).

16. **Memoization Store**
	```cpp
	    return memo[idx][k][end] = ans;
	```
	Store the computed result for the current state (idx, k, end) in the memoization table to avoid recalculating in the future.

17. **Function Declaration**
	```cpp
	int ma(vector<vector<int>>& events) {
	```
	Declare the main function 'ma' that takes a vector of events as input.

18. **Sorting**
	```cpp
	    sort(events.begin(), events.end());
	```
	Sort the events by their start time to facilitate the selection of non-overlapping events.

19. **Variable Assignment**
	```cpp
	    eve = events;
	```
	Assign the sorted events to the global 'eve' vector.

20. **Variable Assignment**
	```cpp
	    n = eve.size();
	```
	Set the number of events 'n' to the size of the 'eve' vector.

21. **Memoization Resize**
	```cpp
	    memo.resize(n, vector<unordered_map<int, int>>(3));
	```
	Resize the memoization table to accommodate all events and selections.

22. **Recursive Call**
	```cpp
	    return dp(0, 0, 2);
	```
	Start the dp calculation from the first event, with no events selected and a maximum of two selections allowed.

23. **Main Function Declaration**
	```cpp
	int maxTwoEvents(vector<vector<int>>& events) {
	```
	Declare the main function 'maxTwoEvents' that is called to solve the problem.

24. **Sorting**
	```cpp
	    sort(events.begin(), events.end());
	```
	Sort the events by their start time for easier comparison.

25. **Variable Declaration**
	```cpp
	    int ans = 0, mx = 0;
	```
	Declare variables to store the answer and the maximum value encountered so far.

26. **Map Declaration**
	```cpp
	    map<int, int> mp;
	```
	Declare a map 'mp' to store the maximum value for each event's end time.

27. **While Loop**
	```cpp
	    int size = events.size();
	```
	Get the size of the events vector to iterate over.

28. **While Loop**
	```cpp
	    while(size--) {
	```
	Start a loop to iterate over all events in reverse order.

29. **Map Search**
	```cpp
	        auto it = mp.upper_bound(events[size][1]);
	```
	Find the first event in the map whose end time is greater than the current event's end time.

30. **Max Update**
	```cpp
	        mx = max(mx, events[size][2]);
	```
	Update the maximum value encountered so far with the current event's value.

31. **Map Update**
	```cpp
	        mp[events[size][0]] = mx;
	```
	Update the map with the current event's start time and its corresponding maximum value.

32. **Result Calculation**
	```cpp
	        if(it == mp.end()) {
	```
	If no valid event is found, update the answer with the maximum value encountered so far.

33. **Result Calculation**
	```cpp
	            ans = max(ans, mx);
	```
	Update the answer with the maximum value found.

34. **Result Calculation**
	```cpp
	        } else {
	```
	If a valid event is found, update the answer with the sum of the current event's value and the maximum value from the map.

35. **Result Calculation**
	```cpp
	            ans = max(ans, events[size][2] + it->second);
	```
	Update the answer with the sum of the current event's value and the result from the map.

36. **Return Statement**
	```cpp
	    return ans;
	```
	Return the final answer after processing all events.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the events and performing binary searches for each event dominate the time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space is used for the map and sorting auxiliary structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/two-best-non-overlapping-events/description/)

---
{{< youtube eC62DF5PW6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
