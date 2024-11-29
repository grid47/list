
+++
authors = ["grid47"]
title = "Leetcode 2513: Minimize the Maximum of Two Arrays"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2513: Minimize the Maximum of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "g6L-jnW2n_4"
youtube_upload_date="2022-12-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/g6L-jnW2n_4/maxresdefault.webp"
comments = true
+++



---
Given two integers `divisor1` and `divisor2`, and two integers `uniqueCnt1` and `uniqueCnt2`, construct two arrays such that: `arr1` contains `uniqueCnt1` distinct integers that are not divisible by `divisor1`, `arr2` contains `uniqueCnt2` distinct integers that are not divisible by `divisor2`, and no integer appears in both arrays. Return the smallest possible maximum integer in either array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given 4 integers: `divisor1`, `divisor2`, `uniqueCnt1`, and `uniqueCnt2`.
- **Example:** `divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1`
- **Constraints:**
	- 2 <= divisor1, divisor2 <= 105
	- 1 <= uniqueCnt1, uniqueCnt2 < 109
	- 2 <= uniqueCnt1 + uniqueCnt2 <= 109

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest maximum integer that can appear in either array.
- **Example:** `3`
- **Constraints:**
	- The answer will always be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Use binary search to find the minimum possible maximum integer that satisfies the conditions.

- Perform a binary search for the minimum possible maximum number.
- For each mid-value, check if it's possible to fill both arrays with the required number of distinct integers.
{{< dots >}}
### Problem Assumptions ✅
- The divisors and counts are valid and within the provided constraints.
- The solution must be efficient enough to handle large input sizes.
{{< dots >}}
## Examples 🧩
- **Input:** `divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3`  \
  **Explanation:** The arrays arr1 = [1] and arr2 = [2, 3, 4] satisfy all the conditions. The maximum value is 4.

{{< dots >}}
## Approach 🚀
Use binary search to find the smallest number x such that we can fill both arrays with the required integers.

### Initial Thoughts 💭
- Binary search can be used to minimize the maximum integer.
- The challenge is calculating the number of valid integers in each range for a given x.
- Consider how to compute the number of integers divisible by each divisor and the overlap of divisibility between the two.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs expected in this problem.
- The solution must handle inputs where uniqueCnt1 + uniqueCnt2 is close to the upper limit.
- Divisors and counts should always be positive integers within the provided bounds.
- The solution must work within the given time and space limits for large inputs.
{{< dots >}}
## Code 💻
```cpp

bool isPossible(long long mx, long long div1, long long div2, long long unq1, long long unq2) {
    long long a = mx / div1;
    long long a_ = mx - a;
    long long b = mx / div2;
    long long b_ = mx - b;
    long long aib = mx / (long long)lcm(div1, div2);
    long long aub = a + b - aib;
    long long a_ib_ = mx - aub;
    long long neededA = (a_ - a_ib_ >= unq1) ? 0: unq1 - (a_ - a_ib_);
    long long neededB = (b_ - a_ib_ >= unq2) ? 0: unq2 - (b_ - a_ib_);        
    
    return a_ib_ >= neededA + neededB;
}

int minimizeSet(int div1, int div2, int unq1, int unq2) {
    
    long long l = 1, r = (long long) pow(10, 17), ans = 1;
    
    
    while(l <= r) {
        long long mid = l + (r - l + 1) / 2;
        if(isPossible(mid, div1, div2, unq1, unq2)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return ans;
}
```

The complete code includes two functions: `isPossible` to check if the required unique students can be achieved with a given number of students, and `minimizeSet` to find the minimum number of students using binary search.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isPossible(long long mx, long long div1, long long div2, long long unq1, long long unq2) {
	```
	Declares the `isPossible` function, which checks if it is possible to have the required number of students based on given parameters.

2. **Variable Initialization**
	```cpp
	    long long a = mx / div1;
	```
	Calculates the number of students divisible by `div1` from `mx`.

3. **Variable Initialization**
	```cpp
	    long long a_ = mx - a;
	```
	Calculates the number of remaining students after accounting for those divisible by `div1`.

4. **Variable Initialization**
	```cpp
	    long long b = mx / div2;
	```
	Calculates the number of students divisible by `div2` from `mx`.

5. **Variable Initialization**
	```cpp
	    long long b_ = mx - b;
	```
	Calculates the number of remaining students after accounting for those divisible by `div2`.

6. **Variable Initialization**
	```cpp
	    long long aib = mx / (long long)lcm(div1, div2);
	```
	Calculates the number of students divisible by both `div1` and `div2`.

7. **Variable Initialization**
	```cpp
	    long long aub = a + b - aib;
	```
	Calculates the total number of students divisible by either `div1` or `div2`.

8. **Variable Initialization**
	```cpp
	    long long a_ib_ = mx - aub;
	```
	Calculates the remaining students after considering those divisible by either `div1` or `div2`.

9. **Conditional Check**
	```cpp
	    long long neededA = (a_ - a_ib_ >= unq1) ? 0: unq1 - (a_ - a_ib_);
	```
	Checks how many more students are needed to satisfy the unique count for students divisible by `div1`.

10. **Conditional Check**
	```cpp
	    long long neededB = (b_ - a_ib_ >= unq2) ? 0: unq2 - (b_ - a_ib_);
	```
	Checks how many more students are needed to satisfy the unique count for students divisible by `div2`.

11. **Return Statement**
	```cpp
	    return a_ib_ >= neededA + neededB;
	```
	Returns whether the remaining students after satisfying the unique counts are enough.

12. **Function Declaration**
	```cpp
	int minimizeSet(int div1, int div2, int unq1, int unq2) {
	```
	Declares the `minimizeSet` function to minimize the number of students while satisfying the unique student requirements.

13. **Variable Initialization**
	```cpp
	    long long l = 1, r = (long long) pow(10, 17), ans = 1;
	```
	Initializes the binary search range (`l` to `r`) and the variable `ans` to store the result.

14. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Starts the binary search loop to find the minimum number of students.

15. **Binary Search Iteration**
	```cpp
	        long long mid = l + (r - l + 1) / 2;
	```
	Calculates the midpoint of the current search range.

16. **Condition Check**
	```cpp
	        if(isPossible(mid, div1, div2, unq1, unq2)) {
	```
	Checks if it is possible to achieve the required unique students with the current midpoint value.

17. **Result Update**
	```cpp
	            ans = mid;
	```
	Updates the result `ans` with the current midpoint value if it is possible.

18. **Binary Search Update**
	```cpp
	            r = mid - 1;
	```
	Updates the search range to the lower half of the current range.

19. **Binary Search Update**
	```cpp
	        } else {
	```
	If the current midpoint doesn't satisfy the condition, proceed with the upper half of the range.

20. **Binary Search Update**
	```cpp
	            l = mid + 1;
	```
	Updates the search range to the upper half of the current range.

21. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the result `ans`, which is the minimum number of students.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(max_integer))
- **Average Case:** O(log(max_integer))
- **Worst Case:** O(log(max_integer))

Binary search over the possible values of the maximum integer ensures a logarithmic time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

Only a few variables are used for the binary search and calculations, so the space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/)

---
{{< youtube g6L-jnW2n_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
