
+++
authors = ["Yasir"]
title = "Leetcode 2545: Sort the Students by Their Kth Score"
date = "2017-11-09"
description = "Solution to Leetcode 2545"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int k;
    int partition(vector<vector<int>>& score, int low, int high) {

      // select the rightmost element as pivot
      vector<int> pivot = score[high];

      // pointer for greater element
      int i = (low - 1);

      // traverse each element of the array
      // compare them with the pivot
      for (int j = low; j < high; j++) {
        if (score[j][k] > pivot[k]) {

          // if element smaller than pivot is found
          // swap it with the greater element pointed by i
          i++;

          // swap element at i with element at j
          swap(score[i], score[j]);
        }
      }

      // swap pivot with the greater element at i
      swap(score[i + 1], score[high]);

      // return the partition point
      return (i + 1);
    }
    void quickSort(vector<vector<int>>& score, int low, int high) {
        if (low < high) {
            int pi = partition(score, low, high);
            quickSort(score, low, pi - 1);
            quickSort(score, pi + 1, high);
        }
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        this->k = k;
        quickSort(score, 0, score.size() - 1);
        return score;
    }
};
{{< /highlight >}}

