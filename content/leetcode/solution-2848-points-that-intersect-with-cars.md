
+++
authors = ["grid47"]
title = "Leetcode 2848: Points That Intersect With Cars"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2848: Points That Intersect With Cars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "86n-e3Zwx34"
youtube_upload_date="2023-09-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/86n-e3Zwx34/maxresdefault.webp"
comments = true
+++



---
You are given a list of cars represented by their starting and ending positions on a number line. Your task is to count how many distinct integer points are covered by any part of a car.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A list of pairs representing the start and end positions of each car on the number line.
- **Example:** `nums = [[1, 4], [2, 5], [6, 7]]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- nums[i].length == 2
	- 1 <= starti <= endi <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The total number of distinct integer points covered by any part of a car.
- **Example:** `Output: 6`
- **Constraints:**
	- The output should be a single integer representing the total number of distinct integer points.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the total number of distinct integer points covered by any part of a car.

- Create a boolean array to represent the points on the number line that are covered by a car.
- For each car, mark the points it covers as true in the array.
- Count the number of true values in the array, which represents the total number of covered points.
{{< dots >}}
### Problem Assumptions ✅
- All cars have valid starting and ending positions where starti <= endi.
- The cars may overlap, but each point on the number line is counted only once.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [[1, 4], [2, 5], [6, 7]]`  \
  **Explanation:** The integer points covered by the cars are: 1, 2, 3, 4, 5, 6. Hence, the total number of points covered is 6.

- **Input:** `nums = [[1, 3], [4, 6], [5, 8]]`  \
  **Explanation:** The integer points covered by the cars are: 1, 2, 3, 4, 5, 6, 7, 8. After removing duplicates, the answer is 6.

{{< dots >}}
## Approach 🚀
The approach involves creating an array to mark the covered integer points and then counting how many distinct points are covered by any of the cars.

### Initial Thoughts 💭
- We need to track the integer points on the number line covered by the cars.
- The positions of the cars may overlap, so we need to count each point only once.
- We can use a boolean array to mark covered points and count the true values to find the answer.
{{< dots >}}
### Edge Cases 🌐
- No empty input arrays are expected as per the problem statement.
- The solution should handle the maximum number of cars efficiently.
- Cars with the same start and end position should still be counted correctly.
- The approach should work within the time and space constraints provided.
{{< dots >}}
## Code 💻
```cpp
int numberOfPoints(vector<vector<int>>& nums) {
vector<int> v(102, 0);
int ans = 0;
for(auto n: nums){
    for(int i = n[0]; i <= n[1]; ++i) v[i-1]++;
}
for(auto e: v){
    if(e) ans++;
}
return ans;
}
```

This function calculates the number of distinct points covered by a set of ranges represented as pairs of integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numberOfPoints(vector<vector<int>>& nums) {
	```
	Defines the function 'numberOfPoints', which takes a vector of integer pairs as input representing ranges.

2. **Vector Initialization**
	```cpp
	vector<int> v(102, 0);
	```
	Initializes a vector 'v' of size 102 to track the frequency of each point in the range, all initialized to zero.

3. **Variable Initialization**
	```cpp
	int ans = 0;
	```
	Declares and initializes an integer variable 'ans' to store the count of distinct points covered by the ranges.

4. **Outer Loop**
	```cpp
	for(auto n: nums){
	```
	Starts a loop to iterate over each range in the input vector 'nums'. Each range is represented by a pair of integers.

5. **Inner Loop**
	```cpp
	    for(int i = n[0]; i <= n[1]; ++i) v[i-1]++;
	```
	For each range, this loop increments the corresponding index in the vector 'v' for each point between the range's start and end (inclusive).

6. **Count Points**
	```cpp
	for(auto e: v){
	```
	Starts a loop to iterate over the elements of the vector 'v' to count how many distinct points are covered.

7. **Condition Check**
	```cpp
	    if(e) ans++;
	```
	Increments 'ans' whenever a point is covered (i.e., the count at that index is greater than zero).

8. **Return Statement**
	```cpp
	return ans;
	```
	Returns the total count of distinct points covered by the ranges.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of cars, as we iterate over each car and the points it covers.

### Space Complexity 💾
- **Best Case:** O(101)
- **Worst Case:** O(101)

The space complexity is O(101) because we use an array of size 101 to track covered points.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/points-that-intersect-with-cars/description/)

---
{{< youtube 86n-e3Zwx34 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
