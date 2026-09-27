
Hospital Patient Priority Queue Using Max Heap

Aim

To implement a Max Heap for managing hospital patients according to their severity score and to compare Heap Sort and Quick Sort based on their performance and complexity.

Given Patient Severity Scores

45, 72, 30, 90, 65, 50, 85

A higher severity score represents a higher priority.

---

1. Max Heap Insertion

A Max Heap is a complete binary tree in which the parent node is greater than or equal to its children.

Heap after each insertion

Step| Inserted Score| Max Heap
1| 45| 45
2| 72| 72, 45
3| 30| 72, 45, 30
4| 90| 90, 72, 30, 45
5| 65| 90, 72, 30, 45, 65
6| 50| 90, 72, 50, 45, 65, 30
7| 85| 90, 72, 85, 45, 65, 30, 50

Final Max Heap

             90
           /    \
         72      85
        /  \    /  \
      45   65  30   50

The highest-priority patient has severity 90, which is stored at the root.

---

2. Heap Sort

Heap Sort uses a Max Heap to arrange the elements in ascending order.

Initial Array

45 72 30 90 65 50 85

Max Heap

90 72 85 45 65 50 30

Final Output

30 45 50 65 72 85 90

---

3. Quick Sort

Quick Sort uses a pivot to divide the array into smaller subarrays.

The last element is used as the pivot.

Initial Array

45 72 30 90 65 50 85

First Pivot

85

After First Partition

45 72 30 65 50 85 90

Final Output

30 45 50 65 72 85 90

---

4. Complexity Analysis

Algorithm / Operation| Best Case| Average Case| Worst Case| Space
Max Heap Insertion| O(log n)| O(log n)| O(log n)| O(1)
Get Maximum| O(1)| O(1)| O(1)| O(1)
Delete Maximum| O(log n)| O(log n)| O(log n)| O(1)
Heap Sort| O(n log n)| O(n log n)| O(n log n)| O(1)
Quick Sort| O(n log n)| O(n log n)| O(n²)| O(log n) average

---

5. Heap Structure and Height

The final Max Heap contains 7 nodes.

             90
           /    \
         72      85
        /  \    /  \
      45   65  30   50

The height is:

h = floor(log2(7))
h = 2

Therefore, the height of the heap is 2.

---

6. Comparison of Heap Sort and Quick Sort

Heap Sort

- Uses a heap structure.
- Time complexity is O(n log n) in the best, average and worst cases.
- Requires O(1) auxiliary space in the standard in-place implementation.
- Provides a predictable worst-case time complexity.

Quick Sort

- Uses partitioning and recursion.
- Average-case time complexity is O(n log n).
- Worst-case time complexity is O(n²), depending on pivot selection.
- Average auxiliary space is O(log n) due to recursion.

---

7. Suitable Approach for Continuous Patient Management

For a hospital that continuously inserts patients and needs the highest-priority patient immediately, a Max Heap Priority Queue can be used.

The operations are:

Insert patient        → O(log n)
Get highest priority  → O(1)
Delete highest        → O(log n)

The highest-severity patient is always maintained at the root of the Max Heap. Therefore, the system does not need to sort the complete list whenever a new patient arrives.

---

8. Conclusion

Heap Sort and Quick Sort both successfully sort the given patient severity scores:

30 45 50 65 72 85 90

For continuous patient priority management, the Max Heap provides direct access to the highest-priority patient and supports efficient insertion and deletion operations.

Files

- "hospital_priority_queue.c" – C implementation
- "output.txt" – Program execution output
- "README.md" – Assignment description and analysis
