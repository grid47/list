
+++
authors = ["grid47"]
title = "Leetcode 2595: Number of Even and Odd Bits"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2595: Number of Even and Odd Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "SMk2dF8hReg"
youtube_upload_date="2023-03-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SMk2dF8hReg/maxresdefault.webp"
comments = true
+++



---
Given a positive integer `n`, return an array containing the number of `1` bits at even indices and odd indices in the binary representation of `n`. The binary digits are indexed from right to left, starting at index 0. The first element of the array should represent the number of `1` bits at even indices, and the second element should represent the number of `1` bits at odd indices.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n`.
- **Example:** `For `n = 50`.`
- **Constraints:**
	- 1 <= n <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array with two elements: the first element is the count of `1` bits at even indices and the second element is the count of `1` bits at odd indices.
- **Example:** `For `n = 50`, the output is `[1, 2]`.`
- **Constraints:**
	- The output is an array of two integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently count the `1` bits at even and odd indices in the binary representation of `n`.

- 1. Convert `n` to its binary representation.
- 2. Iterate through each bit of the binary representation, counting the `1` bits at even and odd indices separately.
- 3. Return the result as an array with the counts of even and odd indexed `1` bits.
{{< dots >}}
### Problem Assumptions ✅
- The binary representation of `n` will not exceed 10 bits in length.
{{< dots >}}
## Examples 🧩
- **Input:** `For `n = 50``  \
  **Explanation:** The binary representation of `50` is `110010`. There is one `1` at an even index (index 1), and two `1`s at odd indices (indices 4 and 5). Thus, the output is `[1, 2]`.

{{< dots >}}
## Approach 🚀
The solution involves converting `n` to its binary form, then iterating through each bit, keeping track of counts of `1` bits at even and odd positions.

### Initial Thoughts 💭
- The binary representation of `n` is at most 10 bits long for values of `n` up to 1000.
- We can solve this problem by iterating through the binary representation and checking the position of each bit.
- We will use a loop to check each bit of `n` and classify it as belonging to either an even or odd index.
{{< dots >}}
### Edge Cases 🌐
- The input `n` will always be a positive integer.
- The largest possible input is `n = 1000`, which is manageable within the solution's time complexity.
- When `n` is a small number, such as 1 or 2, the solution should still work correctly.
- The solution must handle all values of `n` between 1 and 1000 efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<int> evenOddBit(int n) {
    int a=0,b=0;
    int c=0;
    while(n>0)
    {
        if(c%2==0)
        {
            if(n%2==1)
            {
                a++;
            }
        }
        else
        {
            if(n%2==1) b++;
        }
        n=n/2;
        c++;
        
    }
    return {a,b};
}
```

This function calculates how many 1's are present at even and odd bit positions in the binary representation of a number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> evenOddBit(int n) {
	```
	Define a function that takes an integer `n` as input and returns a vector of two integers representing counts of 1's at even and odd bit positions.

2. **Variable Initialization**
	```cpp
	    int a=0,b=0;
	```
	Initialize two variables `a` and `b` to count the 1's at even and odd positions, respectively.

3. **Variable Initialization**
	```cpp
	    int c=0;
	```
	Initialize a counter `c` to keep track of the bit position.

4. **Loop**
	```cpp
	    while(n>0)
	```
	Start a while loop that continues until `n` becomes zero. This loop will iterate through the bits of the number.

5. **Condition Check**
	```cpp
	        if(c%2==0)
	```
	Check if the current bit position (`c`) is even.

6. **Increment Counter**
	```cpp
	            if(n%2==1)
	```
	Check if the current bit is 1.

7. **Increment Counter**
	```cpp
	                a++;
	```
	Increment the counter `a` for even bit positions.

8. **Else Block**
	```cpp
	        else
	```
	For odd bit positions.

9. **Increment Counter**
	```cpp
	            if(n%2==1) b++;
	```
	If the current bit is 1, increment the counter `b` for odd bit positions.

10. **Bit Shift**
	```cpp
	        n=n/2;
	```
	Right shift `n` by 1 (divide by 2) to move to the next bit.

11. **Counter Increment**
	```cpp
	        c++;
	```
	Increment the bit position counter `c`.

12. **Return Statement**
	```cpp
	    return {a,b};
	```
	Return a vector containing the counts of 1's at even and odd bit positions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(b)
- **Average Case:** O(b)
- **Worst Case:** O(b)

The time complexity is O(b), where `b` is the number of bits in `n`. Since `n <= 1000`, `b` is at most 10.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a few integer counters to store the results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-even-and-odd-bits/description/)

---
{{< youtube SMk2dF8hReg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
