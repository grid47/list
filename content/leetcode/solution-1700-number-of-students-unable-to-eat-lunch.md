
+++
authors = ["grid47"]
title = "Leetcode 1700: Number of Students Unable to Eat Lunch"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1700: Number of Students Unable to Eat Lunch in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Queue","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "d_cvtFwnOZg"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi/d_cvtFwnOZg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countStudents(vector<int>& A, vector<int>& B) {
        int count[] = {0, 0}, n = A.size(), k;
        for (int a : A)
            count[a]++;
        for (k = 0; k < n && count[B[k]] > 0; ++k)
            count[B[k]]--;
        return n - k;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires counting the number of students who could not be matched with their preferred seats in a scenario where students have specific seating preferences. The input consists of two integer arrays:
- **A**: An array representing the preferred seats for each student.
- **B**: An array representing the actual seats available.

The goal is to determine how many students end up without a matching seat based on their preferences.

### Approach

To tackle this problem, we can adopt a straightforward approach:
1. **Count the Preferences**: First, we will count the number of students who prefer each seat in array A.
2. **Match Students to Seats**: Next, we will iterate through the available seats in array B and decrement the count for each seat that a student prefers.
3. **Count Unmatched Students**: Finally, we can compute how many students were not able to find a matching seat based on their preferences by comparing the total number of students to the count of students matched.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the implementation:

```cpp
class Solution {
public:
    int countStudents(vector<int>& A, vector<int>& B) {
        // Initialize a count array to keep track of seat preferences.
        int count[] = {0, 0}; // We assume two types of seats (0 and 1)
        int n = A.size(); // Get the number of students
        int k; // Variable to keep track of the number of students who found seats

        // Count preferences for seats from array A
        for (int a : A)
            count[a]++; // Increment the count for each preferred seat

        // Match students to their preferred seats from array B
        for (k = 0; k < n && count[B[k]] > 0; ++k)
            count[B[k]]--; // Decrease the count of preferred seats if matched

        // Return the number of students who couldn't find a matching seat
        return n - k; // Total students minus the number matched
    }
};
```

#### Step-by-Step Explanation

1. **Initialize Variables**:
   - We declare an integer array `count` to track how many students prefer each type of seat. Here, we assume there are two types of seats (0 and 1). The array size can be adjusted depending on the actual problem constraints.
   - We also initialize `n` to hold the size of array A, which represents the total number of students.

2. **Count Preferences**:
   - We iterate through each element in array A, and for every student’s preferred seat (`a`), we increment the corresponding index in the `count` array. This gives us the total number of students preferring each seat type.

3. **Match Students to Seats**:
   - We initialize `k` to zero and start iterating through array B, which represents the actual seats available.
   - For each available seat `B[k]`, we check if there are any students preferring that seat by looking at the `count` array. If `count[B[k]]` is greater than zero, it means a student can be matched to that seat. We then decrement the count for that seat to signify that one student has taken that seat.
   - We continue this process until either we have checked all seats in B or run out of students that can be matched (i.e., when `count[B[k]]` becomes zero).

4. **Return Unmatched Students**:
   - Finally, we return the number of students who could not be matched to a seat. This is calculated as `n - k`, where `k` is the count of students that found seats.

### Complexity

- **Time Complexity**: 
  - The time complexity is \(O(n)\), where \(n\) is the number of students. We traverse the preferences and the available seats in linear time.

- **Space Complexity**: 
  - The space complexity is \(O(1)\) as we only use a fixed-size array to count the preferences.

### Conclusion

The solution efficiently counts how many students cannot be seated according to their preferences using a linear time approach. Here are the key takeaways from this code:

1. **Efficient Counting**: The use of an integer array to count preferences allows for quick updates and checks, leading to an efficient solution.

2. **Simple Logic**: The implementation relies on straightforward iteration and counting, making it easy to understand and maintain.

3. **Scalability**: The solution can be adapted to accommodate different types of seats or more complex matching rules by modifying the count logic.

In summary, this solution demonstrates how to efficiently manage matching problems using basic data structures and algorithms, providing a clear and effective way to handle student seating preferences.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)

---
{{< youtube d_cvtFwnOZg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
