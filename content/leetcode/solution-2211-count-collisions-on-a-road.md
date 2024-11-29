
+++
authors = ["grid47"]
title = "Leetcode 2211: Count Collisions on a Road"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2211: Count Collisions on a Road in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Cy_E7rABX_U"
youtube_upload_date="2022-03-20"
youtube_thumbnail="https://i.ytimg.com/vi/Cy_E7rABX_U/maxresdefault.jpg"
comments = true
+++



---
You have `n` cars on a straight road, each numbered from 0 to `n-1` from left to right, with each car positioned at a unique location. You are given a string `directions` where each character represents the direction of a car ('L' for left, 'R' for right, and 'S' for stationary). Each moving car has the same speed, and the cars can collide under the following conditions: Two cars moving in opposite directions ('L' and 'R') will collide, counting as 2 collisions. A moving car colliding with a stationary car ('S') will result in 1 collision. After a collision, the cars involved stay at the collision point and no longer move. Your task is to calculate the total number of collisions that will happen.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 0-indexed string `directions` of length `n`, where each character is one of 'L', 'R', or 'S', denoting the direction of each car.
- **Example:** `"RSLSRL"`
- **Constraints:**
	- 1 <= directions.length <= 10^5
	- directions[i] is one of 'L', 'R', or 'S'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of collisions that will happen.
- **Example:** `4`
- **Constraints:**
	- The output will be an integer representing the total number of collisions.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of collisions by checking when cars move in opposite directions or when moving cars collide with stationary cars.

- Find the first car that moves towards the left and the last car that moves towards the right.
- Count the number of cars between them that collide based on the direction of movement and whether they are stationary.
{{< dots >}}
### Problem Assumptions ✅
- The input string `directions` represents valid data with no other characters apart from 'L', 'R', or 'S'.
{{< dots >}}
## Examples 🧩
- **Input:** `"RSLSRL"`  \
  **Explanation:** The cars move in opposite directions, causing collisions between moving cars and stationary cars as they meet, and we count these interactions to get the total number of collisions.

{{< dots >}}
## Approach 🚀
The approach involves scanning the `directions` string and identifying the range of cars that will collide based on their movement directions, counting the number of collisions based on specific rules.

### Initial Thoughts 💭
- Cars moving in opposite directions (R and L) will collide.
- Cars moving towards a stationary car will cause a collision.
- We need to identify collisions between moving cars and stationary cars, and count collisions where two cars move towards each other.
{{< dots >}}
### Edge Cases 🌐
- The input is guaranteed to have at least one car.
- The solution should handle strings of length up to 10^5 efficiently.
- The string may contain only 'L', 'R', or 'S'.
- The string should not contain any other characters apart from 'L', 'R', or 'S'.
{{< dots >}}
## Code 💻
```cpp
int countCollisions(string dir) {
    int l = 0, r = dir.size() - 1;
    int n = dir.size();
    while(l < n && dir[l] == 'L')
        l++;
    
    while(r >= 0 && dir[r] == 'R')
        r--;
    
    int cnt = 0;
    for(int i = l; i <= r; i++)
        if(dir[i] != 'S')
            cnt++;
    
    return cnt;
}
```

This function counts the number of collisions between cars represented by the string `dir`. Cars are represented by 'L' (left), 'R' (right), and 'S' (stopped). A collision occurs when a moving car ('L' or 'R') encounters another moving car or a stationary car.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countCollisions(string dir) {
	```
	Function definition starts. The function takes a string `dir` that represents the direction of cars ('L' for left, 'R' for right, 'S' for stopped) and returns an integer indicating the number of collisions.

2. **Variable Initialization**
	```cpp
	    int l = 0, r = dir.size() - 1;
	```
	Initialize two variables `l` and `r` to track the leftmost and rightmost car positions in the string `dir`.

3. **Size Calculation**
	```cpp
	    int n = dir.size();
	```
	Calculate the size of the input string `dir` and store it in the variable `n`.

4. **Left Pointer Movement**
	```cpp
	    while(l < n && dir[l] == 'L')
	```
	Move the left pointer `l` to the right while the car is moving left ('L').

5. **Left Pointer Update**
	```cpp
	        l++;
	```
	Increment the left pointer `l` to skip over all left-moving cars ('L').

6. **Right Pointer Movement**
	```cpp
	    while(r >= 0 && dir[r] == 'R')
	```
	Move the right pointer `r` to the left while the car is moving right ('R').

7. **Right Pointer Update**
	```cpp
	        r--;
	```
	Decrement the right pointer `r` to skip over all right-moving cars ('R').

8. **Collision Counter Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize the collision counter `cnt` to 0. This will be used to count the number of collisions.

9. **Loop through Middle Cars**
	```cpp
	    for(int i = l; i <= r; i++)
	```
	Loop through the cars between the left and right pointers (from `l` to `r`).

10. **Collision Check**
	```cpp
	        if(dir[i] != 'S')
	```
	Check if the car at position `i` is not stationary ('S'). If it's moving ('L' or 'R'), it's a collision.

11. **Increment Collision Counter**
	```cpp
	            cnt++;
	```
	If the car at position `i` is moving ('L' or 'R'), increment the collision counter `cnt`.

12. **Return Collision Count**
	```cpp
	    return cnt;
	```
	Return the final count of collisions detected.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We scan the directions string only once to determine the collisions.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses a constant amount of extra space as we only need a few variables for the calculation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-collisions-on-a-road/description/)

---
{{< youtube Cy_E7rABX_U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
