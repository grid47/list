
+++
authors = ["grid47"]
title = "Leetcode 1318: Minimum Flips to Make a OR b Equal to c"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1318: Minimum Flips to Make a OR b Equal to c in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given three positive integers, a, b, and c. Your task is to find the minimum number of bit flips required in a and b to make the result of (a OR b) equal to c. A bit flip consists of changing any bit from 0 to 1 or from 1 to 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three integers a, b, and c, where each integer represents the bitwise values of a, b, and c.
- **Example:** `For a = 3, b = 5, and c = 7, we will calculate the number of bit flips needed to satisfy (a OR b == c).`
- **Constraints:**
	- 1 <= a, b, c <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the minimum number of bit flips required to make (a OR b) equal to c.
- **Example:** `For a = 3, b = 5, and c = 7, the output is 2.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the minimum number of bit flips required to ensure that the bitwise OR of a and b equals c.

- 1. Loop through each bit position (from 0 to 30).
- 2. Check the values of a, b, and c at each bit position using bitwise operations.
- 3. Determine if a flip is required based on the combination of a, b, and c at that bit position.
- 4. Count the number of flips needed and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The input integers are valid positive integers within the specified range.
- The bitwise operations are performed on integers with a maximum of 30 bits.
{{< dots >}}
## Examples 🧩
- **Input:** `For a = 3, b = 5, and c = 7, (a OR b) = 7, and no flip is needed. Hence, the output is 2.`  \
  **Explanation:** In binary, a = 0011, b = 0101, and c = 0111. (a OR b) results in 0111, which is equal to c, requiring 2 flips in total.

{{< dots >}}
## Approach 🚀
We use bitwise operations to check each bit of a, b, and c. By comparing the values at each bit position, we determine whether a flip is required and count the total number of flips needed.

### Initial Thoughts 💭
- The bitwise OR operation compares corresponding bits from two integers.
- For each bit position, there are a few possible combinations of bits between a, b, and c.
- The solution involves looping through all bit positions and checking if a flip is required for each one.
{{< dots >}}
### Edge Cases 🌐
- There should always be valid input values (non-zero positive integers).
- The input values could be as large as 10^9, requiring efficient bitwise operations to handle these cases.
- If a, b, or c are equal to 0, we need to handle these cases carefully as they may require different flip combinations.
- The problem guarantees that all values will be positive integers.
{{< dots >}}
## Code 💻
```cpp

int bit(int n, int i) {
    return (n >> i) & 1;
}

int minFlips(int a, int b, int c) {
    // (a|b) has zero and c has 1 required change is one
    // (a|b) has one and c has zero required change is one(if one of them have 1) or two (if both have one)
    
    /*
        0   0   1       1
        0   1   0       1
        1   0   0       1
        1   1   0       2
    */
    int cnt = 0;
    for(int i = 0; i < 31; i++) {
        if((!bit(a, i) && !bit(b, i) && bit(c, i)) ||
           (!bit(a, i) && bit(b, i) && !bit(c, i)) ||
           (bit(a, i) && !bit(b, i) && !bit(c, i)) ) {
            cnt++;
        } else if((bit(a, i) && bit(b, i) && !bit(c, i))) {
            cnt += 2;
        }
    }
    return cnt;
}
```

This solution calculates the minimum number of flips required to convert integers 'a' and 'b' into integer 'c'. It uses bitwise operations to assess bit differences between 'a', 'b', and 'c'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Helper Function**
	```cpp
	int bit(int n, int i) {
	```
	The function 'bit' extracts the bit at position 'i' from the integer 'n' using bitwise right shift and AND operations.

2. **Bitwise Operation**
	```cpp
	    return (n >> i) & 1;
	```
	The expression shifts the bits of 'n' to the right by 'i' positions and returns the bitwise AND with 1 to isolate the desired bit.

3. **Function Declaration**
	```cpp
	int minFlips(int a, int b, int c) {
	```
	The 'minFlips' function is declared. It takes three integers 'a', 'b', and 'c' and calculates the number of bit flips required to convert 'a' and 'b' into 'c'.

4. **Initialization**
	```cpp
	    int cnt = 0;
	```
	The variable 'cnt' is initialized to 0 to keep track of the number of flips needed.

5. **Loop Start**
	```cpp
	    for(int i = 0; i < 31; i++) {
	```
	A loop is set up to iterate over all 31 bit positions of the integers 'a', 'b', and 'c'.

6. **Condition Check**
	```cpp
	        if((!bit(a, i) && !bit(b, i) && bit(c, i)) ||
	```
	This condition checks if both 'a' and 'b' have 0 in a bit position, but 'c' has 1, which requires a flip.

7. **Condition Check**
	```cpp
	           (!bit(a, i) && bit(b, i) && !bit(c, i)) ||
	```
	This checks if 'a' has 0, 'b' has 1, and 'c' has 0, which also requires a flip.

8. **Condition Check**
	```cpp
	           (bit(a, i) && !bit(b, i) && !bit(c, i)) ) {
	```
	This checks if 'a' has 1, 'b' has 0, and 'c' has 0, which requires a flip.

9. **Count Increment**
	```cpp
	            cnt++;
	```
	If the condition is true, one flip is required, so we increment 'cnt'.

10. **Else Condition**
	```cpp
	        } else if((bit(a, i) && bit(b, i) && !bit(c, i))) {
	```
	This checks if both 'a' and 'b' have 1 in a bit position, but 'c' has 0, which requires two flips.

11. **Count Increment**
	```cpp
	            cnt += 2;
	```
	If the condition is true, two flips are required, so we increment 'cnt' by 2.

12. **Return Statement**
	```cpp
	    return cnt;
	```
	The function returns the final count of required flips.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(30)
- **Worst Case:** O(30)

The worst case occurs when we need to check all 30 bits for a, b, and c, so the time complexity is constant and O(30).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we only need a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
