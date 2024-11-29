
+++
authors = ["grid47"]
title = "Leetcode 2293: Min Max Game"
date = "2024-03-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2293: Min Max Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZDZ4KQsbnbc"
youtube_upload_date="2022-06-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZDZ4KQsbnbc/maxresdefault.webp"
comments = true
+++



---
You are given an integer array nums where the length of the array is a power of 2. The task is to apply a repeated algorithm to reduce the array size. In each iteration, if the index of an element is even, the new value at that index will be the minimum of two adjacent elements; if the index is odd, the new value will be the maximum. The process continues until only one element remains, which is the result.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array nums of integers where the length is a power of 2.
- **Example:** `Input: nums = [2, 4, 6, 8, 10, 12, 14, 16]`
- **Constraints:**
	- 1 <= nums.length <= 1024
	- nums.length is a power of 2
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the last number that remains in the array after applying the reduction algorithm repeatedly.
- **Example:** `Output: 8`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reduce the array by repeatedly applying the described transformation. In each iteration, alternate positions are filled with the minimum or maximum values of adjacent elements.

- Step 1: Begin with the full array.
- Step 2: Create a new array by replacing elements at even indices with the minimum of two adjacent elements and elements at odd indices with the maximum.
- Step 3: Replace the original array with the new array and repeat the process.
- Step 4: Continue until only one element remains in the array, which is returned as the result.
{{< dots >}}
### Problem Assumptions ✅
- The length of the array is guaranteed to be a power of 2.
- The integer values in the array are valid and within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 5, 7]`  \
  **Explanation:** In the first iteration: newNums = [min(1, 3), max(5, 7)] = [1, 7]. Then, the next iteration gives newNums = [1]. The last remaining element is 1.

- **Input:** `Input: nums = [2, 4, 6, 8, 10, 12, 14, 16]`  \
  **Explanation:** After the first iteration, nums = [2, 6, 10, 14], and in subsequent iterations, nums = [2, 10], and finally, nums = [8].

{{< dots >}}
## Approach 🚀
The approach involves recursively applying the reduction algorithm to the array until only one element remains. In each iteration, you need to build a new array based on the minimum and maximum values of adjacent pairs.

### Initial Thoughts 💭
- The array's size reduces by half in each iteration.
- The process continues recursively until only one element is left.
- The problem can be solved efficiently by using a recursive approach to apply the transformation on smaller arrays.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty, as the length of the array is guaranteed to be at least 1.
- For large arrays (up to size 1024), ensure that the algorithm efficiently reduces the array size in each iteration.
- Arrays with identical values will always return that value as the result.
- The array will always be a power of 2, and the number of iterations will be logarithmic with respect to the array size.
{{< dots >}}
## Code 💻
```cpp
int minMaxGame(vector<int>& nums) {
    int n = nums.size(); 
    if(n==1) return nums[0];  // Base case
    vector<int> newNum(n/2); 
    for(int i=0; i<n/2; i++) { 
        if(i%2==0) newNum[i] = min(nums[2 * i], nums[2 * i + 1]); 
        else newNum[i] = max(nums[2 * i], nums[2 * i + 1]); 
    } 
    int res = minMaxGame(newNum); // Recursive call
    return res;
}
```

The function `minMaxGame` recursively reduces the size of the input array by choosing the minimum or maximum between adjacent elements in pairs, alternating between minimum and maximum at each step, until the array is reduced to one element. This element is then returned as the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minMaxGame(vector<int>& nums) {
	```
	The function `minMaxGame` is declared, which takes a reference to a vector of integers `nums` and returns an integer. This function aims to reduce the input vector based on alternating min and max operations.

2. **Get Array Size**
	```cpp
	    int n = nums.size(); 
	```
	The size of the input vector `nums` is calculated and stored in the variable `n`.

3. **Base Case Check**
	```cpp
	    if(n==1) return nums[0];  // Base case
	```
	A base case is checked: if the vector has only one element, that element is returned as the result.

4. **Create New Vector**
	```cpp
	    vector<int> newNum(n/2); 
	```
	A new vector `newNum` of size `n/2` is created to store the results of the alternating min and max operations.

5. **Iterate Over Vector**
	```cpp
	    for(int i=0; i<n/2; i++) { 
	```
	A for-loop is initiated to iterate through the input vector `nums` in steps of two, processing pairs of elements.

6. **Min Operation**
	```cpp
	        if(i%2==0) newNum[i] = min(nums[2 * i], nums[2 * i + 1]); 
	```
	For even indexed iterations, the minimum of the two adjacent elements in `nums` is stored in `newNum[i]`.

7. **Max Operation**
	```cpp
	        else newNum[i] = max(nums[2 * i], nums[2 * i + 1]); 
	```
	For odd indexed iterations, the maximum of the two adjacent elements in `nums` is stored in `newNum[i]`.

8. **Recursive Call**
	```cpp
	    int res = minMaxGame(newNum); // Recursive call
	```
	The function `minMaxGame` is called recursively with the newly created vector `newNum` as the input.

9. **Return Result**
	```cpp
	    return res;
	```
	The result of the recursive call is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) for each iteration, and there are log(n) iterations in total. Hence, the overall complexity is O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) since we create a new array of half the size of the original array in each iteration.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/min-max-game/description/)

---
{{< youtube ZDZ4KQsbnbc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
