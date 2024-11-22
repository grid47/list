
+++
authors = ["grid47"]
title = "Leetcode 2139: Minimum Moves to Reach Target Score"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2139: Minimum Moves to Reach Target Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "y3r6o712auw"
youtube_upload_date="2022-01-16"
youtube_thumbnail="https://i.ytimg.com/vi/y3r6o712auw/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<int, map<int, int>> mp;
    int dp(int cur, int end, int dops) {
        if(cur == end) return 0;
        if(cur > end) return INT_MAX - 1;
        
        if(mp.count(cur) && mp[cur].count(dops)) return mp[cur][dops];
        
        int ans = 1 + dp(cur + 1, end, dops);
        if(dops > 0)
        ans = min(ans, 1 + dp(cur * 2, end, dops - 1));
        
        return mp[cur][dops] = ans;
    }
    
    int minMoves(int end, int dops) {
        
        int cnt = 0;
        
        while(end > 1) {
            if(end % 2) end -= 1;
            else if(dops > 0) {
                end /= 2;
                dops--;
            } else {
                cnt += (end -1);
                break;                
            }
            cnt++;
        }
        return cnt;
        
        // return dp(1, end, dops);
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the minimum number of moves required to reach a target number (`end`) starting from 1, with the option to double the current number a limited number of times (`dops`). Each move can either increment the current number by 1 or, if available, use a "double" operation to multiply the current number by 2, decreasing the allowed number of doubles (`dops`) by 1. The goal is to minimize the total number of moves to reach the target.

### Approach

The solution employs a combination of dynamic programming and greedy strategies. The main idea is to count how many moves are necessary to reach the target number, considering both the increment operations and the doubling operations allowed. The algorithm evaluates the steps required in two phases:

1. **Greedy Approach**: Start from the target number and work backwards to determine how many steps it would take to reach 1. The operations considered include:
   - If the current number is odd, subtract 1 (since odd numbers can't be halved).
   - If the current number is even and we still have doubles available (`dops > 0`), halve the number and decrement `dops`.
   - If the current number is even and no doubles are available, directly count the moves required to decrement down to 1.

2. **Dynamic Programming (Commented Out)**: A recursive function with memoization could be employed to compute the minimum moves recursively, but in this implementation, it is replaced with the greedy method.

### Code Breakdown (Step by Step)

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```
   - This defines the `Solution` class, which contains methods for solving the problem.

2. **Data Structure**:
   ```cpp
   map<int, map<int, int>> mp;
   ```
   - A nested map (`mp`) is used to store previously computed results for specific states defined by the current value and remaining doubles. This structure helps in memoization.

3. **Dynamic Programming Function**:
   ```cpp
   int dp(int cur, int end, int dops) {
   ```
   - The `dp` function is defined to compute the minimum moves recursively. It takes three parameters:
     - `cur`: The current value we are processing.
     - `end`: The target value we want to reach.
     - `dops`: The number of doubling operations left.

4. **Base Cases**:
   ```cpp
   if(cur == end) return 0;
   if(cur > end) return INT_MAX - 1;
   ```
   - If the current value equals the target, no more moves are needed, so return 0.
   - If the current value exceeds the target, it is impossible to reach the target from this state, so return a large number to signify an invalid state.

5. **Memoization Check**:
   ```cpp
   if(mp.count(cur) && mp[cur].count(dops)) return mp[cur][dops];
   ```
   - Before performing calculations, the function checks if the result for the current state has already been computed. If it has, it returns the stored result.

6. **Recursive Calculation**:
   ```cpp
   int ans = 1 + dp(cur + 1, end, dops);
   if(dops > 0)
       ans = min(ans, 1 + dp(cur * 2, end, dops - 1));
   ```
   - The recursive relation calculates the minimum moves:
     - First, it counts the moves required by incrementing the current value (`cur + 1`).
     - If doubling is allowed (`dops > 0`), it also considers the option of doubling the current value (`cur * 2`).

7. **Memoization Store**:
   ```cpp
   return mp[cur][dops] = ans;
   ```
   - The result is stored in the memoization map for future reference before returning the answer.

8. **Main Function**:
   ```cpp
   int minMoves(int end, int dops) {
   ```
   - The `minMoves` function is defined to initiate the process. It sets up the variables needed for counting moves.

9. **Counting Moves**:
   ```cpp
   int cnt = 0;
   while(end > 1) {
       if(end % 2) end -= 1;
       else if(dops > 0) {
           end /= 2;
           dops--;
       } else {
           cnt += (end - 1);
           break;                
       }
       cnt++;
   }
   return cnt;
   ```
   - The loop continues until `end` is greater than 1. The logic inside the loop uses the greedy approach as described:
     - If `end` is odd, subtract 1.
     - If `end` is even and we can still double, divide by 2 and decrement `dops`.
     - If `end` is even but no doubles are left, directly subtract down to 1 and add the remaining moves to `cnt`.

10. **Return Statement**:
    ```cpp
    return cnt;
    ```
    - Finally, the function returns the total count of moves needed to reach the target.

11. **Commented Out DP Approach**:
    ```cpp
    // return dp(1, end, dops);
    ```
    - This line suggests an alternative solution using the recursive approach but is commented out in this implementation.

12. **End of Class**:
    ```cpp
    };
    ```
    - This closing brace signifies the end of the `Solution` class.

### Complexity Analysis

- **Time Complexity**: \(O(\log(\text{end}))\)
  - The while loop inside the `minMoves` function will iterate approximately logarithmically with respect to the value of `end` since every operation either halves the number or decrements it.

- **Space Complexity**: \(O(\log(\text{end}))\) (for the call stack in the recursive version)
  - If the recursive approach is used, the space complexity would primarily come from the recursion stack.

### Conclusion

The `minMoves` function effectively calculates the minimum number of moves required to reach a target number by combining both greedy and dynamic programming strategies. It efficiently counts the moves while considering the options available for incrementing or doubling the current number, making it a powerful solution to the problem.

This implementation serves as an excellent example of optimizing solutions through both greedy and dynamic programming principles, showcasing the importance of understanding problem constraints and efficiently using available operations. This problem is common in algorithmic challenges and competitive programming, making it a useful example for aspiring programmers to learn from. 

By grasping the logic behind this solution, developers can enhance their problem-solving skills and apply similar strategies to other algorithmic challenges involving numeric operations and state transitions.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-moves-to-reach-target-score/description/)

---
{{< youtube y3r6o712auw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
