#include <iostream>
#include <queue>
#include <map>       // Need map to track counts
#include <vector>    // Need vector for min-heap implementation
#include <functional> // Need functional for std::greater

using namespace std;

int main()
{
    // These lines speed up C++ I/O operations
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t; 
    cin >> t;
    for (int i = 0 ; i < t; i++)
    {
        int k; 
        cin >> k;

        // --- Data Structures ---
        // max-heap (default)
        priority_queue<int> pq_max; 
        // min-heap
        priority_queue<int, vector<int>, greater<int>> pq_min; 
        // Map to store the "true" count of each element
        map<int, int> counts;
        // Total number of valid elements currently in the structure
        int valid_elements = 0;

        for (int j = 0; j < k; j++)
        {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I')
            {
                // Insert into both queues and update map
                pq_max.push(n);
                pq_min.push(n);
                counts[n]++;
                valid_elements++;
            }
            else if (c == 'D')
            {
                // If the structure is empty, do nothing
                if (valid_elements == 0)
                {
                    continue;
                }

                if (n == 1) // Delete Max
                {
                    // Loop until we find a valid (non-zombie) max element
                    while (!pq_max.empty()) 
                    {
                        int max_val = pq_max.top();
                        pq_max.pop();

                        // Check if this element is "real" (count > 0)
                        if (counts[max_val] > 0)
                        {
                            counts[max_val]--; // Decrement its "true" count
                            valid_elements--;
                            break; // Found and removed the valid max
                        }
                        // If counts[max_val] == 0, it's a "zombie" element
                        // (already removed by a 'D -1'), so we loop again.
                    }
                }
                else if (n == -1) // Delete Min
                {
                    // Loop until we find a valid (non-zombie) min element
                    while (!pq_min.empty())
                    {
                        int min_val = pq_min.top();
                        pq_min.pop();

                        // Check if this element is "real"
                        if (counts[min_val] > 0)
                        {
                            counts[min_val]--; // Decrement its "true" count
                            valid_elements--;
                            break; // Found and removed the valid min
                        }
                        // If counts[min_val] == 0, it's a "zombie"
                        // (already removed by a 'D 1'), so we loop again.
                    }
                }
            }
        } // End of operations loop

        // --- Print Final Result ---
        if (valid_elements == 0)
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            int res_max, res_min;

            // "Clean" the tops of the queues from any remaining zombie elements
            while (!pq_max.empty() && counts[pq_max.top()] == 0)
            {
                pq_max.pop();
            }
            res_max = pq_max.top();

            while (!pq_min.empty() && counts[pq_min.top()] == 0)
            {
                pq_min.pop();
            }
            res_min = pq_min.top();

            cout << res_max << ' ' << res_min << '\n';
        }
    } // End of test case loop
    
    return 0;
}