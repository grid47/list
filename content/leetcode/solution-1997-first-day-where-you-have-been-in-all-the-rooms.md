
+++
authors = ["grid47"]
title = "Leetcode 1997: First Day Where You Have Been in All the Rooms"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1997: First Day Where You Have Been in All the Rooms in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GYyHxkGO4J0"
youtube_upload_date="2021-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/GYyHxkGO4J0/maxresdefault.jpg"
comments = true
+++



---
You are given a list of rooms and their visiting order for each day based on a set of rules. On each day, you either revisit a room based on the number of visits or proceed to the next room in a cyclic manner. Your task is to find the first day when all rooms have been visited.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list 'nextVisit' of length n (2 <= n <= 100,000), where each element is an integer indicating the next room to visit based on the rules provided.
- **Example:** `nextVisit = [0, 0]`
- **Constraints:**
	- 2 <= n <= 100,000
	- 0 <= nextVisit[i] <= i

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the first day when all rooms have been visited. The answer should be returned modulo 10^9 + 7.
- **Example:** `2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to track how many times each room is visited and determine when all rooms have been visited at least once.

- 1. Use dynamic programming (dp) to track the total number of visits up to each day.
- 2. For each room, depending on whether it has been visited an even or odd number of times, decide the next room to visit.
- 3. Continue until all rooms have been visited at least once, then return the day modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The input list will always contain valid values.
{{< dots >}}
## Examples 🧩
- **Input:** `nextVisit = [0, 0]`  \
  **Explanation:** On day 0, you visit room 0. On day 1, you visit room 0 again, and on day 2, you visit room 1, completing the visit to all rooms.

{{< dots >}}
## Approach 🚀
The solution uses dynamic programming to track the visits and determine when all rooms are visited.

### Initial Thoughts 💭
- We can simulate each day by using a dp array to store the cumulative steps taken and track which room is visited.
- Since the number of rooms is large (up to 100,000), we need an efficient approach to calculate the first day all rooms are visited.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees a minimum input length of 2.
- Ensure that the solution can handle the largest input sizes efficiently within time limits.
- The modulo operation (10^9 + 7) ensures the result remains within valid range.
- The input will always satisfy the constraints.
{{< dots >}}
## Code 💻
```cpp
int n;

int firstDayBeenInAllRooms(vector<int>& nxt) {
    n = nxt.size();
    int mod = (int) 1e9 + 7;
    vector<long long> dp(n, 0); // step
    for(int i = 1; i < n; i++)
        dp[i] = (dp[i - 1] + 1 + (dp[i - 1] - dp[nxt[i - 1]]) + 1 + mod) % mod;
    
    return dp[n - 1];
}
```

This function calculates the minimum number of steps required for the first day to have visited all rooms in a circular array using dynamic programming. It handles large numbers by applying modulo operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int n;
	```
	Declares the variable `n` to store the size of the `nxt` vector, representing the number of rooms.

2. **Function Definition**
	```cpp
	int firstDayBeenInAllRooms(vector<int>& nxt) {
	```
	Defines the function `firstDayBeenInAllRooms`, which takes a reference to a vector `nxt` that represents the connections between rooms, and returns the minimum number of steps modulo 1e9+7.

3. **Array Size Initialization**
	```cpp
	    n = nxt.size();
	```
	Initializes `n` with the size of the `nxt` vector, which represents the total number of rooms.

4. **Modulo Constant Declaration**
	```cpp
	    int mod = (int) 1e9 + 7;
	```
	Declares and initializes the constant `mod` with the value 1e9 + 7, used for modulo operations to prevent overflow.

5. **Dynamic Programming Initialization**
	```cpp
	    vector<long long> dp(n, 0); // step
	```
	Declares a vector `dp` of type `long long` initialized with 0s, which will store the steps for each room. The vector size is `n`.

6. **Loop Start**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Starts a loop from the second room (i=1) to the last room (i<n), calculating the minimum number of steps for each room.

7. **Dynamic Programming Update**
	```cpp
	        dp[i] = (dp[i - 1] + 1 + (dp[i - 1] - dp[nxt[i - 1]]) + 1 + mod) % mod;
	```
	Updates the `dp` value for the current room `i` based on the steps from the previous room, adjusted by the modulo to handle overflow.

8. **Return Statement**
	```cpp
	    return dp[n - 1];
	```
	Returns the value stored in `dp[n-1]`, representing the minimum number of steps required to visit all rooms.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we only iterate through the rooms once, and the calculations for each room are constant time operations.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space needed for the dp array to track visits.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/description/)

---
{{< youtube GYyHxkGO4J0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
