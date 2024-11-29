
+++
authors = ["grid47"]
title = "Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MOeuK6gaC2A"
youtube_upload_date="2021-06-06"
youtube_thumbnail="https://i.ytimg.com/vi/MOeuK6gaC2A/maxresdefault.jpg"
comments = true
+++



---
You are given a binary string s consisting of '0's and '1's. You can perform two operations on the string: 
1. Type-1: Move the first character of the string to the end. 
2. Type-2: Flip the value of any character in the string ('0' becomes '1' and '1' becomes '0'). The goal is to make the string alternating, i.e., no two adjacent characters should be the same. You need to find the minimum number of type-2 operations required to make the string alternating.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a binary string s where each character is either '0' or '1'.
- **Example:** `For s = '100101'`
- **Constraints:**
	- 1 <= s.length <= 100,000
	- Each character in s is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of type-2 operations needed to make the string alternating.
- **Example:** `For s = '100101', the output will be 1.`
- **Constraints:**
	- The output is a non-negative integer representing the minimum number of operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of type-2 operations required to make the string alternating.

- First, duplicate the string by appending it to itself to allow rotations.
- Create two target alternating strings: one starting with '0' and the other starting with '1'.
- For each position in the string, count how many type-2 flips are needed to match each alternating target string.
- Return the minimum number of flips required after considering all rotations.
{{< dots >}}
### Problem Assumptions ✅
- The input string will only contain '0's and '1's.
- The string is non-empty, with at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '100101'`  \
  **Explanation:** The string '100101' can be made alternating by performing one type-2 operation: flip the second character to '0', resulting in '100001'.

- **Input:** `s = '111000'`  \
  **Explanation:** We can perform two type-1 operations to make the string '100011', and then one type-2 operation to change the third character to '1', making the string '101010'.

- **Input:** `s = '010'`  \
  **Explanation:** The string is already alternating, so no type-2 operations are needed.

{{< dots >}}
## Approach 🚀
The approach involves generating two target alternating strings, counting the number of flips needed to match each target string, and finding the minimum flips required after considering all rotations.

### Initial Thoughts 💭
- The problem involves finding the minimum number of flips, so we need to consider all possible rotations of the string.
- By creating two alternating target strings, one starting with '0' and the other with '1', we can efficiently calculate the number of flips needed.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty, as the string length is always at least 1.
- The solution should handle strings of length up to 100,000 efficiently.
- For strings that are already alternating, no operations are needed.
- Ensure that the solution works within the time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
int minFlips(string s) {
    int n = s.size();
    s += s;
    string s1 = "", s2 = "";
    for(int i = 0; i < s.size(); i++) {
        s1 += i % 2? '0': '1';
        s2 += i % 2? '1': '0';
    }
    
    int ans1 = 0, ans2 = 0, ans = INT_MAX;
    for(int i = 0; i < s.size(); i++) {
        if(s1[i] != s[i]) ans1++;
        if(s2[i] != s[i]) ans2++;
        if(i >= n) {
            if(s1[i - n] != s[i - n]) ans1--;
            if(s2[i - n] != s[i - n]) ans2--;
        }
        if(i >= n - 1)
            ans = min({ans1, ans2, ans});
    }
    return ans;
}
```

This function calculates the minimum number of flips required to make a string alternate between '0' and '1'. The string is doubled to account for rotations, and two target alternating strings are created for comparison.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minFlips(string s) {
	```
	Function declaration, takes a string as input.

2. **String Length**
	```cpp
	    int n = s.size();
	```
	Calculate the size of the input string 's'.

3. **String Concatenation**
	```cpp
	    s += s;
	```
	Double the string 's' by concatenating it with itself to handle rotations.

4. **Target Strings Initialization**
	```cpp
	    string s1 = "", s2 = "";
	```
	Initialize two empty strings 's1' and 's2' to represent the two alternating patterns.

5. **Loop to Generate Alternating Strings**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Iterate through the string to generate two alternating strings.

6. **Alternating String 1**
	```cpp
	        s1 += i % 2? '0': '1';
	```
	Add '0' if index is odd, otherwise add '1' to the first alternating string 's1'.

7. **Alternating String 2**
	```cpp
	        s2 += i % 2? '1': '0';
	```
	Add '1' if index is odd, otherwise add '0' to the second alternating string 's2'.

8. **Answer Initialization**
	```cpp
	    int ans1 = 0, ans2 = 0, ans = INT_MAX;
	```
	Initialize variables to store the number of flips for each alternating string and the minimum result.

9. **Main Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Loop through the string to calculate the flips needed for both alternating patterns.

10. **Count Flips for String 1**
	```cpp
	        if(s1[i] != s[i]) ans1++;
	```
	If the current character doesn't match 's1', increment the flip count for 's1'.

11. **Count Flips for String 2**
	```cpp
	        if(s2[i] != s[i]) ans2++;
	```
	If the current character doesn't match 's2', increment the flip count for 's2'.

12. **Check Rotation Bounds**
	```cpp
	        if(i >= n) {
	```
	Check if the current index is beyond the original string's size, indicating a full rotation.

13. **Adjust Answer for Rotations**
	```cpp
	            if(s1[i - n] != s[i - n]) ans1--;
	```
	Adjust the flip count for 's1' by subtracting the character that is now out of the window.

14. **Adjust Answer for Rotations**
	```cpp
	            if(s2[i - n] != s[i - n]) ans2--;
	```
	Adjust the flip count for 's2' by subtracting the character that is now out of the window.

15. **Update Minimum Flips**
	```cpp
	        if(i >= n - 1)
	```
	If we have checked enough characters, update the minimum number of flips.

16. **Calculate Minimum Answer**
	```cpp
	            ans = min({ans1, ans2, ans});
	```
	Take the minimum of the three possible answers.

17. **Return Final Answer**
	```cpp
	    return ans;
	```
	Return the minimum number of flips.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) for counting the number of flips in each rotation, where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the duplicated string and the two target alternating strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/)

---
{{< youtube MOeuK6gaC2A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
