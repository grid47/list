
+++
authors = ["grid47"]
title = "Leetcode 2833: Furthest Point From Origin"
date = "2024-01-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2833: Furthest Point From Origin in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "XD2LVEXo8j8"
youtube_upload_date="2023-08-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XD2LVEXo8j8/maxresdefault.webp"
comments = true
+++



---
You are given a string moves consisting of characters 'L', 'R', and '_'. The string represents movements on a number line starting from position 0. You can choose to move left or right when the character is '_', and the goal is to calculate the maximum distance from the origin you can reach after completing all the moves.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string moves where each character is either 'L', 'R', or '_'.
- **Example:** `moves = 'L_RL__R'`
- **Constraints:**
	- 1 <= moves.length <= 50
	- moves consists only of characters 'L', 'R', and '_'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum distance from the origin that can be achieved after completing all the moves.
- **Example:** `3`
- **Constraints:**
	- The output should be a single integer representing the maximum distance.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the maximum distance from the origin after performing all moves, accounting for the choices made at each '_' character.

- Initialize two counters to track the furthest left and right positions based on the current moves.
- Iterate over the string moves and calculate the maximum possible distance considering the '_' characters can be either 'L' or 'R'.
- Return the maximum of the absolute values of the two positions.
{{< dots >}}
### Problem Assumptions ✅
- The characters '_' in the moves string are flexible and can be treated as either 'L' or 'R'.
{{< dots >}}
## Examples 🧩
- **Input:** `moves = 'L_RL__R'`  \
  **Explanation:** The furthest point we can reach is -3 after making the sequence of moves 'LLRLLLR'.

- **Input:** `moves = '_R__LL_'`  \
  **Explanation:** The furthest point we can reach is -5 after making the sequence 'LRLLLLL'.

{{< dots >}}
## Approach 🚀
The problem can be approached by iterating through the string and calculating the furthest points we can reach for both left and right moves, considering the flexibility provided by '_' characters.

### Initial Thoughts 💭
- For every '_' character, we can choose either left or right, so we need to maximize the distance considering both choices.
- We should compute the furthest left and right points and then take the maximum of their absolute values.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, the distance should be 0.
- The solution should handle the case where the string length is large (up to 50 characters).
- If the string contains only 'L' or 'R' characters, the solution will still compute the correct result.
- Ensure that the solution runs efficiently given the constraints on the length of the moves string.
{{< dots >}}
## Code 💻
```cpp
int furthestDistanceFromOrigin(string moves) {
    int n=moves.length();
    
    int l=0, r=0;
    for(int i=0;i<n;i++){
        if(moves[i]=='L' || moves[i]=='_'){
            l--;
        }else{
            l++;
        }
        
        if(moves[i]=='R' || moves[i]=='_'){
            r++;
        }else{
            r--;
        }
    }
    
    if(l<0) l *= -1;
    if(r<0) r *= -1;
		
    return max(l,r);
}
```

This is the complete code for the function `furthestDistanceFromOrigin` which calculates the maximum distance a person has moved from the origin based on a series of directional moves ('L', 'R', '_'). The function uses two variables `l` and `r` to track the movements left and right respectively and computes the final distance.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int furthestDistanceFromOrigin(string moves) {
	```
	Defines the function `furthestDistanceFromOrigin`, which takes a string `moves` as input to determine the furthest distance from the origin.

2. **Length Calculation**
	```cpp
	    int n=moves.length();
	```
	Calculates the length of the `moves` string to determine how many steps to process.

3. **Variable Initialization**
	```cpp
	    int l=0, r=0;
	```
	Initializes two integer variables `l` and `r` to track the left and right movements respectively.

4. **Loop Setup**
	```cpp
	    for(int i=0;i<n;i++){
	```
	Starts a loop that iterates through each character in the `moves` string.

5. **Left Movement Check**
	```cpp
	        if(moves[i]=='L' || moves[i]=='_'){
	```
	Checks if the current move is left ('L') or an underscore ('_') which signifies movement towards the left.

6. **Left Movement**
	```cpp
	            l--;
	```
	Decreases the left movement counter `l` when a left move is detected.

7. **Else Right Movement Check**
	```cpp
	        }else{
	```
	Otherwise, check if the move is towards the right.

8. **Right Movement**
	```cpp
	            l++;
	```
	Increases the left movement counter `l` if the move is not left.

9. **Right Movement Check**
	```cpp
	        if(moves[i]=='R' || moves[i]=='_'){
	```
	Checks if the current move is right ('R') or an underscore ('_') which signifies movement towards the right.

10. **Right Movement**
	```cpp
	            r++;
	```
	Increases the right movement counter `r` when a right move is detected.

11. **Else Left Movement Check**
	```cpp
	        }else{
	```
	Otherwise, check if the move is towards the left.

12. **Left Movement**
	```cpp
	            r--;
	```
	Decreases the right movement counter `r` if the move is not right.

13. **Negative Value Correction**
	```cpp
	    if(l<0) l *= -1;
	```
	Corrects the left movement counter `l` if it is negative by multiplying it by -1 to ensure positive values.

14. **Negative Value Correction**
	```cpp
	    if(r<0) r *= -1;
	```
	Corrects the right movement counter `r` if it is negative by multiplying it by -1 to ensure positive values.

15. **Return Result**
	```cpp
			
	```
	Space for additional logic if needed.

16. **Return Maximum**
	```cpp
	    return max(l,r);
	```
	Returns the maximum of the left and right movement values, representing the furthest distance from the origin.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the length of the moves string since we only iterate once over the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few variables to track the distances.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/furthest-point-from-origin/description/)

---
{{< youtube XD2LVEXo8j8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
