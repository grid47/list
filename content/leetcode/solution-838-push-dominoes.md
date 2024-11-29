
+++
authors = ["grid47"]
title = "Leetcode 838: Push Dominoes"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 838: Push Dominoes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0_XmKkgHSdI"
youtube_upload_date="2021-01-25"
youtube_thumbnail="https://i.ytimg.com/vi/0_XmKkgHSdI/maxresdefault.jpg"
comments = true
+++



---
In a line of n dominoes, each domino is initially standing upright. Some dominoes are pushed either to the left or the right. Over time, falling dominoes will cause adjacent dominoes to fall in the same direction. If a domino is pushed from both sides, it remains standing. The task is to simulate the final state of the dominoes after all the forces are applied.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string representing the initial state of the dominoes. Each character in the string is one of 'L', 'R', or '.' representing a domino that has been pushed to the left, right, or is still standing upright, respectively.
- **Example:** `Input: dominoes = 'R..L.'`
- **Constraints:**
	- 1 <= n <= 10^5
	- dominoes[i] is one of 'L', 'R', or '.'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string representing the final state of the dominoes after all forces have been applied.
- **Example:** `Output: 'RRLL.'`
- **Constraints:**
	- The output string should have the same length as the input string.

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the effect of the falling dominoes and determine the final state of the line of dominoes.

- Step 1: Add a 'L' at the start and an 'R' at the end of the input string to handle edge cases.
- Step 2: Iterate through the string and determine the state of each domino after forces from both sides are applied.
- Step 3: Use a sliding window approach to determine how the forces affect the dominoes in between.
- Step 4: Return the final string representing the state of the dominoes.
{{< dots >}}
### Problem Assumptions ✅
- Dominoes falling to the left will push adjacent dominoes to the left.
- Dominoes falling to the right will push adjacent dominoes to the right.
- If a domino has forces applied from both sides, it remains upright.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: 'R..L.'`  \
  **Explanation:** Here, the first domino is pushed to the right and the last domino is pushed to the left. The dominoes in between are stationary but will be affected by the falling forces from both sides. The final state is 'RRLL.'

- **Input:** `Input: 'R.L.'`  \
  **Explanation:** In this case, the dominoes are pushed in opposite directions, and the falling forces cancel each other out in the middle. The final state remains as 'R.L.'

{{< dots >}}
## Approach 🚀
The problem can be approached by simulating the falling dominoes using a sliding window mechanism to compute the resulting final state.

### Initial Thoughts 💭
- The problem requires a simulation of forces applied from both directions (left and right).
- We can optimize the simulation using a sliding window approach to avoid recalculating the result repeatedly.
- The forces from the left and right will interact in the middle regions of the dominoes, so we need to efficiently determine the resulting state.
{{< dots >}}
### Edge Cases 🌐
- There should always be at least one domino in the input, as per the constraints.
- Ensure the solution handles inputs with n up to 10^5 efficiently.
- Handle cases where all dominoes are already falling in one direction or no domino is falling initially.
- Input strings must only contain 'L', 'R', or '.' and be within the given length range.
{{< dots >}}
## Code 💻
```cpp
string pushDominoes(string d) {
    d = 'L' + d + 'R';
    string res = "";
    for(int i = 0, j = 1; j < d.length(); j++) {
        if(d[j] == '.') continue;
        int middle = j - i - 1;
        if(i > 0) 
            res += d[i];
        if(d[i] == d[j])
            res += string(middle, d[i]);
        else if (d[i] == 'L' && d[j] == 'R')
            res += string(middle, '.');
        else 
            res += string(middle/2, 'R') + string(middle%2, '.') + string(middle/2, 'L');
        i = j;
    }
    return res;
}
```

This function simulates the behavior of falling dominoes with a string of characters where 'L' stands for leftward falling domino, 'R' for rightward falling domino, and '.' for an empty spot. The function returns the final state of the dominoes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string pushDominoes(string d) {
	```
	This line defines the function 'pushDominoes' which takes a string 'd' representing the state of the dominoes. The function returns a string indicating the final state after all dominoes have fallen.

2. **Variable Initialization**
	```cpp
	    d = 'L' + d + 'R';
	```
	The string 'd' is modified by appending 'L' to the beginning and 'R' to the end to handle boundary conditions where no dominoes are falling outside the array.

3. **Variable Initialization**
	```cpp
	    string res = "";
	```
	An empty string 'res' is initialized to hold the final configuration of the dominoes after processing.

4. **Loop**
	```cpp
	    for(int i = 0, j = 1; j < d.length(); j++) {
	```
	A for-loop is initiated, where 'i' represents the start of the current segment and 'j' iterates through the string 'd'. The loop processes each domino and its relationship with its neighbors.

5. **Condition**
	```cpp
	        if(d[j] == '.') continue;
	```
	If the current character is a '.', indicating an empty spot, the loop skips processing this position and continues to the next character.

6. **Calculation**
	```cpp
	        int middle = j - i - 1;
	```
	The variable 'middle' calculates the number of positions between the two dominoes (i.e., between 'd[i]' and 'd[j]').

7. **Condition**
	```cpp
	        if(i > 0) 
	```
	If the starting index 'i' is greater than zero, the domino at index 'i' is added to the result string.

8. **Action**
	```cpp
	            res += d[i];
	```
	This line appends the character at index 'i' to the result string 'res'.

9. **Condition**
	```cpp
	        if(d[i] == d[j])
	```
	If both dominoes at 'i' and 'j' are the same (both 'L' or both 'R'), the function appends 'middle' number of the same domino ('L' or 'R') to the result string.

10. **Action**
	```cpp
	            res += string(middle, d[i]);
	```
	Appends 'middle' number of dominoes (either 'L' or 'R') to the result string.

11. **Condition**
	```cpp
	        else if (d[i] == 'L' && d[j] == 'R')
	```
	If there is a conflict where the domino at 'i' is 'L' and the domino at 'j' is 'R', the function appends 'middle' number of '.' to the result string.

12. **Action**
	```cpp
	            res += string(middle, '.');
	```
	Appends 'middle' number of '.' to the result string, representing an empty spot between two opposite falling dominoes.

13. **Action**
	```cpp
	        else 
	```
	Handles the case where the two dominoes are different ('L' and 'R') and neither of the previous conditions were met.

14. **Action**
	```cpp
	            res += string(middle/2, 'R') + string(middle%2, '.') + string(middle/2, 'L');
	```
	For a mix of left and right dominoes ('L' and 'R') in between, this line appends a balanced mix of 'R' and 'L' dominoes with a possible middle '.' for an odd number of spots.

15. **Action**
	```cpp
	        i = j;
	```
	Updates the start of the next segment 'i' to the current position 'j', effectively moving to the next section of dominoes.

16. **Return**
	```cpp
	    return res;
	```
	Returns the final string 'res', which represents the final state of the dominoes after all interactions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we process each domino once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the string representation of the dominoes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/push-dominoes/description/)

---
{{< youtube 0_XmKkgHSdI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
