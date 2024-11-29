
+++
authors = ["grid47"]
title = "Leetcode 2594: Minimum Time to Repair Cars"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2594: Minimum Time to Repair Cars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yZ1o7WcAwxI"
youtube_upload_date="2023-03-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yZ1o7WcAwxI/maxresdefault.webp"
comments = true
+++



---
You are given an array `ranks` representing the ranks of some mechanics, where `ranks[i]` is the rank of the `i`-th mechanic. A mechanic with rank `r` can repair `n` cars in `r * n^2` minutes. You are also given an integer `cars` representing the total number of cars waiting to be repaired. Return the minimum time required to repair all the cars when all mechanics can work simultaneously.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `ranks` and an integer `cars`.
- **Example:** `For `ranks = [5, 2, 3, 1], cars = 12`.`
- **Constraints:**
	- 1 <= ranks.length <= 10^5
	- 1 <= ranks[i] <= 100
	- 1 <= cars <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum time required to repair all the cars.
- **Example:** `For `ranks = [5, 2, 3, 1], cars = 12`, the output is `15`.`
- **Constraints:**
	- The output is an integer representing the minimum time.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the time taken to repair all the cars by distributing the work efficiently among the mechanics.

- 1. Use binary search to find the minimum time required to repair all cars.
- 2. For each possible time, calculate how many cars can be repaired by each mechanic.
- 3. Sum up the number of cars repaired by all mechanics and check if it is sufficient to repair all the cars.
- 4. Adjust the search range to find the minimum time that allows all cars to be repaired.
{{< dots >}}
### Problem Assumptions ✅
- The number of cars is always at least 1.
- There will always be at least one mechanic.
{{< dots >}}
## Examples 🧩
- **Input:** `For `ranks = [5, 2, 3, 1], cars = 12``  \
  **Explanation:** By distributing the work among the mechanics, we find the minimum time required is 15 minutes.

{{< dots >}}
## Approach 🚀
The solution uses binary search to find the minimum time required to repair all the cars by distributing the work efficiently among the mechanics.

### Initial Thoughts 💭
- The time complexity is dominated by the binary search and the car calculation for each mechanic, which can be optimized.
- The binary search will help narrow down the possible time range efficiently.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one mechanic and one car, so no empty inputs are possible.
- The solution should efficiently handle large inputs up to the constraint limits.
- If there is only one mechanic or one car, the solution should still work correctly.
- The solution must handle inputs with up to 100,000 mechanics and 1 million cars.
{{< dots >}}
## Code 💻
```cpp

bool can(vector<int> &ranks, long long time, int cars) {
    long long cnt = 0;
    if(time == 0) return false;
    for(int i = 0; i < ranks.size(); i++) {
        cnt += (long long) sqrt(time/ranks[i]);
        
        if(cnt >= cars) return true;
    }
    
    return cnt >= cars;
}

long long repairCars(vector<int>& ranks, int cars) {
    sort(ranks.begin(), ranks.end());
    int mx = ranks[ranks.size() - 1];
    long long l = 0, r = LLONG_MAX - 100;
    long long ans = r;
    while(l <= r) {
        long long mid = l + (r - l + 1) / 2;
        if(can(ranks, mid, cars)) {
            ans= mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}
```

This is the full implementation of the repairCars function, which determines the minimum time required to repair a given number of cars using a binary search strategy. The can helper function checks if a given amount of time is enough to repair the cars based on their repair ranks.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool can(vector<int> &ranks, long long time, int cars) {
	```
	This function checks if it is possible to repair a given number of cars within the specified time, based on the repair ranks provided.

2. **Variable Initialization**
	```cpp
	    long long cnt = 0;
	```
	Initializes the counter 'cnt' to track the total number of cars that can be repaired within the given time.

3. **Condition Check**
	```cpp
	    if(time == 0) return false;
	```
	If time is zero, no cars can be repaired, so the function returns false.

4. **Loop**
	```cpp
	    for(int i = 0; i < ranks.size(); i++) {
	```
	Iterates through each rank to calculate the number of cars that can be repaired in the given time.

5. **Calculation**
	```cpp
	        cnt += (long long) sqrt(time/ranks[i]);
	```
	For each rank, it calculates how many cars can be repaired in the given time and adds it to 'cnt'.

6. **Condition Check**
	```cpp
	        if(cnt >= cars) return true;
	```
	If the counter reaches or exceeds the number of cars, it returns true, indicating that the repair is possible.

7. **Return Statement**
	```cpp
	    return cnt >= cars;
	```
	Returns true if the number of cars repaired is greater than or equal to the target; otherwise, it returns false.

8. **Function Definition**
	```cpp
	long long repairCars(vector<int>& ranks, int cars) {
	```
	Defines the 'repairCars' function, which determines the minimum time required to repair the specified number of cars.

9. **Sorting**
	```cpp
	    sort(ranks.begin(), ranks.end());
	```
	Sorts the repair ranks in ascending order to optimize the binary search process.

10. **Maximum Rank**
	```cpp
	    int mx = ranks[ranks.size() - 1];
	```
	Determines the maximum repair rank from the sorted ranks.

11. **Variable Initialization**
	```cpp
	    long long l = 0, r = LLONG_MAX - 100;
	```
	Initializes the binary search range, starting from 0 to a large value (LLONG_MAX - 100).

12. **Binary Search Setup**
	```cpp
	    long long ans = r;
	```
	Sets up a variable 'ans' to store the minimum time required.

13. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Begins the binary search loop.

14. **Middle Point Calculation**
	```cpp
	        long long mid = l + (r - l + 1) / 2;
	```
	Calculates the middle point of the current binary search range.

15. **Check Feasibility**
	```cpp
	        if(can(ranks, mid, cars)) {
	```
	Calls the 'can' function to check if it's possible to repair the cars in the current time 'mid'.

16. **Update Answer**
	```cpp
	            ans = mid;
	```
	If the 'can' function returns true, updates 'ans' to the current time.

17. **Adjust Search Range**
	```cpp
	            r = mid - 1;
	```
	If repair is possible within 'mid' time, narrow the search range by adjusting 'r'.

18. **Adjust Search Range**
	```cpp
	        } else l = mid + 1;
	```
	If repair is not possible within 'mid' time, adjust the lower bound 'l'.

19. **Return Minimum Time**
	```cpp
	    return ans;
	```
	Returns the minimum time required to repair all cars.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log T)
- **Average Case:** O(n log T)
- **Worst Case:** O(n log T)

The binary search takes log(T) iterations, and for each iteration, we check the repair capacity of all mechanics, which takes O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the mechanics' ranks and perform operations on them.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-time-to-repair-cars/description/)

---
{{< youtube yZ1o7WcAwxI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
