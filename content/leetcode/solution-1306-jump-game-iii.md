
+++
authors = ["grid47"]
title = "Leetcode 1306: Jump Game III"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1306: Jump Game III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9oUhzPLmLZQ"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/9oUhzPLmLZQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0)
                return true;
            int l = i - arr[i];
            int r = i + arr[i];
            arr[i] = -arr[i];
            if (l > -1 && arr[l] > -1) q.push(l);
            if (r < n  && arr[r] > -1) q.push(r);
        }
        
        return false;
    }
};
{{< /highlight >}}
---


### Problem Statement
Given an integer array `arr` and a starting index `start`, each element in `arr` represents the maximum number of steps you can move either left or right. The task is to determine if you can reach any index with a value of zero by jumping to the left or right. You can only visit each index once. If it’s possible to reach an element with a value of zero, return `true`; otherwise, return `false`.

### Approach
This solution utilizes **Breadth-First Search (BFS)** to explore each possible index that can be reached by jumping left or right:
1. **Initialize Queue for BFS**: A queue is used to explore each index, starting from the given `start` index.
2. **Explore Each Jump**: For each index, the solution calculates two possible moves:
   - **Left Jump**: Move to `i - arr[i]`.
   - **Right Jump**: Move to `i + arr[i]`.
3. **Mark Visited Indices**: To prevent revisiting indices, each visited index is marked by negating its value, ensuring it will not be added back into the queue.
4. **Check for Target Value**: If any of the indices have a value of zero, return `true`. If the queue becomes empty without finding a zero, return `false`.

This BFS approach is efficient because it explores each reachable index only once, leveraging the negation technique to mark visited indices.

### Code Breakdown (Step by Step)

1. **Class and Method Definition**:
   - The class `Solution` has a public method `canReach` that takes an integer array `arr` and an integer `start` as input and returns a boolean indicating if reaching a zero is possible.

   ```cpp
   class Solution {
   public:
       bool canReach(vector<int>& arr, int start) {
   ```

2. **Initialize Variables**:
   - `n` stores the size of `arr`.
   - A queue `q` is initialized with the `start` index to begin BFS from this index.

   ```cpp
           int n = arr.size();
           queue<int> q;
           q.push(start);
   ```

3. **BFS Loop**:
   - The loop runs while there are indices to explore in `q`.

   ```cpp
           while(!q.empty()) {
               int i = q.front();
               q.pop();
   ```

4. **Check for Zero**:
   - If `arr[i]` is zero, the function returns `true` since a zero has been reached.

   ```cpp
               if (arr[i] == 0)
                   return true;
   ```

5. **Calculate Left and Right Jumps**:
   - `l` stores the left jump index (`i - arr[i]`), and `r` stores the right jump index (`i + arr[i]`).

   ```cpp
               int l = i - arr[i];
               int r = i + arr[i];
   ```

6. **Mark Index as Visited**:
   - To prevent revisiting `i`, its value in `arr` is negated.

   ```cpp
               arr[i] = -arr[i];
   ```

7. **Add Valid Jumps to Queue**:
   - The code checks if `l` and `r` are within bounds and have not been visited (i.e., have a positive value). If valid, they are added to `q`.

   ```cpp
               if (l > -1 && arr[l] > -1) q.push(l);
               if (r < n  && arr[r] > -1) q.push(r);
           }
   ```

8. **Return False if No Zero is Found**:
   - If the loop completes without finding a zero, return `false`.

   ```cpp
           return false;
       }
   };
   ```

### Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the number of elements in `arr`. In the worst case, each element is added to the queue once and processed once.
- **Space Complexity**: \(O(n)\), as the queue could potentially hold up to all elements in the worst case.

### Conclusion
This solution uses BFS to explore each possible index in `arr` starting from the `start` index. By using a queue and marking visited indices by negation, the algorithm efficiently explores reachable indices without revisiting them, ensuring optimal performance. The BFS approach is well-suited to this problem as it allows systematic exploration of all possible paths to find a zero, returning true if one is found or false otherwise. This solution is both time-efficient and memory-efficient for large arrays.

[`Link to LeetCode Lab`](https://leetcode.com/problems/jump-game-iii/description/)

---
{{< youtube 9oUhzPLmLZQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
