
+++
authors = ["grid47"]
title = "Leetcode 2844: Minimum Operations to Make a Special Number"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2844: Minimum Operations to Make a Special Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xFshDEg_Ul4"
youtube_upload_date="2023-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/xFshDEg_Ul4/maxresdefault.jpg"
comments = true
+++



---
You are given a non-negative integer represented as a string num. In one operation, you can remove any single digit from the string. If you remove all digits, the result becomes 0. Your task is to return the minimum number of operations required to make the number divisible by 25. A number is divisible by 25 if it ends in 00, 25, 50, or 75.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string num representing a non-negative integer.
- **Example:** `num = "78492"`
- **Constraints:**
	- 1 <= num.length <= 100
	- num only consists of digits '0' through '9'.
	- num does not contain any leading zeros.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to make num divisible by 25.
- **Example:** `2`
- **Constraints:**
	- The output should be a single integer representing the minimum number of operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum number of operations to make the number divisible by 25.

- Loop through the digits of the number from the end (rightmost side).
- Check if the current digits can form a valid pair (00, 25, 50, or 75).
- Track if '0' and '5' are found to make possible combinations.
- Count and remove digits to form a number ending in one of the valid pairs.
{{< dots >}}
### Problem Assumptions ✅
- The string will always represent a valid non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `num = "78492"`  \
  **Explanation:** The number 78492 is not divisible by 25. To make it divisible by 25, delete digits 4 and 9 to get 780, which ends in 00, making it divisible by 25.

- **Input:** `num = "12000"`  \
  **Explanation:** The number 12000 is divisible by 25 if the last two digits are kept. Delete digits 2 and 3 to get 1200, which ends in 00, making it divisible by 25.

- **Input:** `num = "4510"`  \
  **Explanation:** The number 4510 can be made divisible by 25 by removing digit 1. The resulting number 450 ends in 50, making it divisible by 25.

{{< dots >}}
## Approach 🚀
We iterate through the digits of the number from the end to check if we can form one of the valid endings (00, 25, 50, 75). The goal is to find the minimum number of deletions to make the number divisible by 25.

### Initial Thoughts 💭
- We need to find the two digits that make the number divisible by 25.
- Valid endings are 00, 25, 50, or 75.
- We can scan the number from right to left, keeping track of the digits we find to form the required pairs.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the string length is always at least 1.
- The solution should handle strings with lengths up to 100 efficiently.
- Consider cases where num is already divisible by 25 or has fewer than two digits.
- Ensure there are no leading zeros in the input.
{{< dots >}}
## Code 💻
```cpp
int minimumOperations(string num) {
    bool fivefound = false;
    bool zerofound = false;
    for (int i =num.size()-1; i >=0;i--) {
        
        if (zerofound && num[i]=='0') return num.size()-2-i;
        if (zerofound && num[i]=='5') return num.size()-2-i;
        if (fivefound && num[i]=='2') return num.size()-2-i;
        if (fivefound && num[i]=='7') return num.size()-2-i;
        if (num[i]=='5') fivefound = true;
        if (num[i]=='0') zerofound = true;
        
    }
    if (zerofound) return num.size()-1;
    return num.size();
}
```

This code finds the minimum number of operations to change a given number to a number divisible by 25 by adding certain operations. It searches for the right pair of digits ('00', '50', '25', or '75') from right to left in the number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minimumOperations(string num) {
	```
	Declare the function `minimumOperations` that accepts a string `num` representing a number and returns the minimum number of operations to make the number divisible by 25.

2. **Variable Initialization**
	```cpp
	    bool fivefound = false;
	```
	Initialize a boolean variable `fivefound` to track if the digit '5' has been encountered.

3. **Variable Initialization**
	```cpp
	    bool zerofound = false;
	```
	Initialize a boolean variable `zerofound` to track if the digit '0' has been encountered.

4. **Loop Setup**
	```cpp
	    for (int i = num.size() - 1; i >= 0; i--) {
	```
	Start a loop that iterates over the digits of the number `num` in reverse order.

5. **First Condition Check**
	```cpp
	        if (zerofound && num[i] == '0') return num.size() - 2 - i;
	```
	If '0' has been found earlier and the current digit is also '0', return the number of operations needed to form '00'.

6. **Second Condition Check**
	```cpp
	        if (zerofound && num[i] == '5') return num.size() - 2 - i;
	```
	If '0' has been found earlier and the current digit is '5', return the number of operations needed to form '50'.

7. **Third Condition Check**
	```cpp
	        if (fivefound && num[i] == '2') return num.size() - 2 - i;
	```
	If '5' has been found earlier and the current digit is '2', return the number of operations needed to form '25'.

8. **Fourth Condition Check**
	```cpp
	        if (fivefound && num[i] == '7') return num.size() - 2 - i;
	```
	If '5' has been found earlier and the current digit is '7', return the number of operations needed to form '75'.

9. **Check for '5'**
	```cpp
	        if (num[i] == '5') fivefound = true;
	```
	If the current digit is '5', set `fivefound` to `true`.

10. **Check for '0'**
	```cpp
	        if (num[i] == '0') zerofound = true;
	```
	If the current digit is '0', set `zerofound` to `true`.

11. **Final Check for '0'**
	```cpp
	    if (zerofound) return num.size() - 1;
	```
	If '0' has been found, return the number of operations needed to form '00'.

12. **Return Statement**
	```cpp
	    return num.size();
	```
	Return the size of the number if no valid pair of digits was found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we scan through the digits of the number once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are only using a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/)

---
{{< youtube xFshDEg_Ul4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
