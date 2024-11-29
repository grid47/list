
+++
authors = ["grid47"]
title = "Leetcode 1524: Number of Sub-arrays With Odd Sum"
date = "2024-06-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1524: Number of Sub-arrays With Odd Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B5affGy4mCs"
youtube_upload_date="2020-07-25"
youtube_thumbnail="https://i.ytimg.com/vi/B5affGy4mCs/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers `arr`. Your task is to count the number of subarrays whose sum is odd. Since the answer can be a large number, return it modulo (10^9 + 7).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers `arr` is given as input.
- **Example:** `arr = [1, 3, 5]`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- 1 <= arr[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of subarrays whose sum is odd, modulo (10^9 + 7).
- **Example:** `For arr = [1, 3, 5], the output is 4.`
- **Constraints:**
	- The output is the number of subarrays with an odd sum modulo (10^9 + 7).

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of subarrays with odd sums.

- Iterate through the array and track the odd and even subarray sums.
- Swap the odd and even counts when an odd number is encountered.
- Sum the odd subarrays and return the result modulo (10^9 + 7).
{{< dots >}}
### Problem Assumptions ✅
- The array is not empty and contains at least one element.
- The array contains integers within the given range.
{{< dots >}}
## Examples 🧩
- **Input:** `arr = [1, 3, 5]`  \
  **Explanation:** The subarrays are [1], [1, 3], [1, 3, 5], [3], [3, 5], [5]. Their sums are [1, 4, 9, 3, 8, 5], and the odd sums are [1, 9, 3, 5]. Thus, the answer is 4.

- **Input:** `arr = [2, 4, 6]`  \
  **Explanation:** All subarrays have even sums, so there are no odd-sum subarrays. Thus, the answer is 0.

{{< dots >}}
## Approach 🚀
To solve this problem, track the number of odd and even subarrays as we iterate through the array.

### Initial Thoughts 💭
- The sum of any subarray depends on whether the individual elements are odd or even.
- We need to count the odd sums by keeping track of the odd and even subarray counts at each step.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs allowed; the array has at least one element.
- Ensure the solution can handle large input sizes up to 10^5 elements.
- All elements are even or all elements are odd, which will affect the odd subarray count.
- Ensure to return the result modulo (10^9 + 7).
{{< dots >}}
## Code 💻
```cpp
int numOfSubarrays(vector<int>& arr) {
  int odd = 0, even = 0, sum = 0;
    for(int x : arr) {
        
        if (x % 2) {
            
            swap(odd, even);
            odd++;
            
            } else even++;
        
        sum = (sum + odd) % 1000000007;
        
        }
    return sum;
}
```

This code defines a function `numOfSubarrays` that calculates the number of subarrays with an odd sum in a given array `arr`. It uses two counters, `odd` and `even`, to track the number of odd and even sums encountered during iteration, ensuring efficient calculation with a time complexity of O(n).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numOfSubarrays(vector<int>& arr) {
	```
	This line declares the function `numOfSubarrays`, which takes a reference to an integer vector `arr` and returns an integer representing the number of subarrays with an odd sum.

2. **Variable Initialization**
	```cpp
	  int odd = 0, even = 0, sum = 0;
	```
	Here, three variables are initialized: `odd` (counts odd subarrays), `even` (counts even subarrays), and `sum` (holds the total sum of odd subarrays encountered so far).

3. **Looping Through Array**
	```cpp
	    for(int x : arr) {
	```
	This line starts a loop to iterate over each element `x` in the array `arr`.

4. **Condition Check (Odd Number)**
	```cpp
	        if (x % 2) {
	```
	This condition checks if the current number `x` is odd by checking the remainder when divided by 2.

5. **Swap Odd and Even Counters**
	```cpp
	            swap(odd, even);
	```
	Swaps the values of `odd` and `even` to switch the roles, as an odd number flips the parity of subarrays.

6. **Increment Odd Counter**
	```cpp
	            odd++;
	```
	Increments the `odd` counter since the current element `x` is odd, meaning the subarrays formed with this element will have odd sums.

7. **Increment Even Counter**
	```cpp
	            } else even++;
	```
	If the number is even, the `even` counter is incremented, as the subarrays formed with even numbers will continue to have even sums.

8. **Update Sum**
	```cpp
	        sum = (sum + odd) % 1000000007;
	```
	Updates the total `sum` by adding the current `odd` count and taking the result modulo 1000000007 to prevent overflow and ensure large number handling.

9. **Return Statement**
	```cpp
	    return sum;
	```
	Returns the final result stored in `sum`, which represents the number of subarrays with an odd sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution processes each element in the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses a constant amount of extra space for counting odd and even sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/)

---
{{< youtube B5affGy4mCs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
