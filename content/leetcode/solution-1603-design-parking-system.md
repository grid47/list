
+++
authors = ["grid47"]
title = "Leetcode 1603: Design Parking System"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1603: Design Parking System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Simulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "d5zCHesOrSk"
youtube_upload_date="2023-05-29"
youtube_thumbnail="https://i.ytimg.com/vi/d5zCHesOrSk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class ParkingSystem {
public:
    int bm, mm, sm;
    int bc, mc, sc;    
    ParkingSystem(int big, int medium, int small) {
        bm = big;
        mm = medium;
        sm = small;
        bc = 0;
        mc = 0;
        sc = 0;
    }
    
    bool addCar(int ct) {
        switch(ct) {
            case 1:
                if(bc < bm) {
                    bc++;
                    return true;
                }
                break;
            case 2:
                if(mc < mm) {
                    mc++;
                    return true;
                }                
                break;
            case 3:
                if(sc < sm) {
                    sc++;
                    return true;
                }
                break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves managing a parking system that can accommodate three types of vehicles: big, medium, and small cars. The system needs to keep track of how many of each type of vehicle can be parked and whether a new vehicle can be added based on the available parking spaces. Each type of vehicle has a limited number of spaces, and the system should provide functionality to add cars of different types while checking for available spaces.

### Approach

To implement this parking system, we can define a class called `ParkingSystem` that will manage the parking slots for each vehicle type. The core functionality involves:

1. **Initializing the Parking System**: We will set up the total capacity for each type of vehicle when the `ParkingSystem` object is created.
  
2. **Adding Cars**: The system will provide a method to add a car of a specified type. This method will check if there is available space for the requested vehicle type and increment the count of parked vehicles accordingly.

3. **Returning Results**: The method will return a boolean value indicating whether the car was successfully added or not.

### Code Breakdown (Step by Step)

Here's a detailed breakdown of the provided code:

```cpp
class ParkingSystem {
public:
    int bm, mm, sm;  // Maximum capacity for big, medium, and small cars
    int bc, mc, sc;  // Current count of parked big, medium, and small cars
```
- The class `ParkingSystem` is defined with public member variables to store the maximum capacity (`bm`, `mm`, `sm`) for each type of car and the current count of parked cars (`bc`, `mc`, `sc`).

```cpp
    ParkingSystem(int big, int medium, int small) {
        bm = big;
        mm = medium;
        sm = small;
        bc = 0;
        mc = 0;
        sc = 0;
    }
```
- The constructor `ParkingSystem(int big, int medium, int small)` initializes the maximum capacity for each type of vehicle. The current counts for parked cars are initialized to zero.

```cpp
    bool addCar(int ct) {
        switch(ct) {
            case 1:
                if(bc < bm) {
                    bc++;
                    return true;
                }
                break;
            case 2:
                if(mc < mm) {
                    mc++;
                    return true;
                }                
                break;
            case 3:
                if(sc < sm) {
                    sc++;
                    return true;
                }
                break;
        }
        return false;
    }
```
- The `addCar(int ct)` method is defined to handle the addition of a car based on its type (`ct`):
  - If `ct` is `1`, it checks if there is space for a big car (`bc < bm`). If so, it increments the count of parked big cars and returns `true`.
  - If `ct` is `2`, it checks for a medium car in the same manner (`mc < mm`).
  - If `ct` is `3`, it checks for a small car (`sc < sm`).
- If the respective parking slot is full for any type, the method does not increment the count and returns `false`.

```cpp
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
```
- The class ends with a comment describing how to instantiate the `ParkingSystem` object and how to call the `addCar` method.

### Complexity

- **Time Complexity**: The time complexity for the `addCar` method is \(O(1)\) since the method consists of a constant number of comparisons and assignments, regardless of the number of cars.
  
- **Space Complexity**: The space complexity is also \(O(1)\) since the class uses a fixed number of variables for storage, independent of the number of cars or the input size.

### Conclusion

The `ParkingSystem` class effectively manages parking slots for different types of vehicles using a straightforward and efficient design. The key features of this implementation include:

1. **Clear Structure**: The separation of vehicle types and their respective counts makes it easy to understand the current state of the parking system.

2. **Efficiency**: The use of constant-time operations for adding cars ensures that the system remains responsive, even with frequent requests to park vehicles.

3. **Simplicity**: The use of a switch statement for handling different car types keeps the code clean and easy to follow.

In summary, this solution provides a robust framework for managing a parking system with different vehicle types, ensuring that the constraints of parking capacity are respected while allowing for efficient vehicle management. This implementation is particularly useful in scenarios where space management is critical, such as urban parking systems or automated car parks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-parking-system/description/)

---
{{< youtube d5zCHesOrSk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
