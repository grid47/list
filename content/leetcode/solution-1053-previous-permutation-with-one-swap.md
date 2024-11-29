
+++
authors = ["grid47"]
title = "Leetcode 1053: Previous Permutation With One Swap"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1053: Previous Permutation With One Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "x_y3nIsbENM"
youtube_upload_date="2021-03-01"
youtube_thumbnail="https://i.ytimg.com/vi/x_y3nIsbENM/maxresdefault.jpg"
comments = true
+++



---
Given an array of positive integers, return the lexicographically largest permutation that is smaller than the given array. This can be done by swapping exactly two elements. If no such swap is possible (i.e., the array is already the smallest permutation), return the same array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers arr where each element is a positive integer. You need to return the lexicographically largest permutation smaller than arr that can be made by swapping exactly two numbers in the array.
- **Example:** `Input: arr = [5, 3, 4, 2, 1]`
- **Constraints:**
	- 1 <= arr.length <= 10^4
	- 1 <= arr[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the lexicographically largest permutation that is smaller than the given array, obtained by swapping exactly two elements. If no such swap exists, return the input array as is.
- **Example:** `Output: [5, 4, 3, 2, 1]`
- **Constraints:**
	- The output is guaranteed to be a valid array of integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the lexicographically largest permutation smaller than the given array by swapping two elements.

- 1. Find the first pair of adjacent elements where arr[i] > arr[i+1] (this is where the lexicographical order breaks).
- 2. Swap the first element arr[i] with the largest element in the suffix of the array that is smaller than arr[i].
- 3. If no such pair exists, return the array as is, because it is already the smallest permutation.
{{< dots >}}
### Problem Assumptions ✅
- The array contains positive integers and the length of the array is between 1 and 10,000.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [5, 3, 4, 2, 1]`  \
  **Explanation:** The largest permutation smaller than [5, 3, 4, 2, 1] is obtained by swapping 3 and 4, resulting in [5, 4, 3, 2, 1].

- **Input:** `Input: arr = [1, 2, 3]`  \
  **Explanation:** Since the array is already in ascending order, no swap can make a smaller permutation. Therefore, the output is the same as the input: [1, 2, 3].

{{< dots >}}
## Approach 🚀
The approach involves finding the first pair of adjacent elements where the order breaks and then swapping the first element with the largest element from the suffix of the array that is smaller than the first element. This ensures that the resulting permutation is the largest possible smaller permutation.

### Initial Thoughts 💭
- We need to identify the point where the permutation can be swapped to form a smaller arrangement.
- The array might already be in the smallest lexicographical order.
- The key is to find where the array stops being in descending order and use that information to swap the necessary elements.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs because the array will always have at least one element.
- The algorithm needs to efficiently handle inputs up to 10,000 elements in length.
- If the array is already sorted in ascending order, no valid swap can be made.
- The array will always have positive integers.
{{< dots >}}
## Code 💻
```cpp
vector<int> prevPermOpt1(vector<int>& arr) {
    int idx = -1, n = arr.size();
    for(int i = n - 1; i > 0; i--) {
        // cout<< arr[i] << " " << arr[i - 1] << '\n';
        if(arr[i] < arr[i - 1]) {
            idx = i - 1;
            break;
        }
    }
    // cout << idx;
    if(idx == -1) return arr;

    for(int i = n - 1; i > idx; i--) {
        if(arr[i] < arr[idx] && arr[i] != arr[i - 1]) {
            swap(arr[i], arr[idx]);
            break;
        }
    }
    return arr;
}
```

The code provides a solution for finding the previous permutation of an array. It works by identifying the first decrease in the array from the right, then swapping it with a smaller element to get the largest permutation smaller than the current one.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> prevPermOpt1(vector<int>& arr) {
	```
	This line defines the function `prevPermOpt1` which takes a reference to a vector of integers `arr` and returns a vector of integers. It aims to find the previous permutation of the array.

2. **Variable Initialization**
	```cpp
	    int idx = -1, n = arr.size();
	```
	Here, `idx` is initialized to -1 to track the position where a decrease is found, and `n` stores the size of the array.

3. **Loop**
	```cpp
	    for(int i = n - 1; i > 0; i--) {
	```
	This loop iterates through the array in reverse order, starting from the second last element and going towards the first.

4. **Condition**
	```cpp
	        if(arr[i] < arr[i - 1]) {
	```
	This condition checks if the current element is smaller than the previous element. If true, it indicates a possible swap location.

5. **Update Index**
	```cpp
	            idx = i - 1;
	```
	If a decrease is found, the index `idx` is set to `i - 1`, indicating the position where the swap needs to occur.

6. **Break Statement**
	```cpp
	            break;
	```
	The loop breaks as soon as a decrease is found, as no further checking is needed.

7. **Edge Case Handling**
	```cpp
	    if(idx == -1) return arr;
	```
	If no decrease is found (i.e., the array is sorted in ascending order), the function returns the original array, as no previous permutation exists.

8. **Second Loop**
	```cpp
	    for(int i = n - 1; i > idx; i--) {
	```
	This second loop searches for the largest element smaller than `arr[idx]` to swap it with.

9. **Swap Condition**
	```cpp
	        if(arr[i] < arr[idx] && arr[i] != arr[i - 1]) {
	```
	This condition ensures that the element to swap is smaller than `arr[idx]` and is not equal to the previous element, preventing unnecessary swaps.

10. **Swap Operation**
	```cpp
	            swap(arr[i], arr[idx]);
	```
	The two elements at indices `i` and `idx` are swapped, creating the next smaller permutation.

11. **Break Statement**
	```cpp
	            break;
	```
	The loop breaks once the swap is made, as only one swap is needed.

12. **Return Statement**
	```cpp
	    return arr;
	```
	The function returns the modified array after the swap.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, we perform linear scans through the array, so the time complexity is O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a constant amount of extra space, aside from the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/previous-permutation-with-one-swap/description/)

---
{{< youtube x_y3nIsbENM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
