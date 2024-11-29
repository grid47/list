
+++
authors = ["grid47"]
title = "Leetcode 2857: Count Pairs of Points With Distance k"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2857: Count Pairs of Points With Distance k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Z7hDq-nGzUI"
youtube_upload_date="2023-09-16"
youtube_thumbnail="https://i.ytimg.com/vi/Z7hDq-nGzUI/maxresdefault.jpg"
comments = true
+++



---
Given a list of 2D points and an integer k, find the number of pairs of points whose distance (calculated as XOR sum of their coordinates) equals k.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of 2D points and an integer k.
- **Example:** `coordinates = [[1, 2], [4, 2], [1, 3], [5, 2]], k = 5`
- **Constraints:**
	- 2 <= coordinates.length <= 50000
	- 0 <= xi, yi <= 10^6
	- 0 <= k <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of pairs (i, j) where i < j and the distance between points i and j equals k.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is an integer representing the number of valid pairs.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the number of valid pairs of points whose XOR-based distance equals k.

- Initialize a hash map to store the count of points encountered so far.
- Iterate through the points and for each point, calculate the potential pairings that result in the required distance k.
- For each valid pair, increment the result count.
- Return the final result.
{{< dots >}}
### Problem Assumptions ✅
- The input coordinates are non-negative integers.
- The value of k is not negative.
{{< dots >}}
## Examples 🧩
- **Input:** `coordinates = [[1, 2], [4, 2], [1, 3], [5, 2]], k = 5`  \
  **Explanation:** Valid pairs (0, 1) and (2, 3) both have a distance of 5.

- **Input:** `coordinates = [[1, 3], [1, 3], [1, 3], [1, 3], [1, 3]], k = 0`  \
  **Explanation:** Any two points have a distance of 0, so there are 10 ways to select two points from the list.

{{< dots >}}
## Approach 🚀
Use a hash map to efficiently count valid pairs of points whose XOR distance is equal to k.

### Initial Thoughts 💭
- The problem requires efficiently finding pairs of points that satisfy the XOR distance condition.
- Using a hash map allows us to track previously encountered points and quickly check if a valid pair can be formed.
- The key insight is to iterate through the points and use XOR operations to find potential valid pairs that give the desired distance.
{{< dots >}}
### Edge Cases 🌐
- If the input array contains fewer than 2 points, no pairs can be formed.
- For large input sizes, ensure that the solution runs efficiently within the time limit.
- If all points have the same coordinates, only pairs with distance 0 can be formed.
- Make sure the solution can handle the maximum possible value for k (100) and large input sizes.
{{< dots >}}
## Code 💻
```cpp
int countPairs(vector<vector<int>>& coordinates, int k) {
    unordered_map<int, unordered_map<int, int>> count;
    int res = 0;
    for (auto& c : coordinates) {
        for (int x = 0; x <= k; x++)
            if (count[c[0] ^ x].count(c[1] ^ (k - x)))
                res += count[c[0] ^ x][c[1] ^ (k - x)];
        count[c[0]][c[1]]++;
    }
    return res;
}
```

This function counts the number of valid pairs of coordinates from a list where the sum of XORed values satisfies a condition determined by `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int countPairs(vector<vector<int>>& coordinates, int k) {
	```
	Defines the function `countPairs` that takes in a 2D vector `coordinates` and an integer `k`. It will calculate the number of pairs of coordinates with specific properties.

2. **Data Structure Initialization**
	```cpp
	    unordered_map<int, unordered_map<int, int>> count;
	```
	Initializes a nested unordered map `count` to keep track of coordinate pairs and their counts using XOR as the key.

3. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Declares and initializes an integer variable `res` to store the count of valid pairs found during the loop.

4. **Outer Loop**
	```cpp
	    for (auto& c : coordinates) {
	```
	Iterates over each coordinate `c` in the given 2D vector `coordinates`.

5. **Inner Loop**
	```cpp
	        for (int x = 0; x <= k; x++)
	```
	Nested loop that iterates over possible values of `x` from `0` to `k`.

6. **Condition Check**
	```cpp
	            if (count[c[0] ^ x].count(c[1] ^ (k - x)))
	```
	Checks if there is a previously seen coordinate pair (after XORing with `x` and `k-x`) in the `count` map.

7. **Result Update**
	```cpp
	                res += count[c[0] ^ x][c[1] ^ (k - x)];
	```
	If the condition is true, it adds the count of matching coordinate pairs to the result `res`.

8. **Map Update**
	```cpp
	        count[c[0]][c[1]]++;
	```
	Updates the count of the current coordinate pair `c[0]` and `c[1]` in the map `count`.

9. **Return Statement**
	```cpp
	    return res;
	```
	Returns the final count of valid pairs stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) due to the use of a hash map and iterating over the points once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the points in a hash map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-pairs-of-points-with-distance-k/description/)

---
{{< youtube Z7hDq-nGzUI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
