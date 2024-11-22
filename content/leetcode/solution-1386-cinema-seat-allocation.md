
+++
authors = ["grid47"]
title = "Leetcode 1386: Cinema Seat Allocation"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1386: Cinema Seat Allocation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Bit Manipulation"]
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
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n * 2;
        unordered_map<int, char> m;
        for(auto r: reservedSeats)
            if(r[1] > 1 && r[1] < 10)
                m[r[0]] |= 1 << (r[1] - 2);
        
        for(auto [row, seats]: m) {
            int left  = seats & 0b11110000;
            int mid   = seats & 0b00111100;
            int right = seats & 0b00001111;
            ans -= left && mid && right ? 2 : 1;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves determining the maximum number of families that can be seated in a theater given certain reserved seats. Each family occupies a row of seats in a theater, and there are specific seating arrangements to consider. Each row in the theater has a certain number of seats, and some of these seats may be reserved for individual customers, preventing families from sitting together. The goal is to calculate how many families can be seated, assuming families prefer to sit in groups of four in specific configurations.

### Approach

To solve this problem, we can follow these steps:

1. **Initialization**: Start by assuming that every row can seat two families, thus initializing the answer to \(2 \times n\), where \(n\) is the number of rows.

2. **Mapping Reserved Seats**: Use a map to track reserved seats in each row. Each reserved seat affects the seating configurations available for families.

3. **Checking Seating Configurations**: For each row that has reserved seats, check the possible configurations where families can sit:
   - **Left Group**: Seats 2, 3, and 4 (binary representation: `11110000`)
   - **Middle Group**: Seats 4, 5, and 6 (binary representation: `00111100`)
   - **Right Group**: Seats 6, 7, and 8 (binary representation: `00001111`)

4. **Adjusting the Answer**: Based on the reserved seats in each row, adjust the number of families that can be seated. If a configuration is blocked, reduce the count accordingly.

### Code Breakdown (Step by Step)

The provided C++ code implements the above approach. Here’s a detailed breakdown:

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```
   - The `Solution` class contains a method to compute the maximum number of families that can be seated.

2. **Method Declaration**:
   ```cpp
       int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
           int ans = n * 2;
           unordered_map<int, char> m;
   ```
   - The `maxNumberOfFamilies` method takes two parameters: an integer `n` (the number of rows) and a vector of vectors `reservedSeats` containing reserved seat information.
   - It initializes `ans` to \(n \times 2\) (maximum number of families that can be seated) and uses an unordered map `m` to track reserved seats for each row.

3. **Mapping Reserved Seats**:
   ```cpp
           for(auto r: reservedSeats)
               if(r[1] > 1 && r[1] < 10)
                   m[r[0]] |= 1 << (r[1] - 2);
   ```
   - This loop iterates through each reserved seat. If the reserved seat is between seats 2 and 9, it updates the map to mark the reserved seat using bitwise operations. The expression `1 << (r[1] - 2)` shifts a bit to the left to represent the reserved seat in binary format.

4. **Checking Configurations**:
   ```cpp
           for(auto [row, seats]: m) {
               int left  = seats & 0b11110000;
               int mid   = seats & 0b00111100;
               int right = seats & 0b00001111;
   ```
   - For each row in the map, this code segment checks the reserved seats against the three potential family configurations using bitwise AND operations with binary masks.
   - `left`, `mid`, and `right` hold the status of each configuration.

5. **Adjusting the Answer**:
   ```cpp
               ans -= left && mid && right ? 2 : 1;
           }
           return ans;
       }
   };
   ```
   - Depending on which configurations are blocked (if any), the answer is decremented. If all three configurations are blocked, it reduces by 2; otherwise, it reduces by 1.
   - Finally, the method returns the calculated maximum number of families that can be seated.

### Complexity

- **Time Complexity**:
  - The time complexity is \(O(m + n)\), where \(m\) is the number of reserved seats, and \(n\) is the number of rows. This accounts for iterating through reserved seats and then through the rows with reserved seats.

- **Space Complexity**:
  - The space complexity is \(O(n)\) due to the use of an unordered map that stores reserved seat data for each row.

### Conclusion

The solution efficiently determines the maximum number of families that can be seated in a theater given specific seat reservations. By utilizing bitwise operations and a map to track reserved seats, the algorithm is both space and time efficient. The implementation illustrates a practical application of data structures and bit manipulation in solving a combinatorial problem. This code serves as a useful reference for developers and students alike, providing insights into managing complex seating arrangements and constraints in computational problems. Understanding this solution can enhance problem-solving skills in competitive programming and algorithm design, as it highlights the importance of leveraging data structures effectively to derive optimal solutions. Overall, the `maxNumberOfFamilies` function is a robust implementation that elegantly balances efficiency with clarity, making it a valuable addition to any algorithm repertoire.

[`Link to LeetCode Lab`](https://leetcode.com/problems/cinema-seat-allocation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
