#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem: Allocate books to `k` students such that the maximum number of pages allocated to a student is minimized.
- We need to find the minimum possible maximum pages a student has to read, given that we distribute books among `k` students.

Time Complexity: O(n log sum)
- `n` is the number of books, and `sum` is the total number of pages in all books.
- Binary search runs in O(log(sum)), and for each mid value, we check the feasibility of allocation in O(n), leading to O(n log sum).

Space Complexity: O(1)
- Only a constant amount of extra space is used for variables.

Approach:
1. **Binary Search**:
   - We use binary search to find the minimum maximum pages that can be allocated to a student.
   - The range of pages goes from the maximum pages in a single book (start) to the sum of all pages in all books (end).
   
2. **Feasibility Check (`is_possible` function)**:
   - For each mid value, we check if it's possible to allocate books to `k` students such that no student gets more than `mid` pages.
   - We iterate over the array, accumulating the total number of pages assigned to each student.
   - If the total exceeds `mid`, a new student is assigned the next set of pages, and we increment the student count.
   - If the number of students exceeds `k`, the allocation is not possible.
   
3. **Edge Case**:
   - If the number of books is less than the number of students (`n < k`), it's impossible to allocate one book per student, so we return `-1`.
*/

bool is_possible(vector<int> arr, int n, int mid, int k) {
    int total = 0;
    int count = 1; // Start with 1 student
    for (int i = 0; i < n; i++) {
        if (total + arr[i] <= mid) {
            total += arr[i]; // Add pages to the current student
        } else {
            count++; // Assign the next set of pages to a new student
            total = arr[i]; // Start counting pages for the new student
            if(count > k){
                return 0;
            }
        }
    }
    // If the number of students required is less than or equal to `k`, the allocation is possible.
    return count <= k;
}

int main() {
    vector<int> arr = {15, 10, 19, 10, 5, 18, 7}; // List of books with their page numbers
    int n = arr.size(); // Number of books
    int k = 5; // Number of students
    int start = 0, end = 0, mid, ans = -1;

    // Edge Case: If the number of books is less than the number of students
    if (n < k) {
        cout << "Ans: -1"; // Not possible to allocate
        return -1;
    }

    // Initialize start as the maximum pages in a single book (smallest possible max allocation)
    // Initialize end as the total number of pages (largest possible max allocation)
    for (int i = 0; i < n; i++) {
        start = max(start, arr[i]); // The minimum max pages a student can get is at least the largest book
        end += arr[i]; // The maximum would be the sum of all pages
    }

    // Binary search to find the minimum possible maximum pages per student
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate mid to avoid overflow
        bool possible = is_possible(arr, n, mid, k); // Check if allocation with `mid` max pages is possible
        
        if (possible) {
            ans = mid; // If possible, record this value as a potential answer
            end = mid - 1; // Try for a smaller maximum (minimize the max pages)
        } else {
            start = mid + 1; // Increase the minimum max pages
        }
    }

    // Output the minimum possible maximum pages
    cout << ans;

    return 0;
}
