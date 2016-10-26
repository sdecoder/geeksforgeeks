// C++ program to find K'th Boom number
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
// This function uses queue data structure to K'th
// Boom number
void  boomNumber(ll k)
{
    // Create an empty queue of strings
    queue<string> q;
 
    // Enqueue an empty string
    q.push("");
 
    // counter for K'th element
    ll count = 0;
 
    // This loop checks the value of count to
    // become equal to K when value of count
    // will be equals to k we will print the
    // Boom number
    while (count <= k)
    {
        // current Boom number
        string s1 = q.front();
 
        // pop front
        q.pop();
 
        // Store current Boom number before changing it
        string s2 = s1;
 
        // Append "2" to string s1 and enqueue it
        q.push(s1.append("2"));
        count++;
 
        // check if count==k
        if (count==k)
        {
            cout << s1 << endl; // K'th Boom number
            break;
        }
 
        // Append "3" to string s2 and enqueue it.
        // Note that s2 contains the previous front
        q.push(s2.append("3"));
        count++;
 
        // check if count==k
        if (count==k)
        {
            cout << s2 << endl; // K'th Boom number
            break;
        }
    }
    return ;
}
 
// Driver program to test above function
int main()
{
    ll k = 1000000;
    boomNumber(k);
    return 0;
}


