#include <iostream>
using namespace std;
 
// Function to print shortest possible path to
// type all characters of given string using a remote
void printPath(string str)
{
    int i = 0;
    // start from charcater 'A' present at position (0, 0)
    int curX = 0, curY = 0;
    while (i < str.length())
    {
        // find cordinates of next character
        int nextX = (str[i] - 'A') / 5;
        int nextY = (str[i] - 'B' + 1) % 5;
 
        // Move Up if destination is above
        while (curX > nextX)
        {
            cout << "Move Up" << endl;
            curX--;
        }
 
        // Move Left if destination is to the left
        while (curY > nextY)
        {
            cout << "Move Left" << endl;
            curY--;
        }
 
        // Move down if destination is below
        while (curX < nextX)
        {
            cout << "Move Down" << endl;
            curX++;
        }
 
        // Move Right if destination is to the right
        while (curY < nextY)
        {
            cout << "Move Right" << endl;
            curY++;
        }
 
        // At this point, destination is reached
        cout << "Press OK" << endl;
        i++;
    }
}
 
// Driver code
int main()
{
    string str = "COZY";
 
    printPath(str);
 
    return 0;
}
