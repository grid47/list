
+++
authors = ["grid47"]
title = "Leetcode 2069: Walking Robot Simulation II"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2069: Walking Robot Simulation II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "10111CfY7GQ"
youtube_upload_date="2021-11-13"
youtube_thumbnail="https://i.ytimg.com/vi/10111CfY7GQ/maxresdefault.jpg"
comments = true
+++



---
A robot is placed on a grid and initially faces East. It is instructed to move forward by a specified number of steps. If the robot attempts to move out of bounds, it turns 90 degrees counterclockwise and tries again. The task is to implement a class for the robot that can handle these movements and return its current position and direction.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two parts: the dimensions of the grid and the instructions for the robot's movements. The robot starts at position (0, 0), facing East.
- **Example:** ``
- **Constraints:**

{{< dots >}}
### Output Specifications 📤
- **Output:** The output includes the robot's current position in the grid (as a two-element array [x, y]) and its current facing direction.
- **Example:** ``
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To move the robot based on instructions and handle boundary conditions with turning.

- Initialize the grid dimensions and robot's starting position and direction.
- Implement logic to move the robot one step at a time, checking for boundary conditions and turning the robot if necessary.
- Ensure that the robot's position and direction are correctly updated after each movement instruction.
{{< dots >}}
### Problem Assumptions ✅
- The grid's width and height will always be at least 2.
- The robot will always start at position (0, 0) and face East.
{{< dots >}}
## Examples 🧩
- **Input:** `Robot robot = new Robot(6, 3);`  \
  **Explanation:** Here, the robot is initialized on a 6x3 grid, starting at position (0, 0), facing East.

- **Input:** `robot.step(2); robot.getPos(); robot.getDir();`  \
  **Explanation:** The robot moves two steps East and is now at position (2, 0), facing East.

- **Input:** `robot.step(2); robot.getPos(); robot.getDir();`  \
  **Explanation:** After moving two more steps East, the robot is at position (4, 0), still facing East.

- **Input:** `robot.step(2); robot.step(1); robot.step(4); robot.getPos(); robot.getDir();`  \
  **Explanation:** After additional steps, the robot moves in different directions, including turning when hitting boundaries, eventually reaching position (1, 2) facing West.

{{< dots >}}
## Approach 🚀
The robot's movement can be tracked by updating its position and direction after each step, with a check for boundary conditions that triggers a 90-degree turn.

### Initial Thoughts 💭
- The robot's direction can be represented by an integer (0 = East, 1 = North, 2 = West, 3 = South).
- The robot's movement follows a simple grid structure, with checks for boundaries.
- We need to manage the robot's movement and turning behavior efficiently, especially given the constraint on the number of operations.
{{< dots >}}
### Edge Cases 🌐
- The grid must always have a valid size.
- For large step values, use modulo operations to prevent excessive calculations.
- Ensure that the robot turns properly when hitting boundaries.
- Ensure that the total number of operations doesn't exceed 10^4.
{{< dots >}}
## Code 💻
```cpp
int w, h, i, j, dir, per;
Robot(int width, int height) {
    w = width;
    h = height;
    i = 0;
    j = 0;
    dir = 0;
    per = 2 * (w + h - 2);
}

void step(int num) {
    if(num > per) {
        num %= per;
        if(i == 0 && j == 0 && dir == 0) dir = 3;
    }
    int mo[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while(num) {
        int x = i + mo[dir][0], y = j + mo[dir][1];
        if(x >= w || y >= h || x < 0 || y < 0) {
            dir = (dir + 1) % 4;
        } else {
            i = x;
            j = y;
            num--;
        }
    }
    
}

vector<int> getPos() {
    return {i, j};
}

string getDir() {
    switch(dir) {
        case 0: return "East"   ; break;
        case 1: return "North"  ; break;    
        case 2: return "West"   ; break;    
        case 3: return "South"  ; break;
    }
    return "";
}
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
```

This class simulates the movement of a robot in a grid with specified width and height. The robot's position and direction are updated based on the steps it takes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int w, h, i, j, dir, per;
	```
	This line declares the necessary variables: `w` and `h` for the width and height of the grid, `i` and `j` for the robot's current position, `dir` for the robot's current direction, and `per` for the perimeter of the grid.

2. **Constructor Definition**
	```cpp
	Robot(int width, int height) {
	```
	This is the constructor for the `Robot` class that initializes the robot's grid size (`w` and `h`), its starting position (`i` and `j`), its starting direction (`dir`), and calculates the perimeter of the grid.

3. **Width Initialization**
	```cpp
	    w = width;
	```
	This line initializes the width of the grid with the input `width` value.

4. **Height Initialization**
	```cpp
	    h = height;
	```
	This line initializes the height of the grid with the input `height` value.

5. **Initial Position**
	```cpp
	    i = 0;
	```
	This line sets the robot's initial horizontal position (`i`) to 0 (top-left corner).

6. **Initial Position**
	```cpp
	    j = 0;
	```
	This line sets the robot's initial vertical position (`j`) to 0 (top-left corner).

7. **Direction Initialization**
	```cpp
	    dir = 0;
	```
	This line sets the robot's initial direction (`dir`) to 0, which represents East.

8. **Perimeter Calculation**
	```cpp
	    per = 2 * (w + h - 2);
	```
	This line calculates the perimeter of the grid, which is used to optimize movement by limiting unnecessary steps.

9. **Step Function Definition**
	```cpp
	void step(int num) {
	```
	This function defines how the robot steps based on the input `num`, which represents the number of steps to move.

10. **Check for Perimeter Exceedance**
	```cpp
	    if(num > per) {
	```
	This checks if the number of steps exceeds the perimeter of the grid. If so, it reduces the steps to stay within the perimeter.

11. **Modulo Adjustment**
	```cpp
	        num %= per;
	```
	This line applies the modulo operation to `num` to ensure the number of steps does not exceed the perimeter.

12. **Initial Direction Adjustment**
	```cpp
	        if(i == 0 && j == 0 && dir == 0) dir = 3;
	```
	This condition adjusts the direction to South if the robot starts at the top-left corner facing East.

13. **Movement Directions Setup**
	```cpp
	    int mo[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	```
	This array defines the movement directions: East, North, West, and South, using coordinate shifts.

14. **Movement Loop**
	```cpp
	    while(num) {
	```
	This loop runs while there are steps left to take.

15. **Calculate New Position**
	```cpp
	        int x = i + mo[dir][0], y = j + mo[dir][1];
	```
	This calculates the new position (`x`, `y`) based on the current direction of movement.

16. **Boundary Check**
	```cpp
	        if(x >= w || y >= h || x < 0 || y < 0) {
	```
	This condition checks if the new position is outside the grid boundaries.

17. **Change Direction**
	```cpp
	            dir = (dir + 1) % 4;
	```
	If the new position is outside the grid, the direction is updated to the next direction in the cycle (East -> North -> West -> South).

18. **Position Update**
	```cpp
	        } else {
	```
	If the new position is within bounds, proceed to update the robot's position.

19. **Update Position**
	```cpp
	            i = x;
	```
	This updates the robot's horizontal position (`i`).

20. **Update Position**
	```cpp
	            j = y;
	```
	This updates the robot's vertical position (`j`).

21. **Step Decrement**
	```cpp
	            num--;
	```
	This decrements the number of steps remaining.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(num)
- **Worst Case:** O(num)

The time complexity is proportional to the number of steps the robot takes, as each step is processed sequentially.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only store the robot's position and direction.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/walking-robot-simulation-ii/description/)

---
{{< youtube 10111CfY7GQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
