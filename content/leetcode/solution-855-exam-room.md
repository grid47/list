
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
+++



---
**Code:**

{{< highlight cpp >}}
class ExamRoom {
    int N;
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
 */
{{< /highlight >}}
---

### Problem Statement

The problem involves simulating a seating arrangement for students in an exam room. We are given a room with a certain number of seats (`n`), where students can seat themselves based on certain rules:

1. The seat that a student selects should maximize the distance from other students.
2. If multiple seats are at the same maximum distance, select the seat with the smallest index.

Additionally, once a student has seated, they may leave, freeing up their seat. We need to implement the `ExamRoom` class that supports the following operations:

- **`seat()`**: Returns the seat number where the student should sit.
- **`leave(int p)`**: Frees up the seat `p`, allowing future students to occupy it.

The challenge is to design the seating strategy efficiently, considering both seating and leaving operations.

### Approach

To solve this problem, the strategy relies on keeping track of the currently occupied seats and selecting the optimal seat based on the distance from existing students. Here's how we approach it:

1. **Seat Selection**:
   - The first student always sits at seat `0` when the room is empty.
   - After that, the best seat is chosen based on the maximum distance from existing students. The available seats can be split into segments between consecutive seated students or between the boundaries (seat `0` and seat `N-1`).
   - For each segment, the seat closest to the middle is selected to maximize the distance from the nearest student.

2. **Leave Operation**:
   - When a student leaves, the corresponding seat is removed from the list of occupied seats, making that seat available for future students.

### Code Breakdown (Step by Step)

#### Step 1: Data Structure Initialization

```cpp
int N;
vector<int> L;
```

- **`N`**: The total number of seats in the room.
- **`L`**: A list that holds the currently occupied seats, sorted in increasing order.

#### Step 2: Constructor

```cpp
ExamRoom(int n) {
    N = n;
}
```

- The constructor initializes the total number of seats (`N`) in the exam room. The `L` vector is initialized as an empty list to store the occupied seats.

#### Step 3: Seat Method

```cpp
int seat() {
    if(L.size() == 0) {
        L.push_back(0);
        return 0;
    }
```

- If the room is empty (i.e., no seats are occupied), the first student sits at seat `0`, and that seat is added to the `L` list.

```cpp
    int d = max(L[0], N - 1 - L[L.size() - 1]);
    for(int i = 0; i < L.size() - 1; i++) d = max(d, (L[i + 1] - L[i]) / 2);
```

- If there are already students seated, the algorithm calculates the maximum possible distance from an existing student. 
- The first step checks the distance from the first seat (`L[0]`) and the last seat (`N-1 - L[L.size() - 1]`), which are the boundaries of the room.
- Then, we iterate through the list `L` of occupied seats and calculate the maximum distance between adjacent seats. The available distance is halved since the student will sit in the middle of the segment between two seats.

```cpp
    if(L[0] == d) {
        L.insert(L.begin(), 0);
        return L[0];
    }
```

- If the seat at the first position (`0`) has the maximum distance (`d`), the student will sit at seat `0`. This is because the boundary seat is the farthest from other students, and no other seat can offer a better distance.

```cpp
    for(int i = 0; i < L.size() - 1; i++) {
        if((L[i + 1] - L[i])/2 == d) {
            L.insert(L.begin() + i + 1, (L[i] + L[i +1])/2);
            return L[i + 1];
        }
    }
```

- If the maximum distance is found between two adjacent students (seats `L[i]` and `L[i + 1]`), the student will sit in the middle of those seats. The new seat is added to the list `L`.

```cpp
    L.push_back(N - 1);
    return N - 1;
}
```

- If no student is seated at the boundary or middle of two adjacent students, the student sits at the last seat (`N-1`).

#### Step 4: Leave Method

```cpp
void leave(int p) {
    for(int i = 0; i < L.size(); i++) if(L[i] == p) L.erase(L.begin() + i);
}
```

- The `leave` method removes the student from the seat `p` by searching for the seat in the list `L` and erasing it.

### Complexity Analysis

#### Time Complexity:

- **`seat()` method**: 
   - **Finding the best seat** involves scanning through the list of occupied seats. In the worst case, we have to iterate through the entire list of seats, which takes **O(k)** time, where `k` is the number of students seated.
   - **Inserting a seat** into the list takes **O(k)** time due to the shifting of elements in the vector.
   - Thus, the overall time complexity for the `seat()` method is **O(k)**, where `k` is the number of students currently seated.

- **`leave()` method**: 
   - The `leave()` method involves searching for the seat in the list and removing it. Searching for the seat takes **O(k)** time, and removing an element takes **O(k)** time due to shifting elements in the vector.
   - Thus, the overall time complexity for the `leave()` method is **O(k)**.

#### Space Complexity:

- **Space Complexity**: The space complexity is dominated by the vector `L` that stores the list of occupied seats. Therefore, the space complexity is **O(k)**, where `k` is the number of students currently seated.

### Conclusion

The `ExamRoom` class is designed to simulate the process of students seating and leaving in a room while maintaining optimal seating distance. The `seat()` method ensures that each student sits in the optimal seat by calculating the maximum distance from others, while the `leave()` method allows for freeing up seats when a student leaves.

This solution is efficient, with the time complexity of each operation proportional to the number of students seated (`O(k)`), making it scalable for moderate-sized rooms. The use of a vector to maintain the list of occupied seats ensures that the algorithm handles seat selections and removals in a straightforward and understandable manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/exam-room/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
