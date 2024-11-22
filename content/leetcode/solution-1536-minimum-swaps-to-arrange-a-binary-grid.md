
+++
authors = ["grid47"]
title = "Leetcode 1536: Minimum Swaps to Arrange a Binary Grid"
date = "2024-06-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1536: Minimum Swaps to Arrange a Binary Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OLA5Qwt4NKw"
youtube_upload_date="2020-08-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/OLA5Qwt4NKw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        set<int> found;
        
        vector<int> arr(n, 0);
        
        for(int i = 0; i < n; i++) {
            
            int j = n - 1, cnt = 0;
            while(j > -1 && grid[i][j] == 0) {
                j--;
                cnt++;
            }
            
            for(int k = n - 1; k >= 0; k--) {
                if(cnt >= k && !found.count(k)) {
                    found.insert(k);
                    arr[i] = n - 1 - k;
                    break;
                }
            }
        }
        
        if(found.size() != n) return -1;
        
        return bubble(arr);
    }
    
    int bubble(vector<int> &arr) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
        for(int j = 1; j < arr.size(); j++)
            if(arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                cnt++;
            }
        
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand requires us to determine the minimum number of swaps needed to rearrange a given 2D grid such that every row of the grid ends with a certain number of zeroes. Specifically, for a grid of size \(n \times n\), each row \(i\) must have at least \(n - i - 1\) trailing zeroes. The objective is to transform the grid into this desired configuration using the least number of adjacent swaps within the rows.

### Approach

To achieve the desired configuration in the grid with minimal swaps, we can follow these steps:

1. **Calculate Trailing Zeroes**: For each row in the grid, count the number of trailing zeroes. This can be done by starting from the end of the row and counting how many consecutive zeroes are present.
   
2. **Determine Required Positions**: For each row, based on the count of trailing zeroes, determine the minimum number of zeroes required for that row to satisfy the configuration. This will be the position of the last non-zero element in that row.

3. **Bubble Sort Logic**: After establishing the required zero positions for each row, we need to arrange the current positions of non-zero elements in accordance with the required positions. This can be accomplished by using a bubble sort-like approach, where we count how many swaps are necessary to sort the array representing the positions of the non-zero elements.

4. **Return Result**: If any row does not have enough trailing zeroes, return -1 to indicate it's impossible to achieve the desired configuration. Otherwise, return the total number of swaps counted.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); // Get the size of the grid
        
        set<int> found; // To track which positions have been found
        vector<int> arr(n, 0); // Array to hold the number of swaps required for each row
        
        for(int i = 0; i < n; i++) {
            int j = n - 1, cnt = 0; // Start from the end of the row
            
            // Count trailing zeroes
            while(j > -1 && grid[i][j] == 0) {
                j--;
                cnt++;
            }
            
            // Determine the required position based on count of zeroes
            for(int k = n - 1; k >= 0; k--) {
                if(cnt >= k && !found.count(k)) {
                    found.insert(k); // Mark this position as found
                    arr[i] = n - 1 - k; // Store the position for sorting
                    break;
                }
            }
        }
        
        if(found.size() != n) return -1; // If not all positions are filled, return -1
        
        return bubble(arr); // Call bubble function to count swaps
    }
```

- **Count Trailing Zeroes**: We iterate through each row of the grid and count how many trailing zeroes exist. This is done with a nested loop that starts from the last element of the row and moves backward until it finds a non-zero element.
- **Store Positions**: We use a set to ensure that we only consider valid positions and that we have unique entries in our array.
- **Check Completion**: If not all rows can meet the required zeroes condition, we return `-1`.

```cpp
    int bubble(vector<int> &arr) {
        int cnt = 0; // Counter for swaps
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 1; j < arr.size(); j++) {
                if(arr[j - 1] > arr[j]) { // If the previous element is greater than the next
                    swap(arr[j - 1], arr[j]); // Swap them
                    cnt++; // Increment the swap count
                }
            }
        }
        return cnt; // Return total swaps counted
    }
};
```

- **Bubble Sort Logic**: This nested loop implements a simple bubble sort to count how many adjacent swaps are needed to sort the array of positions. Each time we perform a swap, we increment our swap count.

### Complexity

#### Time Complexity
- The time complexity of this solution is \(O(n^2)\) in the worst case because:
  - We traverse each row to count trailing zeroes in \(O(n)\).
  - We perform a nested loop for the bubble sort which takes \(O(n^2)\) time.

#### Space Complexity
- The space complexity is \(O(n)\) due to the additional storage used for the `arr` and `found` data structures.

### Conclusion

This solution effectively counts the number of swaps required to rearrange the grid to satisfy the condition of trailing zeroes for each row. By using a combination of counting and sorting, we can determine the minimal number of adjacent swaps necessary to achieve the desired configuration. 

**Key Takeaways**:
- **Greedy Counting**: The method effectively utilizes greedy counting for trailing zeroes and finding positions.
- **Simple Swapping Mechanism**: The bubble sort approach provides a straightforward way to count the number of swaps, although it's not the most efficient for larger datasets.
- **Edge Cases Handling**: The solution properly handles edge cases where achieving the target configuration is impossible, making it robust for various input scenarios.

Overall, this approach provides a clear and effective method for solving the problem while adhering to complexity constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/)

---
{{< youtube OLA5Qwt4NKw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
