#include <iostream>
#include <ctime>
#include <vector>       // `vector' container is situated here
#include <algorithm>    // `swap' function is here

using namespace std;    // To avoid boring std::

// We need reference for `Array' -- not a pointer
// We don't need references for `first' and `last'
// Let's do swap_counts as optional pointer
// Also it's a quick_sort function
void quick_sort(vector<double> &Array, int first, int last,
                                                 int *swap_counts = NULL)
{
    if (first < 0 || last < 0)
        return;

    int i = first, j = last;
    double x = Array[(first + last) / 2];
    do
    {
        while (Array[i]<x) i++;
        while (Array[j]>x) j--;

        if (i <= j)
        {
            if (Array[i]>Array[j])
            {
                // It's better to use standard procedure
                swap(Array[i], Array[j]);
                if (swap_counts)
                {
                    (*swap_counts)++;
                }
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i<last)
        quick_sort(Array, i, last);
    if (first<j)
        quick_sort(Array, first, j);
}

int main()
{
    srand((unsigned int)time(0));

    int n;
    vector<double> arr;
    cout << "Enter n: ";
    cin >> n;

    // We should avoid incorrect input affection:
    // i%0 is an error and we can't have less than 0 elemens in array
    if (n < 1)
    {
        cerr << "Incorrect input" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= n; i++) // Indexing from 0 -- not from n
    {
        arr.push_back((double) i / (rand() % n)); // We have to use `push_back'
        cout << arr[i] << " ";
    }

    cout << endl;
    int swap_counts = 0;
    quick_sort(arr, 0, n, &swap_counts); // Swaps counter is not global now

    for (int i = 0; i <= n; ++i) // We have n+1 element
        cout << arr[i] << " ";

    cout << endl << "Swaps: " << swap_counts << endl; //It's prettier with EOL
    exit(EXIT_SUCCESS);
}
