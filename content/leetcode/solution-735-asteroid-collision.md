
+++
authors = ["grid47"]
title = "Leetcode 735: Asteroid Collision"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 735: Asteroid Collision in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/735.webp"
youtube = "LN7KjRszjk4"
youtube_upload_date="2021-02-10"
youtube_thumbnail="https://i.ytimg.com/vi/LN7KjRszjk4/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/735.webp" 
    alt="Asteroids moving in space, where collisions are detected, and the remaining asteroids glow softly after the impact."
    caption="Solution to LeetCode 735: Asteroid Collision Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of integers representing asteroids in a row. Each asteroid has a size and a direction, with positive integers representing asteroids moving right and negative integers representing asteroids moving left. You need to determine the state of the asteroids after all collisions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of integers, where each integer represents an asteroid. A positive value means the asteroid is moving to the right, and a negative value means it is moving to the left.
- **Example:** `asteroids = [10, 15, -10]`
- **Constraints:**
	- 2 <= asteroids.length <= 10^4
	- -1000 <= asteroids[i] <= 1000
	- asteroids[i] != 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the final state of the asteroids after all collisions, as an array of integers.
- **Example:** `For the input [10, 15, -10], the output should be [10, 15].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the final state of the asteroids after resolving all collisions.

- Iterate through the array of asteroids.
- Use a stack to track the current state of the asteroids.
- For each new asteroid, check if it will collide with the top of the stack (which represents the asteroid moving to the right).
- If a collision occurs, resolve it by removing the smaller asteroid or both if they are of equal size.
- If no collision occurs, push the asteroid onto the stack.
{{< dots >}}
### Problem Assumptions ✅
- All asteroids move at the same speed.
- Two asteroids moving in the same direction will not collide.
{{< dots >}}
## Examples 🧩
- **Input:** `Starting with asteroids [10, 15, -10], the asteroid 15 collides with -10, leaving 15 intact. The final state is [10, 15].`  \
  **Explanation:** The 15 asteroid moves to the right, while -10 moves to the left. Since 15 is larger than -10, it survives, and -10 explodes. The 10 and 15 do not collide, so they remain.

{{< dots >}}
## Approach 🚀
Use a stack to simulate the movement and collision of the asteroids.

### Initial Thoughts 💭
- Each time an asteroid moves right, we need to check if it will collide with the one moving left.
- We can track the state of the asteroids with a stack, where we only need to check the top of the stack for potential collisions.
{{< dots >}}
### Edge Cases 🌐
- No empty input arrays will be provided, as the minimum length of the array is 2.
- The algorithm should handle large inputs up to the maximum size (10^4 elements).
- If all asteroids are moving in the same direction, the result will be the same array as input.
- The solution must be efficient to handle up to 10^4 elements.
{{< dots >}}
## Code 💻
```cpp
vector<int> asteroidCollision(vector<int>& ast) {

    int dir = 0, n = ast.size();
    vector<int> stk;

    for(int a : ast) {

        bool eq = false;
            while(!stk.empty() && 
                  (((double)stk.back()/a) < 0 && a < 0) && 
                  (abs(stk.back()) < abs(a))) {
                
       
                stk.pop_back();
                
            }
        
 
        
        if(!stk.empty() && (stk.back() == -a && a < 0)) { 

       // cout << stk.back();                
            
            stk.pop_back();                
            
            continue; 
        }

        if (stk.empty() || ((double)stk.back()/a > 0) || ((double)stk.back()/a < 0 && a > 0))
            stk.push_back(a);
        
    }
    return stk;
}
```

This algorithm solves the asteroid collision problem by simulating the movements of asteroids represented by integers. Positive values represent asteroids moving to the right and negative values represent asteroids moving to the left. When a right-moving asteroid and a left-moving asteroid collide, the smaller one is destroyed, and the larger one continues to move in the same direction. The algorithm uses a stack to manage the asteroids and their collisions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	vector<int> asteroidCollision(vector<int>& ast) {
	```
	Define the function that accepts an array of asteroids as input.

2. **Variable Declaration**
	```cpp
	    int dir = 0, n = ast.size();
	```
	Initialize direction (`dir`) and get the size of the asteroid array (`n`).

3. **Stack Initialization**
	```cpp
	    vector<int> stk;
	```
	Declare an empty stack (`stk`) to manage the asteroids during the collision simulation.

4. **Loop**
	```cpp
	    for(int a : ast) {
	```
	Iterate through each asteroid in the input array.

5. **Flag Initialization**
	```cpp
	        bool eq = false;
	```
	Initialize a flag `eq` to track whether a collision has occurred for the current asteroid.

6. **Collision Check**
	```cpp
	            while(!stk.empty() && 
	```
	Check if the stack is non-empty and if there is a potential for collision between the current asteroid and the last asteroid in the stack.

7. **Collision Condition**
	```cpp
	                  (((double)stk.back()/a) < 0 && a < 0) && 
	```
	Check if the last asteroid in the stack is moving to the right and the current one is moving to the left.

8. **Collision Condition**
	```cpp
	                  (abs(stk.back()) < abs(a))) {
	```
	Ensure the current asteroid is larger than the one in the stack (by comparing absolute values).

9. **Pop Asteroid from Stack**
	```cpp
	                stk.pop_back();
	```
	Remove the last asteroid from the stack, as it is destroyed by the current one.

10. **Same Size Collision**
	```cpp
	        if(!stk.empty() && (stk.back() == -a && a < 0)) {
	```
	Check if the current asteroid collides with an asteroid of the same size but moving in the opposite direction.

11. **Pop Matching Asteroid**
	```cpp
	            stk.pop_back();
	```
	Remove the matching asteroid from the stack, as both asteroids are destroyed in the collision.

12. **Continue**
	```cpp
	            continue; 
	```
	Skip the current asteroid as it has been destroyed in the collision.

13. **Asteroid Push**
	```cpp
	        if (stk.empty() || ((double)stk.back()/a > 0) || ((double)stk.back()/a < 0 && a > 0))
	```
	If no collision occurs, or if the current asteroid moves in the opposite direction of the last asteroid in the stack, push it onto the stack.

14. **Stack Push**
	```cpp
	            stk.push_back(a);
	```
	Push the current asteroid onto the stack.

15. **Return Result**
	```cpp
	    return stk;
	```
	Return the stack, which contains the remaining asteroids after all collisions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of asteroids, when no collisions occur.
- **Average Case:** O(n), as each asteroid is processed once.
- **Worst Case:** O(n), as in the worst case, all asteroids could potentially collide.

The algorithm runs in linear time because each asteroid is either pushed to or popped from the stack once.

### Space Complexity 💾
- **Best Case:** O(1), if there are no collisions and the stack remains empty.
- **Worst Case:** O(n), where n is the number of asteroids, as the stack may store all asteroids in the worst case.

The space complexity is proportional to the number of asteroids due to the stack storing the results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/asteroid-collision/description/)

---
{{< youtube LN7KjRszjk4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
