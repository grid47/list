
+++
authors = ["grid47"]
title = "Leetcode 1502: Can Make Arithmetic Progression From Sequence"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1502: Can Make Arithmetic Progression From Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "crVb-Fubs0w"
youtube_upload_date="2020-07-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/crVb-Fubs0w/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers. Your task is to determine if the array can be rearranged to form an arithmetic progression. The array can be rearranged in any order, and the common difference between consecutive elements should be the same.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers, arr.
- **Example:** `[10, 20, 30]`
- **Constraints:**
	- 2 <= arr.length <= 1000
	- -10^6 <= arr[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean indicating whether the array can be rearranged to form an arithmetic progression.
- **Example:** `true`
- **Constraints:**
	- The array can have negative or positive numbers, and it may be sorted or unsorted initially.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if the array can be rearranged into an arithmetic progression with a constant difference between consecutive elements.

- Find the minimum and maximum values in the array.
- Check if the difference between the maximum and minimum values is divisible by the number of elements minus one.
- Calculate the common difference (d) using the formula (max - min) / (arr.size() - 1).
- Try to place each element in its correct position according to the common difference. If any element cannot be placed correctly, return false.
- If all elements are placed correctly, return true.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least two elements.
{{< dots >}}
## Examples 🧩
- **Input:** `[10, 20, 30]`  \
  **Explanation:** The elements can be rearranged to form an arithmetic progression with a common difference of 10.

- **Input:** `[1, 2, 4]`  \
  **Explanation:** The elements cannot be rearranged to form an arithmetic progression, as the difference between 2 and 4 is not consistent with any other pair of elements.

{{< dots >}}
## Approach 🚀
We will first find the minimum and maximum values in the array and then check if the difference between these two values is divisible by the number of elements minus one. Using this difference, we can determine if the array can be rearranged to form an arithmetic progression.

### Initial Thoughts 💭
- An arithmetic progression requires that the difference between any two consecutive elements is constant.
- By calculating the common difference and checking if we can place the elements in positions that respect this difference, we can solve the problem.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least two elements, as per the problem constraints.
- The solution should efficiently handle arrays with up to 1000 elements.
- The array may contain both positive and negative numbers.
- Ensure the solution works for arrays with the minimum and maximum integer values.
{{< dots >}}
## Code 💻
```cpp
bool canMakeArithmeticProgression(vector<int>& arr) {
    if (arr.size() <= 2) return true;
    int min = INT_MAX, max = INT_MIN;
    for (int num : arr) {
        min = std::min(min, num);
        max = std::max(max, num);
    }
    if ((max - min) % (arr.size() - 1) != 0) return false;
    int d = (max - min) / (arr.size() - 1);

    int i = 0;
    while (i < arr.size()) {
        if (arr[i] == min + i * d) i++;
        else if ((arr[i] - min) % d != 0) return false;
        else {
            int pos = (arr[i] - min) / d;
            if (pos < i || arr[pos] == arr[i]) return false;
            std::swap(arr[i], arr[pos]);
        }
    }
    return true;        
}
```

This code checks if an array can be rearranged to form an arithmetic progression. It calculates the minimum and maximum values, checks divisibility, and swaps elements as necessary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	bool canMakeArithmeticProgression(vector<int>& arr) {
	```
	Defines the function that checks whether an array can form an arithmetic progression.

2. **Edge Case Handling**
	```cpp
	    if (arr.size() <= 2) return true;
	```
	Handles edge case where the array has 2 or fewer elements, in which case it trivially forms an arithmetic progression.

3. **Variable Initialization**
	```cpp
	    int min = INT_MAX, max = INT_MIN;
	```
	Initializes variables to track the minimum and maximum values in the array.

4. **Loop**
	```cpp
	    for (int num : arr) {
	```
	Iterates over each element in the array to find the minimum and maximum values.

5. **Mathematical Operations**
	```cpp
	        min = std::min(min, num);
	```
	Updates the minimum value encountered in the array.

6. **Mathematical Operations**
	```cpp
	        max = std::max(max, num);
	```
	Updates the maximum value encountered in the array.

7. **Mathematical Operations**
	```cpp
	    if ((max - min) % (arr.size() - 1) != 0) return false;
	```
	Checks if the difference between the max and min values is divisible by the size of the array minus one.

8. **Mathematical Operations**
	```cpp
	    int d = (max - min) / (arr.size() - 1);
	```
	Calculates the common difference (d) for the arithmetic progression.

9. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initializes a counter variable to track the current index while checking the array elements.

10. **Loop**
	```cpp
	    while (i < arr.size()) {
	```
	Begins a while loop to traverse the array and check the condition for an arithmetic progression.

11. **Conditionals**
	```cpp
	        if (arr[i] == min + i * d) i++;
	```
	If the current element matches the expected value for the arithmetic progression, increment the index.

12. **Conditionals**
	```cpp
	        else if ((arr[i] - min) % d != 0) return false;
	```
	Checks if the current element can be part of the progression. If not, returns false.

13. **Conditionals**
	```cpp
	        else {
	```
	If neither condition is met, attempt to swap elements to help form the arithmetic progression.

14. **Mathematical Operations**
	```cpp
	            int pos = (arr[i] - min) / d;
	```
	Calculates the target position for the current element in the progression.

15. **Conditionals**
	```cpp
	            if (pos < i || arr[pos] == arr[i]) return false;
	```
	Checks if the position is valid and whether the element has already been placed correctly.

16. **Array Operations**
	```cpp
	            std::swap(arr[i], arr[pos]);
	```
	Swaps the current element with the element at the calculated position to form the progression.

17. **Return**
	```cpp
	    return true;        
	```
	Returns true if the array can be rearranged into an arithmetic progression.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Finding the minimum and maximum values takes O(n), and sorting the array takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We only use a few variables for computation, so the space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/)

---
{{< youtube crVb-Fubs0w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
