
+++
authors = ["grid47"]
title = "Leetcode 13: Roman to Integer"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 13: Roman to Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/13.webp"
youtube = "3jdxYj3DD98"
youtube_upload_date="2021-08-30"
youtube_thumbnail="https://i.ytimg.com/vi/3jdxYj3DD98/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/13.webp" 
    alt="Roman numerals transitioning into flowing numbers, visualizing transformation."
    caption="Solution to LeetCode 13: Roman to Integer Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Convert a given valid Roman numeral string into its integer equivalent by following the Roman numeral system.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string 's', representing a valid Roman numeral.
- **Example:** `'VII'`
- **Constraints:**
	- 1 <= s.length <= 15
	- The string s contains only the characters: 'I', 'V', 'X', 'L', 'C', 'D', 'M'.
	- The string s represents a valid Roman numeral in the range [1, 3999].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the integer equivalent of the Roman numeral string.
- **Example:** `7`
- **Constraints:**
	- The output will be an integer in the range [1, 3999].

{{< dots >}}
### Core Logic 🔍
**Goal:** Convert the Roman numeral string into an integer by processing each character and applying the rules of Roman numerals.

- 1. Start with the last character and initialize the result to its corresponding value.
- 2. Iterate through the string from the second-to-last character to the first character.
- 3. If the current character is smaller than the next character (to the right), subtract its value from the result.
- 4. Otherwise, add its value to the result.
- 5. Return the final result.
{{< dots >}}
### Problem Assumptions ✅
- The input Roman numeral is always valid and within the specified range.
- No additional validation of input is needed.
{{< dots >}}
## Examples 🧩
- **Input:** `'VII'`  \
  **Explanation:** 'VII' is interpreted as 5 + 1 + 1 = 7.

- **Input:** `'IX'`  \
  **Explanation:** 'IX' is interpreted as 10 - 1 = 9.

{{< dots >}}
## Approach 🚀
The Roman numeral to integer conversion involves iterating through the string and using the subtraction rule when necessary.

### Initial Thoughts 💭
- Roman numerals have specific rules for subtraction, such as 'IV' for 4 and 'IX' for 9.
- By iterating over the string from right to left, we can easily handle the subtraction rule.
- We need to keep track of the current character and compare it with the next one to determine whether to add or subtract its value.
{{< dots >}}
### Edge Cases 🌐
- The input is guaranteed to be valid and non-empty.
- Ensure that the solution works within the constraint of 15 characters.
- The smallest valid Roman numeral is 'I' (1), and the largest is 'MMMCMXCIX' (3999).
- The input is always a valid Roman numeral within the range [1, 3999].
{{< dots >}}
## Code 💻
```cpp
int romanToInt(string s)
{
    int ln = s.length();
    int res= RomToNum(s[ln-1]);
    int prv= res, curr = 0;
    for (int i = ln -2; i >=0; i--)
    {
        curr = RomToNum(s[i]);
        (curr < prv)? (res -= curr): (res += curr);
        prv = curr;
    }
    return res;
}

int RomToNum(char s)
{
    switch (s)
    {
        case 'I' : return 1		;
        case 'V' : return 5		;
        case 'X' : return 10	;
        case 'L' : return 50	;
        case 'C' : return 100	;
        case 'D' : return 500	;
        case 'M' : return 1000	;
    }
    return 0;
}
```

This code implements the `romanToInt` function, which converts a Roman numeral string to its integer value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int romanToInt(string s)
	```
	Declare the `romanToInt` function, which takes a Roman numeral string `s` as input and returns its integer value.

2. **Variable Initialization**
	```cpp
	    int ln = s.length();
	```
	Initialize `ln` to store the length of the input Roman numeral string.

3. **Variable Initialization**
	```cpp
	    int res= RomToNum(s[ln-1]);
	```
	Initialize `res` with the integer value of the last Roman numeral character.

4. **Variable Initialization**
	```cpp
	    int prv= res, curr = 0;
	```
	Initialize `prv` (previous) to the value of the last character and `curr` (current) to 0.

5. **Loop Iteration**
	```cpp
	    for (int i = ln -2; i >=0; i--)
	```
	Start a loop to iterate through the Roman numeral string from the second-to-last character to the first.

6. **Variable Assignment**
	```cpp
	        curr = RomToNum(s[i]);
	```
	Assign the integer value of the current character to `curr`.

7. **Conditional Update**
	```cpp
	        (curr < prv)? (res -= curr): (res += curr);
	```
	Check if the current value is less than the previous value. If so, subtract it from `res`; otherwise, add it.

8. **Variable Assignment**
	```cpp
	        prv = curr;
	```
	Update `prv` to the current value for the next iteration.

9. **Return Value**
	```cpp
	    return res;
	```
	Return the final integer value `res`.

10. **Function Declaration**
	```cpp
	
	```
	No explicit declaration here, as `RomToNum` is a helper function defined within the same code block.

11. **Function Body**
	```cpp
	int RomToNum(char s)
	```
	Declare the `RomToNum` helper function, which takes a Roman numeral character `s` and returns its integer value.

12. **Conditional Check**
	```cpp
	    switch (s)
	```
	Use a `switch` statement to check the value of the character `s`.

13. **Case 1**
	```cpp
	        case 'I' : return 1		;
	```
	If `s` is 'I', return 1.

14. **Case 2**
	```cpp
	        case 'V' : return 5		;
	```
	If `s` is 'V', return 5.

15. **Case 3**
	```cpp
	        case 'X' : return 10	;
	```
	If `s` is 'X', return 10.

16. **Case 4**
	```cpp
	        case 'L' : return 50	;
	```
	If `s` is 'L', return 50.

17. **Case 5**
	```cpp
	        case 'C' : return 100	;
	```
	If `s` is 'C', return 100.

18. **Case 6**
	```cpp
	        case 'D' : return 500	;
	```
	If `s` is 'D', return 500.

19. **Case 7**
	```cpp
	        case 'M' : return 1000	;
	```
	If `s` is 'M', return 1000.

20. **Default Case**
	```cpp
	    }
	```
	End of the `switch` statement.

21. **Return Value**
	```cpp
	    return 0;
	```
	If the character is not a valid Roman numeral, return 0.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string s.
- **Average Case:** O(n), since the iteration over the string is always linear.
- **Worst Case:** O(n), since we process each character once.

The time complexity is linear because we iterate over the Roman numeral string once.

### Space Complexity 💾
- **Best Case:** O(1), as the space usage does not depend on the input size.
- **Worst Case:** O(1), since only a few variables are used to store the result.

The space complexity is constant, as we only use a few variables to compute the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/roman-to-integer/description/)

---
{{< youtube 3jdxYj3DD98 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
