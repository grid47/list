
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
+++



---
**Code:**

{{< highlight cpp >}}
class Robot {
public:
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
 */
{{< /highlight >}}
---

### Problem Statement

The task involves creating a `Robot` class that simulates the movement of a robot within a rectangular grid defined by its width and height. The robot starts at the top-left corner of the grid, facing east, and is capable of moving in four directions: east, north, west, and south. The challenge is to allow the robot to step a specified number of times, wrapping around when it reaches the edges of the grid, and to retrieve its current position and direction after the steps have been taken.

### Approach

1. **Initialization**: When creating an instance of the `Robot`, we need to initialize its position, direction, and the perimeter of the grid. The position is set to the top-left corner (0, 0), and the direction is initially set to east (0).

2. **Movement Logic**: The robot can move a specified number of steps. When the robot reaches the boundaries of the grid, it changes direction (turns) instead of moving outside the grid. The robot's movement can be handled using a predefined array that represents the changes in coordinates for each direction.

3. **Wrapping Movement**: If the robot is instructed to move more steps than the perimeter of the grid, the effective number of steps is calculated using modulo operation to wrap around correctly.

4. **Position and Direction Retrieval**: After executing the movement, we need methods to retrieve the robot's current position and direction.

### Code Breakdown (Step by Step)

1. **Class Definition**: The `Robot` class is defined with private attributes for width (`w`), height (`h`), current x-coordinate (`i`), current y-coordinate (`j`), current direction (`dir`), and the perimeter of the grid (`per`).

   ```cpp
   class Robot {
   public:
       int w, h, i, j, dir, per;
   ```

2. **Constructor**: The constructor initializes the width and height of the grid and sets the initial position to `(0, 0)` and direction to east (`0`). The perimeter is calculated using the formula \(2 \times (\text{width} + \text{height} - 2)\) to determine how many total steps can be taken before returning to the starting point.

   ```cpp
   Robot(int width, int height) {
       w = width;
       h = height;
       i = 0;
       j = 0;
       dir = 0;
       per = 2 * (w + h - 2);
   }
   ```

3. **Step Function**: The `step` function takes the number of steps to move. It first checks if the number of steps exceeds the perimeter; if so, it reduces the step count using the modulo operator. A movement array (`mo`) defines the direction vectors for east, north, west, and south.

   ```cpp
   void step(int num) {
       if(num > per) {
           num %= per;
           if(i == 0 && j == 0 && dir == 0) dir = 3;
       }
       int mo[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
   ```

4. **Movement Loop**: The function contains a loop that executes the movement commands. If moving in the current direction would result in going out of bounds, the direction is changed clockwise. If not, the position is updated and the step count is decremented.

   ```cpp
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
   ```

5. **Getting Position**: The `getPos` method returns the current position of the robot as a vector containing the x and y coordinates.

   ```cpp
   vector<int> getPos() {
       return {i, j};
   }
   ```

6. **Getting Direction**: The `getDir` method returns the current direction as a string based on the value of `dir`. Each case corresponds to a specific direction.

   ```cpp
   string getDir() {
       switch(dir) {
           case 0: return "East";
           case 1: return "North";
           case 2: return "West";
           case 3: return "South";
       }
       return "";
   }
   ```

### Complexity

- **Time Complexity**: The time complexity for the `step` function is O(n) in the worst case, where n is the number of steps requested. In most cases, the effective steps are reduced by the perimeter calculation, making it efficient for larger inputs.

- **Space Complexity**: The space complexity is O(1) since we only use a fixed amount of space for variables and do not utilize any data structures that grow with input size.

### Conclusion

This `Robot` class implementation provides a clear and efficient way to model the movement of a robot within a bounded grid. The combination of directional logic and boundary checking ensures that the robot operates within the defined constraints, allowing for realistic movement simulation. The ability to easily retrieve the robot's position and direction enhances the utility of the class for potential applications in robotics and simulation scenarios.

Overall, the design is intuitive, making it easy to extend or modify if additional features are required, such as different movement strategies or additional grid dimensions. The implementation serves as an excellent demonstration of how to apply object-oriented programming principles to solve practical problems in a structured manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/walking-robot-simulation-ii/description/)

---
{{< youtube 10111CfY7GQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
