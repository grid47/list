
+++
authors = ["grid47"]
title = "Leetcode 2332: The Latest Time to Catch a Bus"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2332: The Latest Time to Catch a Bus in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TAbfqi-5Zm0"
youtube_upload_date="2022-07-09"
youtube_thumbnail="https://i.ytimg.com/vi/TAbfqi-5Zm0/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays representing bus departure times and passenger arrival times, along with the maximum capacity of each bus. The task is to determine the latest time you may arrive at the bus station to catch a bus. You cannot arrive at the same time as another passenger.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three items: an array of bus departure times, an array of passenger arrival times, and an integer representing the capacity of each bus.
- **Example:** `buses = [10, 20], passengers = [2, 17, 18, 19], capacity = 2`
- **Constraints:**
	- n == buses.length
	- m == passengers.length
	- 1 <= n, m, capacity <= 10^5
	- 2 <= buses[i], passengers[i] <= 10^9
	- All elements in buses and passengers are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the latest possible time you can arrive at the bus station and still catch a bus.
- **Example:** `16`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to find the latest time you can arrive at the bus station without missing a bus and without arriving at the same time as another passenger.

- Sort the buses and passengers arrays.
- For each bus, board passengers based on arrival times and capacity.
- Determine the latest possible time you can arrive at the bus station and still catch a bus.
{{< dots >}}
### Problem Assumptions ✅
- All bus departure times are unique.
- All passenger arrival times are unique.
{{< dots >}}
## Examples 🧩
- **Input:** `If buses = [10, 20] and passengers = [2, 17, 18, 19], and capacity = 2, arriving at time 16 ensures you catch the second bus.`  \
  **Explanation:** At time 10, the first bus departs with the 0th passenger. At time 20, the second bus departs with you and the 1st passenger.

- **Input:** `For buses = [20, 30, 10], passengers = [19, 13, 26, 4, 25, 11, 21], and capacity = 2, arriving at time 20 ensures you catch the third bus.`  \
  **Explanation:** At time 10, the first bus departs with the 3rd passenger. At time 20, the second bus departs with the 5th and 1st passengers. At time 30, the third bus departs with the 0th passenger and you.

{{< dots >}}
## Approach 🚀
Sort the bus departure times and passenger arrival times. For each bus, board passengers based on their arrival times and the bus capacity. Then determine the latest possible time you can arrive at the bus station.

### Initial Thoughts 💭
- We can simulate the boarding process by iterating over buses and passengers.
- Sorting both arrays ensures we process buses and passengers in chronological order.
{{< dots >}}
### Edge Cases 🌐
- If no passengers are available, return the last bus departure time.
- Handle large input sizes efficiently.
- Ensure no conflicts when passengers arrive at the same time.
- Handle the maximum size of buses and passengers arrays efficiently.
{{< dots >}}
## Code 💻
```cpp
int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());
    int n = buses.size();
    int m = passengers.size();
    queue<int> q;
    set<int> st;
    
    for(auto a: passengers) {
        q.push(a);
        st.insert(a);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int curbus = buses[i];
        int count = 0;
        int x ;

        while(!q.empty() && count < capacity && q.front() <= curbus) {
            x = q.front();
            q.pop();
            if(st.find(x - 1) == st.end()) ans = x - 1;
            count++;
        }

        if(count < capacity) {
            while(st.find(curbus) != st.end())
             curbus--;
            ans = max(ans, curbus);
        }
    }
    return ans;
}
```

This function finds the latest time at which a passenger can catch a bus given a list of bus arrival times, passenger arrival times, and the bus capacity. It uses a greedy approach to simulate the boarding process and determine the optimal time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
	```
	Declares the function `latestTimeCatchTheBus`, which takes in vectors of bus arrival times and passenger arrival times, along with the bus capacity, and returns the latest time a passenger can catch the bus.

2. **Sorting Buses**
	```cpp
	    sort(buses.begin(), buses.end());
	```
	Sorts the bus arrival times in ascending order to simulate the sequence in which the buses arrive.

3. **Sorting Passengers**
	```cpp
	    sort(passengers.begin(), passengers.end());
	```
	Sorts the passenger arrival times in ascending order to simulate the sequence in which passengers arrive at the bus station.

4. **Initialize Variables**
	```cpp
	    int n = buses.size();
	```
	Stores the number of buses in the variable `n`.

5. **Initialize Variables**
	```cpp
	    int m = passengers.size();
	```
	Stores the number of passengers in the variable `m`.

6. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	Creates a queue to manage the passengers waiting for the bus.

7. **Set Initialization**
	```cpp
	    set<int> st;
	```
	Creates a set to keep track of the passengers who have already boarded the bus.

8. **Add Passengers to Queue and Set**
	```cpp
	    for(auto a: passengers) {
	```
	Iterates through each passenger arrival time and adds it to both the queue and the set.

9. **Queue Operations**
	```cpp
	        q.push(a);
	```
	Adds the passenger to the queue, simulating the passenger waiting for the bus.

10. **Set Operations**
	```cpp
	        st.insert(a);
	```
	Adds the passenger to the set, which tracks passengers who have boarded the bus.

11. **Initialize Answer**
	```cpp
	    int ans = 0;
	```
	Initializes the variable `ans`, which will store the latest time a passenger can catch the bus.

12. **Bus Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates through each bus in the buses list.

13. **Current Bus Time**
	```cpp
	        int curbus = buses[i];
	```
	Stores the current bus time in the variable `curbus`.

14. **Initialize Boarding Counter**
	```cpp
	        int count = 0;
	```
	Initializes a counter `count` to track how many passengers have boarded the current bus.

15. **Temporary Variable**
	```cpp
	        int x ;
	```
	Declares a temporary variable `x` to store the current passenger being processed.

16. **Passenger Boarding Logic**
	```cpp
	        while(!q.empty() && count < capacity && q.front() <= curbus) {
	```
	Checks if there are passengers in the queue, if the bus has space (`count < capacity`), and if the next passenger arrives before or when the bus arrives.

17. **Board Passenger**
	```cpp
	            x = q.front();
	```
	Sets the variable `x` to the front of the queue (the current passenger's arrival time).

18. **Queue Operations**
	```cpp
	            q.pop();
	```
	Removes the passenger from the queue, simulating that the passenger has boarded the bus.

19. **Passenger Checking**
	```cpp
	            if(st.find(x - 1) == st.end()) ans = x - 1;
	```
	Checks if the previous passenger (i.e., `x - 1`) has already boarded. If not, updates `ans` to the latest time a passenger can board.

20. **Update Boarding Count**
	```cpp
	            count++;
	```
	Increments the boarding count for each passenger that boards the bus.

21. **Check If Bus Has Capacity Left**
	```cpp
	        if(count < capacity) {
	```
	Checks if the current bus has remaining capacity.

22. **Find Last Available Slot**
	```cpp
	            while(st.find(curbus) != st.end())
	```
	Finds the last available time slot for a passenger by decrementing the current bus time until no passengers have already boarded at that time.

23. **Decrement Bus Time**
	```cpp
	             curbus--;
	```
	Decrements the bus time to find the last available time slot.

24. **Update Answer**
	```cpp
	            ans = max(ans, curbus);
	```
	Updates the `ans` with the latest available bus time.

25. **Return Answer**
	```cpp
	    return ans;
	```
	Returns the latest time a passenger can catch the bus.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The solution involves sorting the buses and passengers arrays, each of size n and m respectively.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is dominated by the storage required for the buses and passengers arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-latest-time-to-catch-a-bus/description/)

---
{{< youtube TAbfqi-5Zm0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
