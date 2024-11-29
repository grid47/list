
+++
authors = ["grid47"]
title = "Leetcode 1870: Minimum Speed to Arrive on Time"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1870: Minimum Speed to Arrive on Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XtwJqb1HI-o"
youtube_upload_date="2021-05-23"
youtube_thumbnail="https://i.ytimg.com/vi/XtwJqb1HI-o/maxresdefault.jpg"
comments = true
+++



---
You are given a list of n train ride distances and a floating-point number hour which indicates the total time you have to reach your destination. You need to determine the minimum integer speed (in kilometers per hour) at which all the trains must travel to reach the office on time. If it is impossible, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array dist representing the distances for each train ride, and a floating-point number hour representing the total time to reach the office.
- **Example:** `[2, 5, 3], hour = 8`
- **Constraints:**
	- 1 <= dist.length <= 10^5
	- 1 <= dist[i] <= 10^5
	- 1 <= hour <= 10^9
	- hour has at most two decimal places.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum integer speed (in km/h) that all trains must travel to reach on time, or return -1 if it is impossible.
- **Example:** `2`
- **Constraints:**
	- The result should be an integer speed or -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum integer speed that satisfies the given time constraint for all train rides.

- Start with the smallest possible speed and calculate the time taken for each train ride.
- For each train ride, calculate the time based on the speed, and determine if you need to wait to depart at an integer hour.
- Use binary search to find the minimum speed that allows you to arrive at the office on time.
{{< dots >}}
### Problem Assumptions ✅
- All the train distances are positive integers.
- The total time must be greater than or equal to the time required for each train ride.
{{< dots >}}
## Examples 🧩
- **Input:** `[2, 5, 3], hour = 8`  \
  **Explanation:** At speed 2, the time taken for each train ride ensures that you arrive exactly on time (8 hours).

- **Input:** `[1, 5, 3], hour = 3.4`  \
  **Explanation:** At speed 3, the total time is less than 3.4 hours, but it is impossible to make it on time as the total time is 3 hours.

{{< dots >}}
## Approach 🚀
The approach involves using binary search to find the minimum integer speed and ensuring the total travel time is within the given hour limit.

### Initial Thoughts 💭
- We need to handle the fractional times and wait for the next integer hour to depart for each train.
- Binary search on speed can help find the smallest feasible speed in an efficient manner.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as dist has at least one element.
- For large inputs, the binary search approach ensures efficiency within the constraints.
- Handle cases where hour is very small or very large, especially when it's impossible to make it on time.
- Ensure correct handling of fractional times due to non-integer hours.
{{< dots >}}
## Code 💻
```cpp

bool canReach(int speed, vector<int>& dist, double hour) {
    
    double est = 0;
    
    for(int i = 0; i < dist.size(); i++) {
        if(i == (dist.size() - 1)) est += (double)dist[i]/ speed; 
        else est = ceil(est + (double)dist[i]/ speed);
    }
    // cout << speed << " " << est << " " << (est <= hour) << "\n";
    return est <= hour;
}

int minSpeedOnTime(vector<int>& dist, double hour) {
    int l = 0, r = INT_MAX - 1;
    
    int ans = INT_MAX;
    
    while(l <= r) {
        int speed = l + (r - l + 1)/2;
        
        if(canReach(speed, dist, hour)) {
            ans = speed;
            r = speed - 1;
        } else {
            l = speed + 1;
        }
    }
    return ans == INT_MAX? -1: ans;
}
```

Implements a binary search approach to determine the minimum speed required to reach on time, using helper function `canReach` to validate speed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Helper Function**
	```cpp
	bool canReach(int speed, vector<int>& dist, double hour) {
	```
	Defines a helper function to check if the given speed allows reaching within the specified hour.

2. **Calculation**
	```cpp
	    double est = 0;
	```
	Declares and initializes a variable to store the estimated time.

3. **For Loop**
	```cpp
	    for(int i = 0; i < dist.size(); i++) {
	```
	Iterates through each distance segment to calculate time based on speed.

4. **Condition Check**
	```cpp
	        if(i == (dist.size() - 1)) est += (double)dist[i]/ speed; 
	```
	Checks if it's the last segment to compute exact travel time.

5. **Ceiling Calculation**
	```cpp
	        else est = ceil(est + (double)dist[i]/ speed);
	```
	Adds the ceiling of travel time for intermediate segments.

6. **Return Statement**
	```cpp
	    return est <= hour;
	```
	Returns true if the estimated time is within the allowed hour.

7. **Binary Search Initialization**
	```cpp
	int minSpeedOnTime(vector<int>& dist, double hour) {
	```
	Starts the function and initializes binary search bounds.

8. **Binary Search Initialization**
	```cpp
	    int l = 0, r = INT_MAX - 1;
	```
	Defines the left and right bounds for binary search.

9. **Result Variable**
	```cpp
	    int ans = INT_MAX;
	```
	Sets the result variable to track the minimum speed.

10. **While Loop**
	```cpp
	    while(l <= r) {
	```
	Performs binary search to find the optimal speed.

11. **Midpoint Calculation**
	```cpp
	        int speed = l + (r - l + 1)/2;
	```
	Calculates the midpoint speed for binary search.

12. **Valid Speed**
	```cpp
	        if(canReach(speed, dist, hour)) {
	```
	Updates the result if the speed is valid.

13. **Update Right**
	```cpp
	            ans = speed;
	```
	Updates the answer and adjusts the binary search bound.

14. **Update Right**
	```cpp
	            r = speed - 1;
	```
	Adjusts the upper bound to refine the search.

15. **Else Block**
	```cpp
	        } else {
	```
	Handles the case where speed is too low.

16. **Update Left**
	```cpp
	            l = speed + 1;
	```
	Adjusts the lower bound to refine the search.

17. **Return Result**
	```cpp
	    return ans == INT_MAX? -1: ans;
	```
	Returns the minimum speed or -1 if no valid speed exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log M), where M is the maximum possible speed (10^7).
- **Average Case:** O(n log M), with n being the number of trains.
- **Worst Case:** O(n log M), due to the binary search on speed and iterating over all train rides.

The time complexity is logarithmic in terms of speed, with a linear scan of the train rides.

### Space Complexity 💾
- **Best Case:** O(1), no additional space is used beyond input and variables.
- **Worst Case:** O(1), as we only use a few extra variables.

The space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/)

---
{{< youtube XtwJqb1HI-o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
