
+++
authors = ["grid47"]
title = "Leetcode 16: 3Sum Closest"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 16: 3Sum Closest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/16.webp"
youtube = "PXWT4wzkA6M"
youtube_upload_date="2024-07-29"
youtube_thumbnail="https://i.ytimg.com/vi/PXWT4wzkA6M/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/16.webp" 
    alt="Three glowing points forming a close triangle, with the central point shimmering in light."
    caption="Solution to LeetCode 16: 3Sum Closest Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums and an integer target. Find three integers in nums such that the sum is closest to the target. Return the sum of those three integers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer target.
- **Example:** `nums = [1, 2, 3, -4], target = 3`
- **Constraints:**
	- 3 <= nums.length <= 500
	- -1000 <= nums[i] <= 1000
	- -10^4 <= target <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the three integers whose sum is closest to the target.
- **Example:** `3`
- **Constraints:**
	- The sum should be the closest to the target.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find three integers in the array whose sum is closest to the given target.

- Sort the input array.
- Iterate through the array, fixing one element and using a two-pointer technique to find the other two elements.
- Track the sum of the triplet and check how close it is to the target.
- Return the closest sum.
{{< dots >}}
### Problem Assumptions ✅
- There is exactly one solution, so there is no need to check for multiple solutions.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3, -4], target = 3`  \
  **Explanation:** The closest sum to the target is 3. (1 + 2 + 3 = 3).

- **Input:** `nums = [0, 0, 0], target = 5`  \
  **Explanation:** The closest sum to the target 5 is 0. (0 + 0 + 0 = 0).

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves sorting the array first and then using the two-pointer technique to find the closest sum.

### Initial Thoughts 💭
- Sorting helps in finding the closest sum using the two-pointer technique efficiently.
- The problem requires comparing the sum of different triplets and finding the one closest to the target.
- We need to iterate through the array, fixing one element and using two pointers to explore potential sums.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least 3 elements.
- The solution should be efficient for arrays up to 500 elements.
- The array may contain both negative and positive numbers, which should be handled correctly.
- The solution should handle negative, zero, and positive numbers efficiently.
{{< dots >}}
## Code 💻
```cpp
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int front;
    int sum = nums[0] + nums[1] + nums[2], sum1 = 0;

    for(int i = 0; i < nums.size(); i++) {

        front = i + 1;

        int back = nums.size() - 1;

        while( front < back ) {

            sum1 = nums[front] + nums[back] + nums[i];

            if (abs(sum1-target) <= abs(sum-target)) sum = sum1;

                 if(sum1 > target) back--;
            else if(sum1 < target) front++;
            else return sum1;

        }
    }

    return sum;
}
```

This code implements the `threeSumClosest` function, which finds the triplet in the array `nums` that has the sum closest to the target value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int threeSumClosest(vector<int>& nums, int target) {
	```
	Declare the `threeSumClosest` function, which takes a vector of integers `nums` and a target integer `target` as input and returns the closest sum to the target.

2. **Sorting Operations**
	```cpp
	    sort(nums.begin(),nums.end());
	```
	Sort the `nums` vector in ascending order.

3. **Variable Initialization**
	```cpp
	    int front;
	```
	Declare a variable `front` to be used as a pointer in the two-pointer approach.

4. **Variable Initialization**
	```cpp
	    int sum = nums[0] + nums[1] + nums[2], sum1 = 0;
	```
	Initialize `sum` with the sum of the first three elements as an initial closest sum. Initialize `sum1` to store the current sum of three elements.

5. **Loop Iteration**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Start a loop to iterate through each element `nums[i]` in the sorted array.

6. **Variable Initialization**
	```cpp
	        front = i + 1;
	```
	Initialize `front` to point to the element after `nums[i]`. This will be the left pointer in the two-pointer approach.

7. **Variable Initialization**
	```cpp
	        int back = nums.size() - 1;
	```
	Initialize `back` to point to the last element of the array. This will be the right pointer in the two-pointer approach.

8. **Loop Iteration**
	```cpp
	        while( front < back ) {
	```
	Start a two-pointer loop to find the closest sum to the target.

9. **Calculations**
	```cpp
	            sum1 = nums[front] + nums[back] + nums[i];
	```
	Calculate the sum of the current three elements `nums[i]`, `nums[front]`, and `nums[back]`.

10. **Conditional Update**
	```cpp
	            if (abs(sum1-target) <= abs(sum-target)) sum = sum1;
	```
	Check if the absolute difference between the current sum `sum1` and the target is less than or equal to the current minimum difference. If so, update `sum` to the current `sum1`.

11. **Conditional Update**
	```cpp
	                 if(sum1 > target) back--;
	```
	If the current sum `sum1` is greater than the target, move the `back` pointer to the left to decrease the sum.

12. **Conditional Update**
	```cpp
	            else if(sum1 < target) front++;
	```
	If the current sum `sum1` is less than the target, move the `front` pointer to the right to increase the sum.

13. **Return Value**
	```cpp
	            else return sum1;
	```
	If the current sum `sum1` is exactly equal to the target, return it as the closest sum.

14. **Return Value**
	```cpp
	    return sum;
	```
	Return the closest sum `sum` found after iterating through all possible triplets.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we iterate over the array and use two pointers to find the closest sum.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because no additional space is used except for a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/3sum-closest/description/)

---
{{< youtube PXWT4wzkA6M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
