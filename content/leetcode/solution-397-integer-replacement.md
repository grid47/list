
+++
authors = ["grid47"]
title = "Leetcode 397: Integer Replacement"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 397: Integer Replacement in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Greedy","Bit Manipulation","Memoization"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/397.webp"
youtube = "5ksn2Myjlig"
youtube_upload_date="2020-11-20"
youtube_thumbnail="https://i.ytimg.com/vi/5ksn2Myjlig/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/397.webp" 
    alt="A glowing number transforming step by step into its minimal representation through division or subtraction."
    caption="Solution to LeetCode 397: Integer Replacement Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a positive integer `n`, you can perform one of the following operations: If `n` is even, divide `n` by 2. If `n` is odd, you can either add 1 to `n` or subtract 1 from `n`. Your task is to return the minimum number of operations required to reduce `n` to 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `n` (1 <= n <= 2^31 - 1).
- **Example:** `Input: n = 6`
- **Constraints:**
	- 1 <= n <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the minimum number of operations required to reduce `n` to 1.
- **Example:** `Output: 3`
- **Constraints:**
	- The solution must return the minimum number of operations required.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of operations required to reduce `n` to 1 by strategically choosing the best operation at each step.

- If `n` is even, divide by 2.
- If `n` is odd, choose either `n + 1` or `n - 1` based on which operation leads to a smaller number of operations.
{{< dots >}}
### Problem Assumptions ✅
- The input integer `n` is always a valid positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 6`  \
  **Explanation:** We perform operations on `6`: 6 -> 3 -> 2 -> 1, taking 3 steps.

- **Input:** `Input: n = 15`  \
  **Explanation:** We perform operations on `15`: 15 -> 16 -> 8 -> 4 -> 2 -> 1, taking 5 steps.

{{< dots >}}
## Approach 🚀
The approach uses a greedy algorithm to perform the optimal operation at each step, choosing either `n + 1` or `n - 1` based on the parity of the number.

### Initial Thoughts 💭
- For even numbers, dividing by 2 is always optimal.
- For odd numbers, we need to decide whether adding or subtracting 1 leads to fewer steps.
- We need to use the parity of `n` to decide the most efficient operation for odd numbers.
{{< dots >}}
### Edge Cases 🌐
- The input is always a valid integer `n` between 1 and 2^31 - 1.
- Ensure the solution can handle large values of `n` (up to 2^31 - 1) efficiently.
- Handle small inputs like `n = 1` directly (no operations needed).
- Handle edge cases where `n` is very small or very large.
{{< dots >}}
## Code 💻
```cpp
int integerReplacement(int n) {
    if(n == INT_MAX) return 32;
    int cnt = 0;
    while(n > 1) {
        if(n % 2 == 0) n /= 2;
        else {
            if((n + 1) %4 == 0 && (n - 1) != 2) n++;
            else n--;
        }
        cnt++;
    }
    return cnt;
}
```

The function `integerReplacement` aims to return the minimum number of operations required to reduce a number `n` to 1. The operations allowed are either halving the number if it is even or incrementing or decrementing it when it is odd, with some specific conditions for choosing increment over decrement.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int integerReplacement(int n) {
	```
	This line defines the function `integerReplacement`, which takes an integer `n` as input and returns an integer representing the minimum number of steps to reduce `n` to 1.

2. **Edge Case Check**
	```cpp
	    if(n == INT_MAX) return 32;
	```
	If `n` is the maximum integer value (`INT_MAX`), the function returns 32 directly, as it would require 32 operations to reduce it to 1.

3. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	The variable `cnt` is initialized to count the number of operations performed to reduce `n` to 1.

4. **Loop Setup**
	```cpp
	    while(n > 1) {
	```
	A `while` loop is used to continue the process until `n` becomes 1.

5. **Even Case Handling**
	```cpp
	        if(n % 2 == 0) n /= 2;
	```
	If `n` is even (i.e., divisible by 2), it is halved as the next operation.

6. **Odd Case Handling**
	```cpp
	        else {
	```
	If `n` is odd, we need to either increment or decrement it.

7. **Increment Case**
	```cpp
	            if((n + 1) % 4 == 0 && (n - 1) != 2) n++;
	```
	If incrementing `n` leads to a number divisible by 4 and it is not equal to 2, the function increments `n`.

8. **Decrement Case**
	```cpp
	            else n--;
	```
	If the condition for incrementing is not satisfied, the function decrements `n`.

9. **Operation Count**
	```cpp
	        cnt++;
	```
	Increment the counter `cnt` to keep track of the number of operations performed.

10. **Return Result**
	```cpp
	    return cnt;
	```
	After reducing `n` to 1, the function returns the total number of operations performed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is logarithmic because each operation reduces the number by at least half.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few variables to track the current state.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/integer-replacement/description/)

---
{{< youtube 5ksn2Myjlig >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
