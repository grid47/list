
+++
authors = ["grid47"]
title = "Leetcode 1072: Flip Columns For Maximum Number of Equal Rows"
date = "2024-07-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1072: Flip Columns For Maximum Number of Equal Rows in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xj3ltfSh9Io"
youtube_upload_date="2020-03-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xj3ltfSh9Io/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mtx) {
        unordered_map<string, int> mp;
        for(auto x: mtx) {
            string s = "";
            int top = x[0];
            for(int i = 0; i < x.size(); i++) {
                if(x[i] == top) s += '1';
                else s += '0';
            }
            mp[s]++;
        }
        int res = 0;
        for(auto [k, v]: mp)
            res = max(res, v);
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to determine the maximum number of rows in a binary matrix that can be made equal after flipping any number of rows. A flip on a row inverts its values (0s become 1s and 1s become 0s). To clarify, two rows are considered equal if one can be transformed into the other through any number of flips. 

### Approach
To solve this problem, we can utilize a hashmap (unordered_map) to keep track of the distinct patterns of the rows. By transforming each row into a binary representation where all equivalent rows (rows that can be made equal through flipping) are treated as the same, we can count how many rows share the same pattern. The maximum count of any pattern in the hashmap will give us the answer.

Here’s how the approach works:
1. Iterate through each row of the matrix.
2. For each row, generate a string representation where:
   - A '1' represents the value that is the same as the first element of the row.
   - A '0' represents the value that is different from the first element.
3. Use a hashmap to count the occurrences of each unique string representation.
4. The maximum value in the hashmap represents the maximum number of equal rows that can be obtained after performing the necessary flips.

### Code Breakdown (Step by Step)

1. **Class Definition**:
   The `Solution` class encapsulates the method to solve the problem.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Signature**:
   The method `maxEqualRowsAfterFlips` takes a 2D vector (matrix) as input and returns an integer.

   ```cpp
   int maxEqualRowsAfterFlips(vector<vector<int>>& mtx) {
   ```

3. **HashMap Initialization**:
   An unordered_map is used to store the frequency of each unique pattern generated from the rows.

   ```cpp
   unordered_map<string, int> mp;
   ```

4. **Iterating Through Each Row**:
   The code loops through each row in the matrix.

   ```cpp
   for(auto x: mtx) {
   ```

5. **Generating String Representation**:
   For each row, a string `s` is created. The first element of the row is stored in `top`. As we iterate through the elements of the row, we build the string based on whether the current element is equal to `top` or not.

   ```cpp
   string s = "";
   int top = x[0];
   for(int i = 0; i < x.size(); i++) {
       if(x[i] == top) s += '1';
       else s += '0';
   }
   ```

6. **Updating the HashMap**:
   The hashmap `mp` is updated with the generated string `s` as the key, and the value is incremented to keep track of how many times this pattern has been encountered.

   ```cpp
   mp[s]++;
   ```

7. **Finding the Maximum Count**:
   After processing all rows, we need to find the maximum count of any pattern stored in the hashmap.

   ```cpp
   int res = 0;
   for(auto [k, v]: mp)
       res = max(res, v);
   ```

8. **Return Result**:
   Finally, the maximum count is returned as the result.

   ```cpp
   return res;
   }
   ```

### Complexity Analysis
- **Time Complexity**: The overall time complexity is \(O(n \cdot m)\), where \(n\) is the number of rows and \(m\) is the number of columns in the matrix. This is due to the nested loop where we iterate over each element of each row to build the string representation.
  
- **Space Complexity**: The space complexity is \(O(k)\), where \(k\) is the number of unique row patterns that can be formed. In the worst case, all rows are distinct, and thus the hashmap could potentially store \(n\) distinct patterns.

### Conclusion
The solution provided effectively addresses the problem of maximizing the number of equal rows in a binary matrix through a systematic approach using a hashmap. By transforming rows into binary strings that capture their equivalence, we can efficiently count and determine the maximum number of equal rows achievable after performing the necessary flips.

This technique leverages the properties of strings and hashmaps to optimize both the counting process and the retrieval of maximum counts. The approach is straightforward, efficient, and showcases the power of combinatorial counting in algorithm design.

In summary, this method provides an effective solution to the problem while maintaining optimal performance, making it suitable for competitive programming and practical applications where matrix transformations are required.


[`Link to LeetCode Lab`](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/)

---
{{< youtube xj3ltfSh9Io >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
