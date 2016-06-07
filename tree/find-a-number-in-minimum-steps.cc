// C++ program to find a number in minimum steps
#include <bits/stdc++.h>
using namespace std;
#define InF 99999
 
// To represent data of a node in tree
struct number
{
    int no;
    int level;
public:
    number() {}
    number(int n, int l):no(n),level(l) {}
};
 
// Prints level of node n
void findnthnumber(int n)
{
    // Create a queue and insert root
    queue<number> q;
    struct number r(0, 1);
    q.push(r);
 
    // Do level order traversal
    while (!q.empty())
    {
        // Remove a node from queue
        struct number temp = q.front();
        q.pop();
 
        // To avoid infinite loop
        if (temp.no >= InF || temp.no <= -InF)
            break;
 
        // Check if dequeued number is same as n
        if (temp.no == n)
        {
            cout << "Found number n at level "
                 << temp.level-1;
            break;
        }
 
        // Insert children of dequeued node to queue
        q.push(number(temp.no+temp.level, temp.level+1));
        q.push(number(temp.no-temp.level, temp.level+1));
    }
}
 
// Driver code
int main()
{
    findnthnumber(13);
    return 0;
}


