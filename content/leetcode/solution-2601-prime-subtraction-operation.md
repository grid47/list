
+++
authors = ["grid47"]
title = "Leetcode 2601: Prime Subtraction Operation"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2601: Prime Subtraction Operation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Greedy","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "CC0X2wxP7dE"
youtube_upload_date="2023-03-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/CC0X2wxP7dE/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array nums of length n. You can perform the following operation as many times as needed: pick an index i that has not been previously selected, and choose a prime number p such that p < nums[i]. Then, subtract p from nums[i]. Your task is to determine if it is possible to make the array strictly increasing by performing the operation described.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers nums, where each element nums[i] represents the value at index i.
- **Example:** `nums = [8, 12, 7, 15]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to make nums strictly increasing using the described operations; otherwise, return false.
- **Example:** `true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if it's possible to make the array strictly increasing using the prime subtraction operation.

- Iterate through the array starting from the second-to-last element.
- For each element nums[i], check if it is greater than or equal to the next element nums[i + 1].
- If nums[i] >= nums[i + 1], find the largest prime number p such that p < nums[i] and subtract it from nums[i].
- Check if the updated nums[i] is strictly less than nums[i + 1]. If not, return false.
- If the array is processed successfully, return true.
{{< dots >}}
### Problem Assumptions ✅
- The array can have duplicate elements.
- The prime subtraction operation can be performed any number of times on different elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [8, 12, 7, 15]`  \
  **Explanation:** We can subtract prime numbers 5 from 8, and 7 from 12 to make the array strictly increasing.

- **Input:** `nums = [5, 6, 10, 12]`  \
  **Explanation:** The array is already strictly increasing, no operation needed.

- **Input:** `nums = [4, 8, 3]`  \
  **Explanation:** It is not possible to perform any operation to make this array strictly increasing.

{{< dots >}}
## Approach 🚀
The solution involves iterating through the array and performing prime subtraction to make the array strictly increasing.

### Initial Thoughts 💭
- The array must be strictly increasing at every step.
- Prime numbers less than nums[i] can be used to decrease nums[i].
- We need to iterate from the second-to-last element to the first element to perform operations efficiently.
{{< dots >}}
### Edge Cases 🌐
- An empty input array should return false as there are no elements to operate on.
- The solution should handle input arrays of size up to 1000 efficiently.
- Consider edge cases where nums[i] is 1, and no prime can be subtracted.
- The solution must respect the constraints of 1 <= nums.length <= 1000.
{{< dots >}}
## Code 💻
```cpp
bool primeSubOperation(vector<int>& nums) {
    vector<int> arr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
947, 953, 967, 971, 977, 983, 991, 997 };
    int n = nums.size();
    for(int i = n - 2; i >= 0; i--) {
        int j = 0, tmp = nums[i];
        if(nums[i] >= nums[i + 1]) {
            int diff = nums[i] - nums[i + 1] + 1;
            auto it = lower_bound(arr.begin(), arr.end(), diff);
            if(it == arr.end() || *it >= nums[i]) return false;
            nums[i] -= *it;
        }
        if(nums[i] >= nums[i + 1]) return false;
    }
    return true;
}
```

This is the complete implementation of the 'primeSubOperation' function that checks if a sequence of numbers satisfies certain conditions using a predefined list of prime numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool primeSubOperation(vector<int>& nums) {
	```
	Define the function 'primeSubOperation', which takes a reference to a vector of integers and returns a boolean value.

2. **Prime Numbers Initialization**
	```cpp
	    vector<int> arr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };
	```
	Initialize a vector of prime numbers which will be used to compare and subtract from the elements in 'nums'.

3. **Determine List Size**
	```cpp
	    int n = nums.size();
	```
	Get the size of the input vector 'nums'.

4. **Loop Initialization**
	```cpp
	    for(int i = n - 2; i >= 0; i--) {
	```
	Start a loop that iterates through the vector from second-to-last element down to the first.

5. **Store Temporary Value**
	```cpp
	        int j = 0, tmp = nums[i];
	```
	Store the current element in 'tmp' and initialize 'j'.

6. **Check Comparison Condition**
	```cpp
	        if(nums[i] >= nums[i + 1]) {
	```
	Check if the current element is greater than or equal to the next element.

7. **Calculate Difference**
	```cpp
	            int diff = nums[i] - nums[i + 1] + 1;
	```
	Calculate the difference between the current element and the next element, adding 1.

8. **Find Lower Bound Prime**
	```cpp
	            auto it = lower_bound(arr.begin(), arr.end(), diff);
	```
	Find the smallest prime number that is greater than or equal to the calculated difference.

9. **Prime Validation**
	```cpp
	            if(it == arr.end() || *it >= nums[i]) return false;
	```
	Check if the found prime number is valid. If not, return false.

10. **Subtract Prime**
	```cpp
	            nums[i] -= *it;
	```
	Subtract the found prime from the current element.

11. **Condition Check**
	```cpp
	        if(nums[i] >= nums[i + 1]) return false;
	```
	After modification, check again if the current element is greater than or equal to the next element.

12. **Return True**
	```cpp
	    return true;
	```
	If the loop finishes successfully, return true.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

In the worst case, for each element, we need to search for a prime number smaller than the element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space needed for the prime number list and storing the modified array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/prime-subtraction-operation/description/)

---
{{< youtube CC0X2wxP7dE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
