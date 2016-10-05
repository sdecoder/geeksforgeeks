// C++ implementation of code
#include<bits/stdc++.h>
using namespace std;
 
// Function to calculate maximum value of 
// abs(i - j) * min(arr[i], arr[j]) in arr[]
int Maximum_Product(int arr[], int n)
{
    int maxProduct = INT_MIN; // Initialize result
    int currProduct; // product of current pair
 
    // loop  until they meet with each other
    int Left = 0, right = n-1;
    while (Left < right)
    {
        if (arr[Left] < arr[right])
        {
            currProduct = arr[Left]*(right-Left);
            Left++;
        }
        else // arr[right] is smaller
        {
            currProduct = arr[right]*(right-Left);
            right--;
        }
 
        // maximizing the product
        maxProduct = max(maxProduct, currProduct)
    }
 
    return maxProduct;
}
 
// Driver program to test the case
int main()
{
    int arr[] = {8, 1, 9, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << Maximum_Product(arr,n);
    return 0;
}


