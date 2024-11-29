
+++
authors = ["grid47"]
title = "Leetcode 907: Sum of Subarray Minimums"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 907: Sum of Subarray Minimums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aX1F2-DrBkQ"
youtube_upload_date="2024-01-20"
youtube_thumbnail="https://i.ytimg.com/vi/aX1F2-DrBkQ/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers `arr`, find the sum of the minimum values of all contiguous subarrays of `arr`. Since the result can be very large, return it modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers `arr` representing the input.
- **Example:** `Input: arr = [5, 3, 8, 6]`
- **Constraints:**
	- 1 <= arr.length <= 30,000
	- 1 <= arr[i] <= 30,000

{{< dots >}}
### Output Specifications 📤
- **Output:** An integer representing the sum of the minimum values of all subarrays, modulo 10^9 + 7.
- **Example:** `Output: 35`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Compute the sum of the minimum elements for all contiguous subarrays efficiently.

- Use a monotonic stack to calculate the contribution of each element as the minimum in its range.
- Track the range on the left and right where the current element is the minimum.
- Multiply the contribution of each element by its value and sum all contributions.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least one element.
- All elements in the array are non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [5, 3, 8, 6]`  \
  **Explanation:** Subarrays are [5], [3], [8], [6], [5, 3], [3, 8], [8, 6], [5, 3, 8], [3, 8, 6], [5, 3, 8, 6]. Minimums are 5, 3, 8, 6, 3, 3, 6, 3, 3, 3. Sum is 35.

- **Input:** `Input: arr = [2, 4, 1]`  \
  **Explanation:** Subarrays are [2], [4], [1], [2, 4], [4, 1], [2, 4, 1]. Minimums are 2, 4, 1, 2, 1, 1. Sum is 11.

{{< dots >}}
## Approach 🚀
Use a monotonic stack to efficiently calculate the sum of minimum elements in all subarrays by determining the contribution of each element as the minimum.

### Initial Thoughts 💭
- Brute-force methods to calculate the minimum for every subarray will be computationally expensive.
- A monotonic stack can help efficiently calculate the range of influence of each element.
- The range of influence for an element can be determined by finding the nearest smaller element to its left and right.
{{< dots >}}
### Edge Cases 🌐
- Array contains only one element.
- Array of maximum size with all elements equal.
- All elements in the array are distinct and sorted in descending order.
- The input size and element values at their maximum limit.
{{< dots >}}
## Code 💻
```cpp
int sumSubarrayMins(vector<int>& nums) {
    stack<pair<int, int>> stk_p;

    int n = nums.size();
    vector<int> left(n), right(n);
    // prefill, algo may not catch everything
    for(int i = 0; i < n; i++)  left[i] = i + 1;
    for(int i = 0; i < n; i++) right[i] = n - i;

    for(int i = 0; i < n; i++) {
        while(!stk_p.empty() && stk_p.top().first > nums[i]) {
            auto x = stk_p.top();
            stk_p.pop();
            right[x.second] = i - x.second;
        }
        left[i] = stk_p.empty() ? i + 1 : i - stk_p.top().second;
        stk_p.push({ nums[i], i });
    }
    
    long long ans = 0;
    int mod = (int) 1e9 + 7;
    for (int i = 0; i < n; i++)
    ans = (ans + (long) nums[i] * (long) left[i] * (long) right[i]) % mod;
    return (int) ans;
}
```

This code calculates the sum of the minimums of all subarrays in a given array `nums` using a stack-based approach. It computes the left and right limits for each element, representing the number of subarrays where the element is the minimum. The final result is computed by summing up the contributions of all elements in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumSubarrayMins(vector<int>& nums) {
	```
	This line defines the function `sumSubarrayMins`, which takes a vector `nums` as input and returns an integer. The goal is to calculate the sum of the minimums of all subarrays of the input array.

2. **Variable Initialization**
	```cpp
	    stack<pair<int, int>> stk_p;
	```
	A stack `stk_p` is initialized to store pairs of integers, where the first element is a value from the array and the second element is its index.

3. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	This line initializes the integer `n`, which holds the size of the input array `nums`.

4. **Variable Initialization**
	```cpp
	    vector<int> left(n), right(n);
	```
	Two vectors `left` and `right` of size `n` are initialized to store the number of subarrays where each element is the minimum, for each side (left and right).

5. **Loop**
	```cpp
	    for(int i = 0; i < n; i++)  left[i] = i + 1;
	```
	This loop fills the `left` vector such that `left[i]` represents the number of subarrays where `nums[i]` is the minimum, starting from index `0`.

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) right[i] = n - i;
	```
	This loop fills the `right` vector such that `right[i]` represents the number of subarrays where `nums[i]` is the minimum, extending towards the end of the array.

7. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates over each element in the array to calculate the correct values for `left` and `right` using a stack-based approach.

8. **Condition**
	```cpp
	        while(!stk_p.empty() && stk_p.top().first > nums[i]) {
	```
	This while loop pops elements from the stack until it finds an element smaller than or equal to `nums[i]`. This helps in updating the `right` values for the elements that are being popped.

9. **Stack Operation**
	```cpp
	            auto x = stk_p.top();
	```
	The top element of the stack is stored in the variable `x`, which holds both the value and index of the element.

10. **Stack Operation**
	```cpp
	            stk_p.pop();
	```
	The top element of the stack is popped, and the `right` vector is updated for the index stored in `x`.

11. **Assignment**
	```cpp
	            right[x.second] = i - x.second;
	```
	The `right` vector for the popped element is updated to represent the number of elements between the current element and the popped element.

12. **Assignment**
	```cpp
	        left[i] = stk_p.empty() ? i + 1 : i - stk_p.top().second;
	```
	The `left` value for the current element is calculated based on whether the stack is empty. If the stack is empty, the element extends all the way from the start, else it calculates the distance from the top element of the stack.

13. **Stack Operation**
	```cpp
	        stk_p.push({ nums[i], i });
	```
	The current element `nums[i]` and its index `i` are pushed onto the stack.

14. **Variable Initialization**
	```cpp
	    long long ans = 0;
	```
	A variable `ans` of type `long long` is initialized to accumulate the final result, the sum of the minimums of all subarrays.

15. **Variable Initialization**
	```cpp
	    int mod = (int) 1e9 + 7;
	```
	A modulo value `mod` is set to a large prime number to prevent overflow during the calculations.

16. **Loop**
	```cpp
	    for (int i = 0; i < n; i++)
	```
	This loop iterates over each element in the array to calculate its contribution to the final answer.

17. **Assignment**
	```cpp
	    ans = (ans + (long) nums[i] * (long) left[i] * (long) right[i]) % mod;
	```
	The `ans` value is updated by adding the contribution of the current element, which is calculated as the element value multiplied by its `left` and `right` values, modulo `mod`.

18. **Return**
	```cpp
	    return (int) ans;
	```
	The final result is returned as an integer, cast from `long long` to avoid overflow.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each element is pushed and popped from the stack exactly once, resulting in linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The stack stores at most n elements in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-subarray-minimums/description/)

---
{{< youtube aX1F2-DrBkQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
