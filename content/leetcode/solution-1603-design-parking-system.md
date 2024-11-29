
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
comments = true
+++



---
You are tasked with designing a parking system for a parking lot that has three types of parking spaces: large, medium, and small. Each type of parking space has a fixed number of available slots. Your goal is to implement the `ParkingSystem` class that supports the operations of initializing the parking system and parking a car based on its type.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of operations and their respective arguments. The first operation is the initialization of the ParkingSystem object, followed by multiple addCar operations to park the cars.
- **Example:** `["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[2, 1, 3], [1], [2], [3], [1]]`
- **Constraints:**
	- 0 <= big, medium, small <= 1000
	- carType is 1, 2, or 3
	- At most 1000 calls will be made to addCar

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array of results for each addCar operation. The result is `true` if the car is successfully parked, or `false` if no space is available for the car type.
- **Example:** `[null, true, true, false, false]`
- **Constraints:**
	- Each call to addCar must return a boolean indicating whether the car was parked.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to manage the parking slots based on the car type and check if there is an available parking space before allowing a car to park.

- 1. Initialize the ParkingSystem with the available slots for each type of parking space.
- 2. For each `addCar` operation, check if the corresponding parking space is available.
- 3. If available, park the car and update the respective slot count.
- 4. If not available, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The system is initialized correctly with the provided number of slots for each type.
- All `addCar` operations will be valid (i.e., they will only try to park a car type that is supported).
{{< dots >}}
## Examples 🧩
- **Input:** `["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[2, 1, 3], [1], [2], [3], [1]]`  \
  **Explanation:** In this example, we start with 2 large slots, 1 medium slot, and 3 small slots. The first car parks successfully, followed by the second car. The third car cannot park because there are no small slots, and the fourth car cannot park because there are no large slots available.

{{< dots >}}
## Approach 🚀
The approach involves managing available parking spaces and handling `addCar` operations efficiently based on the number of available slots for each car type.

### Initial Thoughts 💭
- We need to track the number of available parking spaces for each type of car.
- Each `addCar` operation should check if the corresponding space is available.
- The parking system should handle car parking requests sequentially, and update the parking slots count after each successful operation.
{{< dots >}}
### Edge Cases 🌐
- The input may have no `addCar` operations after initialization.
- The system should handle up to 1000 `addCar` operations efficiently.
- All slots could be empty at the start.
- Ensure that the number of available slots is properly updated after each operation.
{{< dots >}}
## Code 💻
```cpp
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
```

This is the implementation of the ParkingSystem class that manages parking spots for three types of vehicles: big, medium, and small. It provides methods to add cars and keep track of their parking availability.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int bm, mm, sm;
	```
	These variables represent the capacity for big, medium, and small parking spots, respectively.

2. **Variable Declaration**
	```cpp
	int bc, mc, sc;    
	```
	These variables track the current number of parked cars for big, medium, and small spots, respectively.

3. **Constructor**
	```cpp
	ParkingSystem(int big, int medium, int small) {
	```
	Constructor to initialize the ParkingSystem with the given capacities for big, medium, and small parking spots.

4. **Assignment**
	```cpp
	    bm = big;
	```
	Assign the provided 'big' parking capacity to the 'bm' variable.

5. **Assignment**
	```cpp
	    mm = medium;
	```
	Assign the provided 'medium' parking capacity to the 'mm' variable.

6. **Assignment**
	```cpp
	    sm = small;
	```
	Assign the provided 'small' parking capacity to the 'sm' variable.

7. **Initialization**
	```cpp
	    bc = 0;
	```
	Initialize the 'bc' variable, which tracks the number of big cars, to 0.

8. **Initialization**
	```cpp
	    mc = 0;
	```
	Initialize the 'mc' variable, which tracks the number of medium cars, to 0.

9. **Initialization**
	```cpp
	    sc = 0;
	```
	Initialize the 'sc' variable, which tracks the number of small cars, to 0.

10. **Method Definition**
	```cpp
	bool addCar(int ct) {
	```
	Method to add a car to the parking system. The car type (ct) determines the parking category.

11. **Switch Statement**
	```cpp
	    switch(ct) {
	```
	The switch statement is used to handle the car type and decide which parking lot to check and update.

12. **Case 1 - Big Car**
	```cpp
	        case 1:
	```
	Handle the case where the car type is 1, representing a big car.

13. **Condition Check**
	```cpp
	            if(bc < bm) {
	```
	Check if the number of big cars is less than the big parking capacity.

14. **Increment**
	```cpp
	                bc++;
	```
	If there is space available, increment the count of big cars.

15. **Return**
	```cpp
	                return true;
	```
	Return 'true' indicating that the car has been successfully parked.

16. **End Switch**
	```cpp
	            break;
	```
	Break out of the switch statement.

17. **Case 2 - Medium Car**
	```cpp
	        case 2:
	```
	Handle the case where the car type is 2, representing a medium car.

18. **Condition Check**
	```cpp
	            if(mc < mm) {
	```
	Check if the number of medium cars is less than the medium parking capacity.

19. **Increment**
	```cpp
	                mc++;
	```
	If there is space available, increment the count of medium cars.

20. **Return**
	```cpp
	                return true;
	```
	Return 'true' indicating that the car has been successfully parked.

21. **End Switch**
	```cpp
	            break;
	```
	Break out of the switch statement.

22. **Case 3 - Small Car**
	```cpp
	        case 3:
	```
	Handle the case where the car type is 3, representing a small car.

23. **Condition Check**
	```cpp
	            if(sc < sm) {
	```
	Check if the number of small cars is less than the small parking capacity.

24. **Increment**
	```cpp
	                sc++;
	```
	If there is space available, increment the count of small cars.

25. **Return**
	```cpp
	                return true;
	```
	Return 'true' indicating that the car has been successfully parked.

26. **End Switch**
	```cpp
	            break;
	```
	Break out of the switch statement.

27. **Return False**
	```cpp
	    return false;
	```
	Return 'false' if no parking space is available for the requested car type.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant for each operation, as it only involves checking the number of available parking spaces for a specific car type.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only store a fixed number of parking slot counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-parking-system/description/)

---
{{< youtube d5zCHesOrSk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
