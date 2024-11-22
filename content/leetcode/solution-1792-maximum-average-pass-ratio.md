
+++
authors = ["grid47"]
title = "Leetcode 1792: Maximum Average Pass Ratio"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1792: Maximum Average Pass Ratio in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZjydWQCVg80"
youtube_upload_date="2021-03-14"
youtube_thumbnail="https://i.ytimg.com/vi/ZjydWQCVg80/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [&](double pass, double total) {
            return (pass + 1)/(total +1) -(pass/ total);
        };

        double total = 0;
        priority_queue<pair<double, array<int, 2>>> pq;
        for(auto &c: classes) {
            total += (double) c[0]/c[1];
            pq.push({profit(c[0], c[1]), {c[0], c[1]}});
        }

        while(extraStudents--) {
            auto [addedProfit, c] = pq.top(); pq.pop();
            total += addedProfit;
            pq.push({profit(c[0] + 1, c[1] + 1), {c[0] +1, c[1] +1}});
        }
        return total/ classes.size();
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to maximize the average ratio of students passing a class after distributing a given number of extra students across multiple classes. Each class has a certain number of students who have passed and the total number of students. The goal is to allocate the extra students in such a way that the average pass ratio across all classes is maximized.

### Approach

To achieve the goal of maximizing the average pass ratio after distributing the extra students, we can utilize a greedy algorithm combined with a priority queue (max-heap). Here's how the approach works:

1. **Profit Calculation**: First, we need to define a function that calculates the potential profit gained by adding one student to a class. This is done by comparing the pass ratio before and after adding a student.

2. **Initialization**: We initialize a total variable to keep track of the current average ratio of students passing across all classes and a priority queue to manage which classes would benefit the most from receiving additional students.

3. **Heap Management**: By utilizing a priority queue, we can efficiently select the class that will yield the highest increase in the average pass ratio with each additional student.

4. **Distribution of Extra Students**: We iteratively allocate the extra students to the class that currently provides the best potential increase in the average pass ratio, updating the total and re-evaluating the potential profits after each allocation.

5. **Final Calculation**: After distributing all extra students, we compute the final average pass ratio.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
```
- We define the `Solution` class and the public method `maxAverageRatio`, which accepts a 2D vector `classes` (where each inner vector contains the number of passing students and the total number of students) and an integer `extraStudents`.

```cpp
        auto profit = [&](double pass, double total) {
            return (pass + 1)/(total +1) -(pass/ total);
        };
```
- We define a lambda function `profit` that calculates the increase in the pass ratio when one additional student is added. The formula computes the difference between the new ratio after adding a student and the current ratio.

```cpp
        double total = 0;
        priority_queue<pair<double, array<int, 2>>> pq;
```
- We initialize a `total` variable to accumulate the current pass ratio across all classes and a priority queue `pq` to hold the potential profits from adding students to each class.

```cpp
        for(auto &c: classes) {
            total += (double) c[0]/c[1];
            pq.push({profit(c[0], c[1]), {c[0], c[1]}});
        }
```
- We iterate over each class, compute the current pass ratio, and accumulate it into `total`. We also push the potential profit of adding one student to each class into the priority queue.

```cpp
        while(extraStudents--) {
            auto [addedProfit, c] = pq.top(); pq.pop();
            total += addedProfit;
            pq.push({profit(c[0] + 1, c[1] + 1), {c[0] +1, c[1] +1}});
        }
```
- We allocate students to the class that offers the highest profit by popping from the priority queue. After adding a student, we recalculate the potential profit for that class and push the updated profit back into the queue.

```cpp
        return total/ classes.size();
    }
};
```
- Finally, we return the average pass ratio, which is computed as the total accumulated pass ratio divided by the number of classes.

### Complexity

- **Time Complexity**: The overall time complexity is \(O(n \log n)\), where \(n\) is the number of classes. This complexity arises from inserting and extracting elements from the priority queue \(n\) times.

- **Space Complexity**: The space complexity is \(O(n)\) due to the storage required for the priority queue.

### Conclusion

The `maxAverageRatio` function effectively maximizes the average pass ratio across multiple classes by strategically allocating extra students to those classes that would benefit the most from additional enrollment. 

This algorithm demonstrates the power of greedy methods in optimization problems, particularly when combined with data structures like priority queues to efficiently manage and evaluate potential choices. In practical applications, this technique can be useful in educational contexts where resource allocation is critical for enhancing student performance metrics.

Understanding this algorithm enhances our problem-solving toolkit for similar optimization challenges, including scenarios in resource management, project planning, and performance improvement strategies in various fields. 

The approach highlights the importance of calculating and prioritizing potential gains, allowing us to make informed decisions that lead to the best possible outcomes in competitive environments.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-average-pass-ratio/description/)

---
{{< youtube ZjydWQCVg80 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
