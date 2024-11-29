
+++
authors = ["grid47"]
title = "Leetcode 969: Pancake Sorting"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 969: Pancake Sorting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "O8YUmSwQ2WU"
youtube_upload_date="2021-04-23"
youtube_thumbnail="https://i.ytimg.com/vi/O8YUmSwQ2WU/maxresdefault.jpg"
comments = true
+++



---
You are tasked with sorting an array of integers by performing a series of pancake flips. A pancake flip involves reversing the order of elements from the start of the array up to a specified index. The goal is to determine the sequence of flips needed to sort the array in ascending order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers where each integer is unique and represents a permutation of numbers from 1 to n.
- **Example:** `Input: arr = [5, 1, 4, 2, 3]`
- **Constraints:**
	- 1 <= arr.length <= 100
	- 1 <= arr[i] <= arr.length
	- All integers in arr are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** An array of integers where each value corresponds to the position up to which a pancake flip is performed. The sequence of flips must sort the input array.
- **Example:** `Output: [5, 3, 4, 3, 2]`
- **Constraints:**
	- The number of flips should not exceed 10 * arr.length.

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the array using a series of pancake flips.

- Identify the largest unsorted element in the array.
- Perform a flip to bring the largest element to the beginning of the array.
- Perform another flip to move the largest element to its correct position in the sorted part of the array.
- Repeat until the entire array is sorted.
{{< dots >}}
### Problem Assumptions ✅
- The array contains only integers.
- Each integer in the array is within the range [1, arr.length].
- The input array is a permutation of numbers from 1 to arr.length.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [3, 1, 4, 2]`  \
  **Explanation:** We perform the following flips: 
1. Flip at k = 3: arr = [4, 1, 3, 2]
2. Flip at k = 4: arr = [2, 3, 1, 4]
3. Flip at k = 3: arr = [3, 1, 2, 4]
4. Flip at k = 2: arr = [1, 3, 2, 4]
5. Flip at k = 3: arr = [1, 2, 3, 4]
Final Output: [3, 4, 3, 2, 3]

- **Input:** `Input: arr = [1, 2, 3]`  \
  **Explanation:** The array is already sorted, so no flips are needed. Output: []

{{< dots >}}
## Approach 🚀
The solution involves iteratively moving the largest unsorted element to its correct position using at most two flips per element.

### Initial Thoughts 💭
- A flip only changes the order of elements in the prefix of the array.
- To sort the array, we can repeatedly position the largest unsorted element at its correct location.
- Identify the position of the largest unsorted element.
- Perform a flip to move it to the beginning of the array.
- Perform another flip to place it at its correct position.
{{< dots >}}
### Edge Cases 🌐
- An empty array would not require any flips.
- For an array with maximum length (100), ensure the algorithm completes within 1000 flips.
- An already sorted array should result in no flips.
- Verify that the input is a permutation of integers from 1 to n.
{{< dots >}}
## Code 💻
```cpp
vector<int> pancakeSort(vector<int>& arr) {
    
    
    // find next largest
    // flip its index so that largest come first
    // flip one more time, so that the first goes to end
    
    vector<int> res;
    int i;
    for(int x = arr.size(); x > 0; x--) {
        for(i = 0; arr[i] != x; i++) {};
        reverse(arr.begin(), arr.begin() + i + 1);
        res.push_back(i + 1);
        reverse(arr.begin(), arr.begin() + x);
        res.push_back(x);
    }
    
    return res;
}
```

The `pancakeSort` function sorts an array by flipping segments. The algorithm repeatedly finds the largest unsorted element, flips it to the front, and then flips it into its final position.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> pancakeSort(vector<int>& arr) {
	```
	The function definition begins the implementation of the pancake sorting algorithm.

2. **Variable Initialization**
	```cpp
	    vector<int> res;
	```
	Initialize a vector `res` to store the sequence of flip operations.

3. **Variable Declaration**
	```cpp
	    int i;
	```
	Declare an integer `i` for use in loops and iteration.

4. **Loop Construct**
	```cpp
	    for(int x = arr.size(); x > 0; x--) {
	```
	Start a loop from the size of the array down to 1 to process all unsorted elements.

5. **Loop Iteration**
	```cpp
	        for(i = 0; arr[i] != x; i++) {};
	```
	Find the index `i` of the current largest unsorted element `x`.

6. **Reverse Operation**
	```cpp
	        reverse(arr.begin(), arr.begin() + i + 1);
	```
	Reverse the segment of the array from the start to index `i` to bring the largest element to the front.

7. **Vector Operation**
	```cpp
	        res.push_back(i + 1);
	```
	Record the flip operation by adding `i + 1` (1-based index) to the result vector.

8. **Reverse Operation**
	```cpp
	        reverse(arr.begin(), arr.begin() + x);
	```
	Reverse the segment of the array from the start to index `x`, moving the largest element to its final position.

9. **Vector Operation**
	```cpp
	        res.push_back(x);
	```
	Record the second flip operation by adding `x` (the size of the remaining unsorted segment) to the result vector.

10. **Return Statement**
	```cpp
	    return res;
	```
	Return the result vector containing the sequence of flip operations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The worst case involves performing two flips for each of the n elements, resulting in O(n^2) complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution operates in-place, so the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/pancake-sorting/description/)

---
{{< youtube O8YUmSwQ2WU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
