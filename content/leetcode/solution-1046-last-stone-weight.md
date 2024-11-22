
+++
authors = ["grid47"]
title = "Leetcode 1046: Last Stone Weight"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1046: Last Stone Weight in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "bmcFr1AdiJg"
youtube_upload_date="2023-04-24"
youtube_thumbnail="https://i.ytimg.com/vi/bmcFr1AdiJg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(int x: stones) {
            pq.push(x);
        }
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if(pq.empty()) return x;
            
            int y = pq.top();
             pq.pop();
             if(y == x) {}
             else {
                    pq.push(abs(y-x));
             }            
        }
        return 0;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem involves a list of stones represented by their weights. When two stones collide, the stone with the lesser weight is destroyed, and the other stone's weight is reduced by the weight of the destroyed stone. This process continues until no stones are left or only one stone remains. The goal is to find the weight of the last remaining stone, or return 0 if all stones are destroyed.

### Approach
To solve this problem, we utilize a **max-heap** (priority queue) to always efficiently retrieve and remove the two heaviest stones at each step. The approach is as follows:

1. **Initialization**: Use a priority queue to store the stones' weights.
2. **Collision Simulation**: Continuously extract the two heaviest stones, simulate their collision, and reinsert the resulting weight back into the priority queue.
3. **Termination**: The process continues until only one stone remains in the priority queue or it becomes empty. The weight of the last stone is returned.

### Code Breakdown (Step by Step)

1. **Class Definition**: The code is encapsulated in a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Priority Queue Declaration**: A priority queue `pq` is declared to hold the stones' weights. This data structure allows us to efficiently access the largest elements.

   ```cpp
   priority_queue<int> pq;
   ```

3. **Main Function**: The function `lastStoneWeight` takes a vector of integers, `stones`, as input.

   ```cpp
   int lastStoneWeight(vector<int>& stones) {
   ```

4. **Inserting Stones into the Priority Queue**:
   - We iterate over each stone's weight and push it into the priority queue. The priority queue automatically arranges the stones so that the heaviest stone can always be accessed quickly.

   ```cpp
   for(int x: stones) {
       pq.push(x);
   }
   ```

5. **Collision Loop**:
   - A `while` loop is used to process the stones as long as the priority queue is not empty.

   ```cpp
   while(!pq.empty()) {
   ```

6. **Extracting Heaviest Stones**:
   - The heaviest stone `x` is retrieved using `pq.top()` and removed from the queue with `pq.pop()`.
   - If the queue becomes empty after this operation, it means `x` is the last stone, and its weight is returned.

   ```cpp
   int x = pq.top();
   pq.pop();
   if(pq.empty()) return x;
   ```

7. **Collision Logic**:
   - The second heaviest stone `y` is also retrieved and removed.
   - If `y` is equal to `x`, both stones are destroyed, and nothing is added back to the queue.
   - If they are different, the absolute difference `abs(y - x)` is calculated and pushed back into the priority queue. This represents the weight of the remaining stone after the collision.

   ```cpp
   int y = pq.top();
   pq.pop();
   if(y == x) {}
   else {
       pq.push(abs(y - x));
   }
   ```

8. **Final Return Statement**:
   - If the priority queue is emptied out and no stones are left, the function returns 0.

   ```cpp
   return 0;
   }
   ```

### Complexity Analysis
- **Time Complexity**: The overall time complexity of the algorithm is \(O(n \log n)\), where \(n\) is the number of stones. Each insertion and extraction operation from the priority queue takes \(O(\log n)\), and since each stone is inserted and removed at most once, the total complexity is governed by \(O(n \log n)\).
  
- **Space Complexity**: The space complexity is \(O(n)\) due to the storage of the stones in the priority queue.

### Conclusion
The `lastStoneWeight` function efficiently solves the problem of determining the weight of the last remaining stone using a priority queue. By always focusing on the two heaviest stones, the algorithm simulates the collisions in an optimal manner.

This implementation highlights the effectiveness of using a max-heap data structure in problems involving repeated access to the maximum element, enabling a clear and efficient approach to simulating the collision process.

The design of this solution is not only efficient but also easy to understand, making it suitable for competitive programming and interview preparation contexts. It serves as a good example of leveraging data structures to manage complexity and ensure optimal performance in algorithms.

Overall, the code illustrates best practices in algorithm design, including clear separation of logic, efficient use of data structures, and adherence to computational complexity principles, providing a robust solution to the problem at hand.


[`Link to LeetCode Lab`](https://leetcode.com/problems/last-stone-weight/description/)

---
{{< youtube bmcFr1AdiJg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
