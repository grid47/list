
+++
authors = ["grid47"]
title = "Leetcode 2971: Find Polygon With the Largest Perimeter"
date = "2024-01-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2971: Find Polygon With the Largest Perimeter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Yk9Mor-Y488"
youtube_upload_date="2024-02-15"
youtube_thumbnail="https://i.ytimg.com/vi/Yk9Mor-Y488/maxresdefault.jpg"
comments = true
+++



---
You are given an array `nums` consisting of positive integers. A polygon can be formed from the integers if it satisfies the following condition: the sum of the lengths of any `k-1` sides must be greater than the length of the remaining side. The perimeter of a polygon is the sum of the lengths of its sides. Your task is to find the largest possible perimeter of a polygon that can be formed using the sides from `nums`, or return `-1` if it is not possible to form such a polygon.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of positive integers. The task is to determine the largest possible perimeter of a polygon that can be made from the elements in `nums`.
- **Example:** `nums = [4, 6, 7, 3]`
- **Constraints:**
	- 3 <= n <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest possible perimeter of a polygon that can be formed using the elements in `nums`, or return `-1` if no valid polygon can be made.
- **Example:** `Output: 17`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the largest possible perimeter of a polygon formed by the sides in `nums`. The key condition is that the sum of the lengths of any `k-1` sides must be greater than the length of the remaining side.

- Sort the array `nums` in ascending order.
- Iterate through the array from the largest element and check if the sum of all elements smaller than the current element is greater than the current element.
- If the condition is met, return the sum of the elements that form the polygon (perimeter).
- If no valid polygon can be formed, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The array is guaranteed to have at least three integers, as this is a requirement for forming a polygon.
- All elements in the array are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [4, 6, 7, 3]`  \
  **Explanation:** The array is sorted as [3, 4, 6, 7]. We can form a polygon with sides 3, 4, 6, and 7. The sum of the sides is 17, which is the largest perimeter that can be formed.

- **Input:** `Input: nums = [8, 10, 2, 1, 5, 7]`  \
  **Explanation:** The sorted array is [1, 2, 5, 7, 8, 10]. A polygon can be formed with sides 1, 2, 5, 7, and 10. The perimeter is 25.

- **Input:** `Input: nums = [10, 20, 30]`  \
  **Explanation:** The sorted array is [10, 20, 30]. We cannot form a polygon because the longest side 30 is greater than the sum of the other two sides (10 + 20).

{{< dots >}}
## Approach 🚀
Sort the array `nums` and iterate through the elements to check if a valid polygon can be formed. If the condition for the polygon is met, return the perimeter; otherwise, return -1.

### Initial Thoughts 💭
- We need to find the largest possible perimeter, so sorting the array in ascending order helps to check if the largest side is smaller than the sum of the others.
- The sorting helps efficiently check if the sum of any `k-1` sides is greater than the largest side.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least three elements in `nums`, as per the constraints.
- The array can contain up to 10^5 elements, so the solution must handle large inputs efficiently.
- Ensure that the largest side is not greater than the sum of the other sides for a valid polygon.
- The array must have at least three elements, and all elements are positive integers.
{{< dots >}}
## Code 💻
```cpp
long long largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<long long> sum(n, 0);
    sum[0] = nums[0];
    for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
    for(int i = n - 1; i >= 2; i--)
        if(nums[i] < sum[i - 1])
            return sum[i];
    return -1;
}
```

This function computes the largest perimeter of a triangle that can be formed by selecting three sides from the given array. It first sorts the array, calculates cumulative sums, and checks for valid triangle sides using the triangle inequality theorem. If no valid perimeter is found, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long largestPerimeter(vector<int>& nums) {
	```
	Defines the function `largestPerimeter` that takes a reference to an integer array `nums` and returns a long long value representing the largest valid perimeter of a triangle that can be formed.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes the variable `n` to store the size of the input array `nums`.

3. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the array `nums` in ascending order to ensure that the largest sides come at the end for easier comparison.

4. **Cumulative Sum Calculation**
	```cpp
	    vector<long long> sum(n, 0);
	```
	Initializes a vector `sum` to store the cumulative sums of the sorted array `nums`. The size of `sum` is equal to `n`.

5. **Cumulative Sum Initialization**
	```cpp
	    sum[0] = nums[0];
	```
	Sets the first element of the `sum` array equal to the first element of `nums`.

6. **Cumulative Sum Loop**
	```cpp
	    for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
	```
	Calculates the cumulative sum for each element in `nums`, storing the result in `sum`. The value of `sum[i]` holds the sum of the first `i+1` elements from `nums`.

7. **Triangle Inequality Check Loop**
	```cpp
	    for(int i = n - 1; i >= 2; i--)
	```
	Starts a loop from the last element of the sorted array and moves backward. The loop continues until there are at least three elements to form a triangle.

8. **Triangle Inequality Condition**
	```cpp
	        if(nums[i] < sum[i - 1])
	```
	Checks if the current side `nums[i]` can form a valid triangle by comparing it to the sum of the previous two sides (triangle inequality).

9. **Return Valid Perimeter**
	```cpp
	            return sum[i];
	```
	If the condition is met, return the perimeter of the triangle formed by `nums[i]`, `nums[i-1]`, and `nums[i-2]`, which is the cumulative sum up to `i`.

10. **Return Invalid Case**
	```cpp
	    return -1;
	```
	If no valid perimeter can be formed (i.e., no valid triangle found), return `-1`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the array takes O(n log n), and the scan through the array takes O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the sorting operation, which requires additional space for the sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/)

---
{{< youtube Yk9Mor-Y488 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
