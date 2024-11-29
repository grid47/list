
+++
authors = ["grid47"]
title = "Leetcode 855: Exam Room"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 855: Exam Room in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are tasked with simulating an exam room where students will choose seats based on a strategy that maximizes their distance from the closest person already seated. If multiple seats have the same distance, the student will choose the seat with the smallest index. Additionally, students can leave the room, freeing up their seats.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n, which represents the number of seats in the exam room. The object should allow for two operations: seating a student and having a student leave a seat.
- **Example:** `Input: 
["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"] 
[[10], [], [], [], [], [4], []]`
- **Constraints:**
	- 1 <= n <= 10^9
	- At most 10^4 calls will be made to the 'seat' and 'leave' operations.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each 'seat' operation, return the seat index where the student will sit. For the 'leave' operation, there is no return value.
- **Example:** `Output: 
[null, 0, 9, 4, 2, null, 5]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To implement the seating strategy such that students sit at the seat that maximizes the distance from the nearest student. If there are multiple options, choose the smallest seat index.

- Step 1: Implement a data structure to track the positions of students already seated.
- Step 2: For each 'seat' operation, calculate the maximum distance to the nearest student for each empty seat and choose the seat that maximizes this distance.
- Step 3: For each 'leave' operation, remove the seat from the list of occupied seats.
{{< dots >}}
### Problem Assumptions ✅
- There will always be at least one seat available when a student arrives.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: 
["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"] 
[[10], [], [], [], [], [4], []]`  \
  **Explanation:** Initially, no student is seated. The first student sits at seat 0. The next student sits at the farthest available seat, seat 9. The next one sits at seat 4 (the middle of the remaining seats). The next student sits at seat 2. When the student at seat 4 leaves, the next student sits at seat 5 (the next best available seat).

{{< dots >}}
## Approach 🚀
To efficiently manage seating and leaving operations, we maintain a list of occupied seats and calculate the optimal seat choice for each 'seat' operation.

### Initial Thoughts 💭
- The problem requires balancing between finding the optimal seat and managing the students' movements.
- A list of occupied seats is essential to calculate the seat with the greatest distance to the nearest student.
{{< dots >}}
### Edge Cases 🌐
- N/A: The problem guarantees there is always at least one seat and one student.
- Efficient handling of operations is necessary when n is large, up to 10^9.
- If there is only one student and one seat, the student always sits at seat 0.
- There is a guarantee that no student will leave a seat that is unoccupied.
{{< dots >}}
## Code 💻
```cpp
vector<int> L;
public:
ExamRoom(int n) {
    N = n;
}

int seat() {
    if(L.size() == 0) {
        L.push_back(0);
        return 0;
    }
 
    
    int d = max(L[0], N - 1 - L[L.size() - 1]);
    for(int i = 0; i < L.size() - 1; i++) d = max(d, (L[i + 1] - L[i]) /2);
    
    if(L[0] == d) {
        
        L.insert(L.begin(), 0);
        
        return L[0];
    }
    
    for(int i = 0; i < L.size() - 1; i++) {
        if((L[i + 1] - L[i])/2 == d) {
            L.insert(L.begin() + i + 1, (L[i] + L[i +1])/2);
            return L[i + 1];
        }
     }
    
        L.push_back(N - 1);
        return N - 1;
    
}

void leave(int p) {
    for(int i = 0; i < L.size(); i++) if(L[i] == p) L.erase(L.begin() + i);
}
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
```

This code defines a class `ExamRoom` with methods to manage seating arrangements based on the distance between people. It includes methods for seating (`seat()`) and a method for leaving (`leave(int p)`).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Data Structures**
	```cpp
	vector<int> L;
	```
	Declares a vector `L` to store the positions of people in the room.

2. **Access Modifiers**
	```cpp
	public:
	```
	Indicates that the following methods are publicly accessible.

3. **Constructor**
	```cpp
	ExamRoom(int n) {
	```
	Constructor of the `ExamRoom` class, initializing the room with a given size `n`.

4. **Initialization**
	```cpp
	    N = n;
	```
	Initializes the variable `N` with the given size of the room `n`.

5. **Method Definition**
	```cpp
	int seat() {
	```
	Defines the `seat()` method, which assigns a seat to a person based on available space.

6. **Conditionals**
	```cpp
	    if(L.size() == 0) {
	```
	Checks if the room is empty. If it is, it assigns the first seat at position 0.

7. **Action**
	```cpp
	        L.push_back(0);
	```
	Inserts the first person at position 0.

8. **Return**
	```cpp
	        return 0;
	```
	Returns the position of the newly seated person (0).

9. **Distance Calculation**
	```cpp
	    int d = max(L[0], N - 1 - L[L.size() - 1]);
	```
	Calculates the maximum distance between the first and last seats.

10. **Loop**
	```cpp
	    for(int i = 0; i < L.size() - 1; i++) d = max(d, (L[i + 1] - L[i]) / 2);
	```
	Calculates the maximum possible distance between two people in the room.

11. **Conditional Check**
	```cpp
	    if(L[0] == d) {
	```
	Checks if the maximum distance is between the first seat and the available space.

12. **Action**
	```cpp
	        L.insert(L.begin(), 0);
	```
	Inserts a new person at the first seat.

13. **Return**
	```cpp
	        return L[0];
	```
	Returns the position of the newly seated person (0).

14. **Loop**
	```cpp
	    for(int i = 0; i < L.size() - 1; i++) {
	```
	Starts a loop to find the best seat based on the maximum distance.

15. **Conditional Check**
	```cpp
	        if((L[i + 1] - L[i]) / 2 == d) {
	```
	Checks if the gap between two adjacent seats is half of the maximum distance.

16. **Action**
	```cpp
	            L.insert(L.begin() + i + 1, (L[i] + L[i +1]) / 2);
	```
	Seats the person at the optimal position between two others.

17. **Return**
	```cpp
	            return L[i + 1];
	```
	Returns the position where the person was seated.

18. **Action**
	```cpp
	        L.push_back(N - 1);
	```
	Inserts a new person at the last seat.

19. **Return**
	```cpp
	        return N - 1;
	```
	Returns the position of the newly seated person (last seat).

20. **Method Definition**
	```cpp
	void leave(int p) {
	```
	Defines the `leave(int p)` method, which removes a person from the room at position `p`.

21. **Loop**
	```cpp
	    for(int i = 0; i < L.size(); i++) if(L[i] == p) L.erase(L.begin() + i);
	```
	Finds the person at position `p` and removes them from the list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for a single seat when no one is in the room.
- **Average Case:** O(n) for finding the best seat when a student is seated.
- **Worst Case:** O(n) per 'seat' operation in the worst case, where the seating strategy requires checking multiple seats.



### Space Complexity 💾
- **Best Case:** O(1) when no students are in the room.
- **Worst Case:** O(n) for storing the list of occupied seats.



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/exam-room/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
