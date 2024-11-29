
+++
authors = ["grid47"]
title = "Leetcode 2187: Minimum Time to Complete Trips"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2187: Minimum Time to Complete Trips in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "M5moLQ_6Xs4"
youtube_upload_date="2022-02-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/M5moLQ_6Xs4/maxresdefault.webp"
comments = true
+++



---
You are given an array 'time' where each element 'time[i]' represents the time taken by the ith bus to complete a trip. Your task is to calculate the minimum amount of time required for all buses to complete at least 'totalTrips' trips in total. Each bus can complete multiple trips consecutively.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers 'time' and an integer 'totalTrips'.
- **Example:** `Input: time = [4, 5], totalTrips = 6`
- **Constraints:**
	- 1 <= time.length <= 10^5
	- 1 <= time[i], totalTrips <= 10^7

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum time required for all buses to complete at least 'totalTrips' trips.
- **Example:** `Output: 10`
- **Constraints:**
	- The solution must handle large inputs efficiently.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum time required for all buses to complete at least 'totalTrips' trips.

- For a given time, calculate the total number of trips completed by all buses.
- Use binary search to find the smallest time for which the total number of trips is at least 'totalTrips'.
{{< dots >}}
### Problem Assumptions ✅
- Each bus operates independently and can make multiple trips in succession.
- All buses are in operation at the same time.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: time = [4, 5], totalTrips = 6`  \
  **Explanation:** At time t = 4, the number of trips completed by the buses are [1,0]. At t = 8, the buses have completed [2,1]. At t = 10, the total number of trips is 6. So, the minimum time required is 10.

- **Input:** `Input: time = [3, 6], totalTrips = 5`  \
  **Explanation:** At time t = 3, the number of trips completed by the buses are [1,0]. At t = 6, the buses have completed [2,1]. At t = 9, the total number of trips is 5. So, the minimum time required is 9.

{{< dots >}}
## Approach 🚀
We will calculate the number of trips completed by each bus for a given time and use binary search to find the minimum time to complete the required total trips.

### Initial Thoughts 💭
- The binary search will allow us to find the optimal time efficiently.
- To solve this problem, we need to determine the number of trips made by all buses for different time intervals and use binary search to narrow down the minimum time.
{{< dots >}}
### Edge Cases 🌐
- Empty input is not possible based on constraints.
- Ensure the solution handles cases where time has up to 10^5 elements and the totalTrips can be as large as 10^7.
- If all buses have the same trip time, the solution should still work efficiently.
- The solution must avoid a brute force approach to ensure it works efficiently for large inputs.
{{< dots >}}
## Code 💻
```cpp
long long numberOfTripsForAGivenTime(vector<int> &a, long long int givenTime) {
    long long int totalTrips = 0;
    for(int &x : a) {
        long long int y = x;
        totalTrips += givenTime / y;
    }
    return totalTrips;
}

long long minimumTime(vector<int>& time, int totalTrips) {
    long long int low = 1, high = 1e14;
    while(low < high) {
        long long int mid = low + (high - low) / 2;
        if(numberOfTripsForAGivenTime(time, mid) >= totalTrips) {
            high = mid;
        } else low = mid + 1;
    }
    return low;
}
```

This code defines two functions: `numberOfTripsForAGivenTime` and `minimumTime`. The first calculates the total number of trips that can be made in a given time based on input trip durations. The second function uses binary search to find the minimum time required to complete a specified number of trips.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long numberOfTripsForAGivenTime(vector<int> &a, long long int givenTime) {
	```
	This defines the function `numberOfTripsForAGivenTime`, which takes a vector of trip durations and a given time, and calculates the total number of trips that can be completed in the given time.

2. **Variable Initialization**
	```cpp
	    long long int totalTrips = 0;
	```
	A variable `totalTrips` is initialized to 0 to accumulate the total number of trips that can be made within the given time.

3. **Loop Through Trips**
	```cpp
	    for(int &x : a) {
	```
	This loop iterates through each element `x` in the vector `a`, which represents the duration of each trip.

4. **Temporary Variable**
	```cpp
	        long long int y = x;
	```
	A temporary variable `y` is created to store the current trip duration `x`. This is done to avoid directly modifying `x` in subsequent calculations.

5. **Accumulate Total Trips**
	```cpp
	        totalTrips += givenTime / y;
	```
	The number of trips that can be completed in the given time for the current trip duration `y` is calculated by integer division of `givenTime / y`. This value is added to `totalTrips`.

6. **Return Total Trips**
	```cpp
	    return totalTrips;
	```
	The function returns the total number of trips that can be completed within the given time.

7. **Empty Location**
	```cpp
	
	```
	This location is left empty as there are no intermediate steps between the functions.

8. **Function Definition**
	```cpp
	long long minimumTime(vector<int>& time, int totalTrips) {
	```
	This defines the function `minimumTime`, which takes a vector of trip durations and the total number of trips to be completed, and calculates the minimum time required to complete those trips.

9. **Binary Search Initialization**
	```cpp
	    long long int low = 1, high = 1e14;
	```
	Two variables `low` and `high` are initialized for the binary search. `low` starts at 1 and `high` is set to a very large value (1e14) to cover a wide range of possible times.

10. **Binary Search Loop**
	```cpp
	    while(low < high) {
	```
	This loop performs binary search, narrowing down the range of possible times (`low` and `high`) until the correct minimum time is found.

11. **Midpoint Calculation**
	```cpp
	        long long int mid = low + (high - low) / 2;
	```
	The midpoint `mid` is calculated as the average of `low` and `high`, which will be checked to see if it allows enough trips to meet or exceed the required `totalTrips`.

12. **Check Trips for Midpoint**
	```cpp
	        if(numberOfTripsForAGivenTime(time, mid) >= totalTrips) {
	```
	The function `numberOfTripsForAGivenTime` is called with `mid` as the given time. If the total trips calculated for this time are greater than or equal to the required `totalTrips`, the upper bound (`high`) is adjusted.

13. **Adjust High**
	```cpp
	            high = mid;
	```
	If the current `mid` allows enough trips, `high` is updated to `mid` to search for a smaller possible time.

14. **Adjust Low**
	```cpp
	        } else low = mid + 1;
	```
	If the current `mid` does not allow enough trips, `low` is updated to `mid + 1` to search for a larger possible time.

15. **Return Minimum Time**
	```cpp
	    return low;
	```
	The function returns the minimum time found by the binary search.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log T)
- **Average Case:** O(n log T)
- **Worst Case:** O(n log T)

The time complexity is O(n log T), where n is the number of buses and T is the time interval range.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a constant amount of extra space for calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-time-to-complete-trips/description/)

---
{{< youtube M5moLQ_6Xs4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
