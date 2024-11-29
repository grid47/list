
+++
authors = ["grid47"]
title = "Leetcode 1702: Maximum Binary String After Change"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1702: Maximum Binary String After Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FL972h3KqKA"
youtube_upload_date="2020-12-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FL972h3KqKA/maxresdefault.webp"
comments = true
+++



---
You are given a binary string consisting of only '0's and '1's. You can perform two types of operations on this string any number of times:

- Operation 1: Replace any occurrence of the substring '00' with '10'.
- Operation 2: Replace any occurrence of the substring '10' with '01'.

Your goal is to apply these operations and transform the binary string into the largest possible binary string in terms of its decimal value. A string 'x' is considered larger than string 'y' if the decimal value of 'x' is greater than that of 'y'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string, 'binary', consisting of only '0's and '1's.
- **Example:** `"001110"`
- **Constraints:**
	- 1 <= binary.length <= 10^5
	- binary consists of only '0' and '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest binary string possible after applying the operations any number of times.
- **Example:** `"111011"`
- **Constraints:**
	- The output should be a valid binary string.

{{< dots >}}
### Core Logic 🔍
**Goal:** Transform the binary string into the largest possible binary string using the given operations.

- 1. Traverse the binary string to count the number of '1's and '0's.
- 2. For the string to be as large as possible, move all '1's to the leftmost positions and the remaining '0's to the right.
- 3. If there are any remaining '0's after moving '1's, the last '0' will stay in its place, as we can't transform it further.
- 4. Return the transformed string.
{{< dots >}}
### Problem Assumptions ✅
- Binary string consists only of '0's and '1's.
- The string may be of any length between 1 and 100,000.
{{< dots >}}
## Examples 🧩
- **Input:** `"001110"`  \
  **Explanation:** In this example, we can transform '001110' step by step: first '001101', then '010101', and finally '111011', yielding the largest possible binary string '111011'.

{{< dots >}}
## Approach 🚀
The approach is to count the '1's and '0's in the string and rearrange them such that all '1's come first, followed by all '0's, yielding the largest possible binary string.

### Initial Thoughts 💭
- The problem essentially involves sorting the string to place all '1's to the left.
- By counting the number of '1's and '0's, we can create the largest string by placing all '1's first, followed by all '0's. This approach ensures we meet the problem's requirement.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return an empty string.
- Ensure the solution can handle inputs with up to 100,000 characters efficiently.
- If the string contains only '1's or only '0's, no transformations can be made, and the original string is the largest possible.
- The string length must not exceed 100,000 characters, and the solution should run in linear time to handle this efficiently.
{{< dots >}}
## Code 💻
```cpp
string maximumBinaryString(string binary) {
    int ones = 0, zeros = 0, n = binary.size();
    for (auto &c: binary) {
        if(c == '0')
        zeros++;
        else if (zeros == 0)
        ones++;
        c = '1';
    }
    if(ones < n)
    binary[zeros + ones -1] = '0';
    return binary;
}
```

This function transforms a binary string into the lexicographically largest possible binary string by shifting the zeros after all the ones, while keeping the number of zeros and ones the same.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string maximumBinaryString(string binary) {
	```
	Defines the function `maximumBinaryString`, which manipulates the given binary string to generate the lexicographically largest possible binary string.

2. **Variable Initialization**
	```cpp
	    int ones = 0, zeros = 0, n = binary.size();
	```
	Initializes three variables: `ones` (counts the number of ones), `zeros` (counts the number of zeros), and `n` (stores the length of the binary string).

3. **Loop Through Binary String**
	```cpp
	    for (auto &c: binary) {
	```
	Iterates through each character of the `binary` string, updating `ones`, `zeros`, and modifying the string.

4. **Check for Zero**
	```cpp
	        if(c == '0')
	```
	Checks if the current character is a zero. If true, increments the `zeros` counter.

5. **Update Zero Counter**
	```cpp
	        zeros++;
	```
	Increments the `zeros` counter when the character is a zero.

6. **Check for One Before Zero**
	```cpp
	        else if (zeros == 0)
	```
	Checks if the current character is a one and if no zeros have been encountered yet (so we can count ones before zeros).

7. **Update One Counter**
	```cpp
	        ones++;
	```
	Increments the `ones` counter when a one is encountered before any zeros.

8. **Modify Character to One**
	```cpp
	        c = '1';
	```
	Changes the current character to '1', ensuring that all ones appear before any zeros in the resulting string.

9. **Condition Check for Ones Less than Total Length**
	```cpp
	    if(ones < n)
	```
	Checks if the number of ones is less than the length of the string. This means that there are still zeros left to place after the ones.

10. **Modify Last Position**
	```cpp
	    binary[zeros + ones -1] = '0';
	```
	Sets the last zero position in the binary string by placing '0' at the calculated position to ensure the number of ones and zeros remains the same.

11. **Return Result**
	```cpp
	    return binary;
	```
	Returns the modified binary string, which is now the lexicographically largest possible string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string. This is the best case where the string is already in the desired form.
- **Average Case:** O(n), where n is the length of the string. We need to scan through the string to count '1's and '0's.
- **Worst Case:** O(n), where n is the length of the string. The solution involves iterating through the string to count the characters.

The time complexity is linear in terms of the input size, making the solution efficient even for large inputs.

### Space Complexity 💾
- **Best Case:** O(1), since we only need a few variables for counting and constructing the output string.
- **Worst Case:** O(n), where n is the length of the string, as we may need additional space to store the result.

The space complexity is linear in the worst case, where we need to store the modified string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-binary-string-after-change/description/)

---
{{< youtube FL972h3KqKA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
