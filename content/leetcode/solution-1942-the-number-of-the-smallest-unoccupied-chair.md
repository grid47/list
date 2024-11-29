
+++
authors = ["grid47"]
title = "Leetcode 1942: The Number of the Smallest Unoccupied Chair"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1942: The Number of the Smallest Unoccupied Chair in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LqhxcaCctCc"
youtube_upload_date="2024-10-11"
youtube_thumbnail="https://i.ytimg.com/vi/LqhxcaCctCc/maxresdefault.jpg"
comments = true
+++



---
In a party, there are n friends with distinct arrival and departure times. Each friend chooses the smallest available chair. The task is to determine the chair number where the friend numbered targetFriend will sit.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A 2D array times where times[i] = [arrivali, leavingi] indicates the arrival and leaving times of the ith friend, and an integer targetFriend representing the index of the target friend.
- **Example:** `times = [[1,5],[2,6],[3,8]], targetFriend = 1`
- **Constraints:**
	- 2 <= n <= 10^4
	- 1 <= arrivali < leavingi <= 10^5
	- Each arrival time is distinct
	- 0 <= targetFriend < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the chair number that the target friend will sit on.
- **Example:** `Output: 1`
- **Constraints:**
	- The output is an integer representing the chair number.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the chair number occupied by the target friend.

- Sort the friends based on their arrival times.
- Use two priority queues: one for keeping track of the available chairs and another for tracking the chairs occupied by friends based on their leaving times.
- Assign the smallest available chair to each arriving friend and release the chair when a friend leaves.
- Check when the target friend arrives and assign their chair number.
{{< dots >}}
### Problem Assumptions ✅
- The arrival and departure times for each friend are unique and provided in a correct format.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: times = [[1, 5], [2, 6], [3, 8]], targetFriend = 1`  \
  **Explanation:** Friend 0 arrives at time 1 and sits on chair 0. Friend 1 arrives at time 2 and sits on chair 1. Friend 2 arrives at time 3 and sits on chair 2. At time 5, Friend 0 leaves and Friend 1 sits back in chair 0. Friend 2 stays until time 8. Since Friend 1 sits on chair 1, the answer is 1.

- **Input:** `Example 2: times = [[1, 3], [2, 5], [3, 7], [4, 6]], targetFriend = 2`  \
  **Explanation:** Friend 0 arrives at time 1 and sits on chair 0. Friend 1 arrives at time 2 and sits on chair 1. Friend 2 arrives at time 3 and sits on chair 2. Friend 1 leaves at time 5, Friend 2 leaves at time 7, and Friend 3 arrives at time 4. The target friend 2 sits on chair 2.

{{< dots >}}
## Approach 🚀
To determine the chair number for the target friend, we will manage chair availability using priority queues and ensure the correct allocation of chairs as friends arrive and leave.

### Initial Thoughts 💭
- We need to efficiently track both the arrival and departure times of friends.
- Using priority queues allows us to quickly find the smallest available chair and to manage which chairs are being occupied or released.
{{< dots >}}
### Edge Cases 🌐
- The problem ensures that there are no empty inputs.
- Handle scenarios with the maximum number of friends and their respective times efficiently.
- When only two friends are involved, the solution should still correctly track the chairs.
- Ensure that all times are within the provided limits and that the chair assignment is accurate.
{{< dots >}}
## Code 💻
```cpp
int smallestChair(vector<vector<int>>& a, int t) {
    int tt = a[t][0];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reserve;
    priority_queue<int, vector<int>, greater<int>> avail;
    sort(a.begin(), a.end());
    for(auto &t : a) {
        
        while(!reserve.empty() && reserve.top().first <= t[0]) {
            
            avail.push(reserve.top().second);
            reserve.pop();
            
        }
        
        if(t[0] == tt) break;
        if (!avail.empty()) {
            
            reserve.push({t[1], avail.top()});
                         
           avail.pop();
            
        } else {
            
            reserve.push({t[1], reserve.size()});
            
        }
        
    }
    
    return avail.empty()? reserve.size() : avail.top();
    
}
```

This function finds the smallest chair index at a given time `t` for a set of events, using priority queues to manage the reservations and available chairs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int smallestChair(vector<vector<int>>& a, int t) {
	```
	Declare the function `smallestChair`, which accepts a 2D vector `a` representing event start and end times, and an integer `t` indicating the target time.

2. **Time Extraction**
	```cpp
	    int tt = a[t][0];
	```
	Extract the start time `tt` of the event at index `t`.

3. **Priority Queue Initialization (Reservation)**
	```cpp
	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reserve;
	```
	Initialize a priority queue `reserve` to store pairs of end times and chair indices, sorted by the end time.

4. **Priority Queue Initialization (Available Chairs)**
	```cpp
	    priority_queue<int, vector<int>, greater<int>> avail;
	```
	Initialize a priority queue `avail` to manage the available chair indices, sorted in ascending order.

5. **Sorting Events**
	```cpp
	    sort(a.begin(), a.end());
	```
	Sort the events in `a` by their start times.

6. **Event Iteration**
	```cpp
	    for(auto &t : a) {
	```
	Loop through each event `t` in the sorted list of events.

7. **While Loop (Check Expired Reservations)**
	```cpp
	        while(!reserve.empty() && reserve.top().first <= t[0]) {
	```
	Check if there are any expired reservations (those whose end time is less than or equal to the current event's start time).

8. **Push to Available Chairs**
	```cpp
	            avail.push(reserve.top().second);
	```
	Push the chair index from the top reservation (expired) into the `avail` queue to make it available.

9. **Pop Expired Reservation**
	```cpp
	            reserve.pop();
	```
	Pop the top reservation from the `reserve` queue as it is now expired.

10. **Check Target Time**
	```cpp
	        if(t[0] == tt) break;
	```
	If the current event's start time is equal to the target time `tt`, break the loop.

11. **Check Available Chairs**
	```cpp
	        if (!avail.empty()) {
	```
	If there are available chairs, proceed to assign one.

12. **Push to Reserve (Available Chair)**
	```cpp
	            reserve.push({t[1], avail.top()});
	```
	Assign an available chair (from the `avail` queue) to the current event and add the reservation to the `reserve` queue.

13. **Else (No Available Chair)**
	```cpp
	        } else {
	```
	If there are no available chairs, assign a new one.

14. **Push to Reserve (New Chair)**
	```cpp
	            reserve.push({t[1], reserve.size()});
	```
	Assign a new chair index (based on the size of `reserve` queue) to the current event and add the reservation to the `reserve` queue.

15. **Return Statement**
	```cpp
	    return avail.empty()? reserve.size() : avail.top();
	```
	Return the index of the smallest available chair, or the total number of reservations if no chairs are available.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), due to sorting the arrival times and managing the queues.
- **Average Case:** O(n log n), for each friend's arrival and departure time management.
- **Worst Case:** O(n log n), as each friend's event needs to be processed and sorted.

The time complexity is dominated by the sorting of the arrival times and the operations on the priority queues.

### Space Complexity 💾
- **Best Case:** O(n), as we may need to track up to n chairs at once.
- **Worst Case:** O(n), for storing the event times and the state of each chair.

The space complexity is linear with respect to the number of friends, as we need to track their arrival and departure times along with the chairs.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/)

---
{{< youtube LqhxcaCctCc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
