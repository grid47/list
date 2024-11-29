
+++
authors = ["grid47"]
title = "Leetcode 436: Find Right Interval"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 436: Find Right Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/436.webp"
youtube = "VEBbumHmps8"
youtube_upload_date="2020-08-27"
youtube_thumbnail="https://i.ytimg.com/vi/VEBbumHmps8/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGF0gZSgsMA8=&rs=AOn4CLA_6ZuhHcyS8kFS3ijdD_BdUQyq8A"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/436.webp" 
    alt="A series of intervals, with each right interval softly lighting up as it is found for each point."
    caption="Solution to LeetCode 436: Find Right Interval Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of intervals, where each interval is represented by a pair of integers [start, end], and the start value is unique. For each interval, find the right interval. The right interval for an interval i is an interval j such that start[j] >= end[i] and the start[j] is minimized. If no right interval exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of intervals, where each interval is represented as a pair of integers [start, end]. Each start value is unique.
- **Example:** `intervals = [[5, 8], [10, 15], [6, 10], [2, 5]]`
- **Constraints:**
	- 1 <= intervals.length <= 2 * 10^4
	- -10^6 <= start[i] <= end[i] <= 10^6
	- The start value of each interval is unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element is the index of the right interval for the corresponding input interval. If no right interval exists for a given interval, return -1.
- **Example:** `[0, -1, 1]`
- **Constraints:**
	- The output array should have the same length as the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently find the right interval for each given interval.

- 1. Create a map of interval start values to their indices.
- 2. For each interval, use the map to find the first interval whose start value is greater than or equal to the end value of the current interval.
- 3. If such an interval is found, store its index. If not, store -1.
{{< dots >}}
### Problem Assumptions ✅
- The intervals are sorted based on their start times or can be sorted to facilitate efficient searching.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[5, 8]]`  \
  **Explanation:** There is only one interval, so there is no right interval, and the result is -1.

- **Input:** `Input: [[10, 15], [6, 10], [2, 5]]`  \
  **Explanation:** For the interval [10, 15], there is no right interval. For [6, 10], the right interval is [10, 15]. For [2, 5], the right interval is [6, 10].

- **Input:** `Input: [[1, 4], [2, 5], [5, 9]]`  \
  **Explanation:** For [1, 4], there is no right interval. For [2, 5], the right interval is [5, 9]. For [5, 9], there is no right interval.

{{< dots >}}
## Approach 🚀
The approach involves mapping each interval's start value to its index and then using a search strategy to efficiently find the right interval.

### Initial Thoughts 💭
- Using a map to store the start values of intervals allows for efficient lookups when searching for the right interval.
- By leveraging the map and lower bound search, we can minimize the time complexity compared to a brute force search.
{{< dots >}}
### Edge Cases 🌐
- If the intervals array is empty, return an empty array.
- Ensure that the solution can handle up to 20,000 intervals efficiently.
- If an interval has the largest possible end value (10^6), ensure that the algorithm still works as expected.
- Handle cases where no right intervals exist for any interval.
{{< dots >}}
## Code 💻
```cpp
vector<int> findRightInterval(vector<vector<int>>& iv) {
    map<int, int> mk;
    
    int n = iv.size();
    for(int i = 0; i < n; i++)
        mk[iv[i][0]] = i;
    
    vector<int> ans(n, -1);
    for(int j = 0; j < n; j++) {
        auto i= iv[j];
        if(mk.lower_bound(i[1]) != end(mk))
            ans[j] = mk.lower_bound(i[1])->second;
    }
    
    return ans;
}
```

This function identifies the right interval for each interval in the input using a map and binary search to optimize the lookup process.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declarations And Calls**
	```cpp
	vector<int> findRightInterval(vector<vector<int>>& iv) {
	```
	Defines the function to find the right intervals for each given interval.

2. **Data Structure Initialization**
	```cpp
	    map<int, int> mk;
	```
	Initializes a map to store the start points of intervals and their indices for efficient lookup.

3. **Length Of Collection**
	```cpp
	    int n = iv.size();
	```
	Stores the size of the input vector to determine the number of intervals.

4. **For Loops**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Iterates through each interval to populate the map with start points and indices.

5. **Map Insertion**
	```cpp
	        mk[iv[i][0]] = i;
	```
	Maps the start point of each interval to its index for quick retrieval.

6. **Variable Initialization**
	```cpp
	    vector<int> ans(n, -1);
	```
	Initializes the answer vector with -1 for all elements, indicating no right interval found initially.

7. **For Loops**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Iterates through each interval to find its right interval using the map.

8. **Variable Assignment**
	```cpp
	        auto i= iv[j];
	```
	Assigns the current interval to a temporary variable for easier reference.

9. **Conditional Checks**
	```cpp
	        if(mk.lower_bound(i[1]) != end(mk))
	```
	Checks if there is a start point greater than or equal to the current interval's end point.

10. **Assignment**
	```cpp
	            ans[j] = mk.lower_bound(i[1])->second;
	```
	Finds and assigns the index of the right interval using the map's lower_bound function.

11. **Return At End**
	```cpp
	    return ans;
	```
	Returns the final answer vector containing indices of right intervals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N log N), where N is the number of intervals, due to the sorting of intervals and map operations.
- **Average Case:** O(N log N), as searching the map for each interval takes logarithmic time.
- **Worst Case:** O(N log N), where N is the number of intervals, due to the need to search the map for each interval.

The solution involves sorting the intervals and performing map lookups, leading to a time complexity of O(N log N).

### Space Complexity 💾
- **Best Case:** O(N), for storing the map and output array.
- **Worst Case:** O(N), where N is the number of intervals, to store the map and the output array.

The space complexity is O(N) due to the storage requirements for the map and the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-right-interval/description/)

---
{{< youtube VEBbumHmps8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
