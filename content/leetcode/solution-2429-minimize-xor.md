
+++
authors = ["grid47"]
title = "Leetcode 2429: Minimize XOR"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2429: Minimize XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mWUMfdloybo"
youtube_upload_date="2022-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mWUMfdloybo/maxresdefault.webp"
comments = true
+++



---
You are given two positive integers, num1 and num2. Your task is to find a positive integer x such that: 1. x has the same number of set bits (1's in binary representation) as num2, and 2. The value of x XOR num1 is minimized. The XOR operation is performed bitwise. Your goal is to return the integer x.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two positive integers num1 and num2.
- **Example:** `num1 = 4, num2 = 7`
- **Constraints:**
	- 1 <= num1, num2 <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer x that satisfies the given conditions.
- **Example:** `Output: 5`
- **Constraints:**
	- There will always be a unique solution.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the integer x such that it has the same number of set bits as num2 and minimizes the value of x XOR num1.

- 1. Count the number of set bits (1's) in num2.
- 2. Try to set bits of x to match the set bits of num2 from the higher bits of num1, aiming to minimize the XOR result.
- 3. If there are still set bits remaining, set them in the lowest possible positions.
{{< dots >}}
### Problem Assumptions ✅
- The inputs num1 and num2 are positive integers.
- There is always a unique solution.
{{< dots >}}
## Examples 🧩
- **Input:** `num1 = 3, num2 = 5`  \
  **Explanation:** In this example, num1 is 3 (binary 0011) and num2 is 5 (binary 0101). We need to find a number with the same number of set bits as num2 and that minimizes the XOR with num1. The number 3 (binary 0011) is the answer, as it has the same number of set bits and gives the minimal XOR value (0).

- **Input:** `num1 = 1, num2 = 12`  \
  **Explanation:** Here, num1 is 1 (binary 0001) and num2 is 12 (binary 1100). The integer 3 (binary 0011) satisfies the condition as it has the same number of set bits as 12 and gives the minimal XOR with num1, resulting in a value of 2.

{{< dots >}}
## Approach 🚀
The approach is to minimize the XOR value while matching the number of set bits in num2. By trying to match the set bits of num1 with num2 from the highest to the lowest positions, we can minimize the XOR value.

### Initial Thoughts 💭
- The number of set bits in num2 is fixed, so the task is to match those set bits while minimizing the XOR result.
- We can attempt to build the number x by manipulating the bits of num1 and num2 from higher to lower positions.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as num1 and num2 are always positive integers.
- Ensure the algorithm handles large inputs up to 10^9 efficiently.
- Consider edge cases where num1 and num2 have very different binary representations, such as num1 = 1 and num2 = 1000000000.
- The solution must handle large numbers and respect the constraints.
{{< dots >}}
## Code 💻
```cpp
int minimizeXor(int num1, int num2) {
    int n = __builtin_popcount(num2);
    int res = 0;
    for(int i = 30; i >= 0; i--) {
        if(((num1 >> i) & 1) == 1) {
            if(n > 0) {
                res |= (1 << i);
                n--;
                if(n == 0) return res;
            }
        }
    }
    int i = 0;
    while(n > 0) {
        if(((res >> i) & 1) == 0) {
            res |= (1 << i);
            n--;
        }
        i++;
    }
    return res;
}
```

This function minimizes the XOR result between two integers by considering the number of 1-bits in the second number and adjusting the bits of the first number accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	int minimizeXor(int num1, int num2) {
	```
	Defines the function 'minimizeXor' which takes two integer arguments and returns an integer.

2. **Variable Initialization**
	```cpp
	    int n = __builtin_popcount(num2);
	```
	Initializes the variable 'n' to store the count of 1-bits in 'num2'.

3. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes 'res' to 0, which will store the result of the minimized XOR.

4. **Loop**
	```cpp
	    for(int i = 30; i >= 0; i--) {
	```
	Starts a loop that iterates through all 32 bits (from 30 down to 0) of 'num1'.

5. **Condition**
	```cpp
	        if(((num1 >> i) & 1) == 1) {
	```
	Checks if the i-th bit of 'num1' is 1.

6. **Condition**
	```cpp
	            if(n > 0) {
	```
	Checks if there are still 1-bits remaining in 'num2' to assign to 'res'.

7. **Operation**
	```cpp
	                res |= (1 << i);
	```
	Sets the i-th bit of 'res' to 1 by performing a bitwise OR operation.

8. **Update**
	```cpp
	                n--;
	```
	Decreases the count of 1-bits in 'num2'.

9. **Return Condition**
	```cpp
	                if(n == 0) return res;
	```
	Returns the result if all 1-bits from 'num2' have been assigned.

10. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initializes 'i' for the while loop that will fill in remaining 1-bits in 'res'.

11. **Loop**
	```cpp
	    while(n > 0) {
	```
	Starts a while loop that continues until all 1-bits from 'num2' are assigned.

12. **Condition**
	```cpp
	        if(((res >> i) & 1) == 0) {
	```
	Checks if the i-th bit of 'res' is 0.

13. **Operation**
	```cpp
	            res |= (1 << i);
	```
	Sets the i-th bit of 'res' to 1.

14. **Update**
	```cpp
	            n--;
	```
	Decreases the count of remaining 1-bits to be assigned.

15. **Update**
	```cpp
	        i++;
	```
	Increments 'i' to check the next bit of 'res'.

16. **Return**
	```cpp
	    return res;
	```
	Returns the result after all necessary bits have been assigned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) where n is the size of the integers because the algorithm processes the bits of num1 and num2.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the solution uses a constant amount of space to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-xor/description/)

---
{{< youtube mWUMfdloybo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
