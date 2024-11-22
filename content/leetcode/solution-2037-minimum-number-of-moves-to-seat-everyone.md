
+++
authors = ["grid47"]
title = "Leetcode 2037: Minimum Number of Moves to Seat Everyone"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2037: Minimum Number of Moves to Seat Everyone in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Counting Sort"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wS7Ag33hf8E"
youtube_upload_date="2024-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/wS7Ag33hf8E/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int res = 0;
        for (int i = 0; i < seats.size(); i++) res += abs(seats[i] - students[i]);
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given two lists, `seats` and `students`, each representing the positions of seats and students respectively, our goal is to calculate the minimum total number of moves required to seat each student. Each student can only move directly to a seat and the aim is to minimize the sum of the moves for all students.

### Approach

To achieve the minimum movement:
1. **Sort both lists** - Sorting ensures that we can pair each student with a seat in a way that minimizes the travel distance, as the closest match in positions is likely between sorted lists.
2. **Calculate moves** - After sorting, the ith student can be paired with the ith seat. Calculating the absolute difference between each student and seat position and summing these differences gives the minimum moves required.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
```

- We first sort `seats` and `students`. This minimizes the movement for each pair, as a student positioned close to a seat in sorted order will require fewer moves than an unoptimized pairing.

```cpp
        int res = 0;
        for (int i = 0; i < seats.size(); i++) res += abs(seats[i] - students[i]);
```

- Initialize `res` to accumulate the total moves required. We loop through each pair (student, seat) and calculate `abs(seats[i] - students[i])`, which represents the movement required for that student. Summing these differences gives the minimum total moves.

```cpp
        return res;
    }
};
```

- Finally, we return `res`, which contains the total minimum moves.

### Complexity

- **Time Complexity**: O(n log n), where `n` is the number of seats (or students). Sorting both `seats` and `students` takes O(n log n), and the for-loop takes O(n).
- **Space Complexity**: O(1), as the sorting is done in place and no additional data structures are used aside from a few integer variables.

### Conclusion

This solution efficiently minimizes the movements needed by pairing students and seats in sorted order. Sorting both lists allows for optimal pairing, minimizing the movement for each student-seat match. This approach provides an elegant and straightforward solution to the problem with minimal computational overhead, making it suitable for larger inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/)

---
{{< youtube wS7Ag33hf8E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
