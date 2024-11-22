
+++
authors = ["grid47"]
title = "Leetcode 1040: Moving Stones Until Consecutive II"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1040: Moving Stones Until Consecutive II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4Xhq2NDbA-I"
youtube_upload_date="2020-01-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4Xhq2NDbA-I/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& pos) {
        sort(pos.begin(), pos.end());
        
        int low = INT_MAX;
        int j = 0, n = pos.size();
        for(int i = 0; i < n; i++) {
            while(pos[i] - pos[j] + 1 > n) j++;
            
            int cnt = i - j + 1;
            
            if(cnt == n - 1 && pos[i] - pos[j] + 1 == n - 1)
                low = min(low, 2);
            else low = min(low, n - cnt);
        }
        return vector<int>{low, max(pos[n - 1] - pos[1] + 1 - (n - 1), pos[n - 2] - pos[0] + 1 - (n - 1))};
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem involves moving stones positioned at distinct integers along a line. Each stone can be moved to an adjacent position, and we aim to determine two values:
1. The minimum number of moves required to arrange the stones in a continuous segment.
2. The maximum number of moves possible when rearranging the stones under specific constraints.

### Approach
To solve the problem, we can break it down into several key steps:

1. **Sorting the Positions**: The first step is to sort the array of stone positions. This will help us easily calculate the number of stones in any segment of the line.

2. **Finding the Minimum Moves**:
   - Use a sliding window approach to calculate how many stones can fit in a continuous segment of length equal to the total number of stones.
   - Maintain a variable to track the minimum number of moves needed to achieve the goal. 
   - Check for special conditions where moving only one stone might yield a quicker solution.

3. **Calculating Maximum Moves**: The maximum number of moves is determined by the gaps between the outermost stones. Specifically, evaluate how many positions can be left empty on the ends after filling in the middle.

### Code Breakdown (Step by Step)

1. **Class Definition**: The solution is encapsulated within a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Signature**: 
   - The `numMovesStonesII` function takes a vector of integers `pos`, which represents the positions of the stones, and returns a vector of two integers representing the minimum and maximum moves.

   ```cpp
   vector<int> numMovesStonesII(vector<int>& pos) {
   ```

3. **Sorting the Positions**:
   - The positions of the stones are sorted in ascending order to facilitate easier calculations for continuous segments.

   ```cpp
   sort(pos.begin(), pos.end());
   ```

4. **Initializing Variables**:
   - We initialize `low` to `INT_MAX` to keep track of the minimum moves.
   - Two pointers `j` and `n` are set, where `j` is for the sliding window, and `n` is the size of the positions vector.

   ```cpp
   int low = INT_MAX;
   int j = 0, n = pos.size();
   ```

5. **Iterating Through Stone Positions**:
   - We use a loop to iterate through each stone position with index `i`.

   ```cpp
   for(int i = 0; i < n; i++) {
   ```

6. **Adjusting the Sliding Window**:
   - For each position, adjust the sliding window with `j` to ensure the segment of stones can fit within a continuous block of size `n`. This is done by checking if the current stone's position minus the starting stone's position plus one exceeds `n`.

   ```cpp
   while(pos[i] - pos[j] + 1 > n) j++;
   ```

7. **Calculating Count of Stones in the Segment**:
   - The variable `cnt` calculates how many stones fit in the current segment from `j` to `i`.

   ```cpp
   int cnt = i - j + 1;
   ```

8. **Determining Minimum Moves**:
   - If we have `n - 1` stones in the current segment and they exactly fill the space, we set `low` to 2 (special case where one stone can be moved out). 
   - Otherwise, the minimum moves would be the number of gaps.

   ```cpp
   if(cnt == n - 1 && pos[i] - pos[j] + 1 == n - 1)
       low = min(low, 2);
   else 
       low = min(low, n - cnt);
   ```

9. **Calculating Maximum Moves**:
   - The maximum number of moves is calculated based on the largest gaps between the outermost stones, ensuring we consider the positions of the first two and the last two stones.

   ```cpp
   return vector<int>{
       low, 
       max(pos[n - 1] - pos[1] + 1 - (n - 1), pos[n - 2] - pos[0] + 1 - (n - 1))
   };
   ```

### Complexity Analysis
- **Time Complexity**: The overall time complexity of this solution is \(O(n \log n)\), where \(n\) is the number of stones. This complexity arises primarily from the sorting step.
  
- **Space Complexity**: The space complexity is \(O(1)\) in terms of extra space since we are not using any additional data structures that grow with input size (excluding the input and output).

### Conclusion
The provided code effectively calculates the minimum and maximum number of moves required to align stones positioned along a line using a sorting and sliding window approach. 

By first sorting the positions and then utilizing a two-pointer technique, we can efficiently determine how many moves are necessary to create a continuous segment of stones. The sliding window technique ensures that we only examine feasible segments of positions, thus optimizing our calculations.

This solution is not only efficient but also clearly structured, making it easy to understand and maintain. The use of the minimum and maximum moves calculations provides a comprehensive overview of the possible configurations of the stones, demonstrating the effectiveness of algorithmic problem-solving in combinatorial scenarios.

In summary, the `numMovesStonesII` function presents a robust and efficient method for addressing the challenge of stone positioning, which can be applicable in various scenarios within computational geometry and optimization problems.


[`Link to LeetCode Lab`](https://leetcode.com/problems/moving-stones-until-consecutive-ii/description/)

---
{{< youtube 4Xhq2NDbA-I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
