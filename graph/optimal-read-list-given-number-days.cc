// C++ DFS solution to schedule chapters for reading in
// given days
# include <iostream>
# include <cstdlib>
# include <climits>
# include <cmath>
using namespace std;
 
// Define total chapters in the book
// Number of days user can spend on reading
# define CHAPTERS 4
# define DAYS 3
# define NOLINK -1
 
// Array to store the final balanced schedule
int optimal_path[DAYS+1];
 
// Graph - Node chapter+1 is the sink described in the
//         above graph
int DAG[CHAPTERS+1][CHAPTERS+1];
 
// Updates the optimal assignment with current assignment
void updateAssignment(int* path, int path_len);
 
// A DFS based recursive function to store the optimal path
// in path[] of size path_len.  The variable sum stores sum of
// of all edges on current path.  k is number of days spent so
// far.
void assignChapters(int u, int* path, int path_len, int sum, int k)
{
    static int min = INT_MAX;
 
    // Ignore the assignment which requires more than required days
    if (k < 0)
        return;
 
    // Current assignment of chapters to days
    path[path_len] = u;
    path_len++;
 
    // Update the optimal assignment if necessary
    if (k == 0 && u == CHAPTERS)
    {
        if (sum < min)
        {
            updateAssignment(path, path_len);
            min = sum;
        }
    }
 
    // DFS - Depth First Search for sink
    for (int v = u+1; v <= CHAPTERS; v++)
    {
        sum += DAG[u][v];
        assignChapters(v, path, path_len, sum, k-1);
        sum -= DAG[u][v];
    }
}
 
// This function finds and prints optimal read list.  It first creates a
// graph, then calls assignChapters().
void minAssignment(int pages[])
{
    // 1) ............CONSTRUCT GRAPH.................
    // Partial sum array construction S[i] = total pages
    // till ith chapter
    int avg_pages = 0, sum = 0, S[CHAPTERS+1], path[DAYS+1];
    S[0] = 0;
 
    for (int i = 0; i < CHAPTERS; i++)
    {
        sum += pages[i];
        S[i+1] = sum;
    }
 
    // Average pages to be read in a day
    avg_pages = round(sum/DAYS);
 
    /* DAG construction vertices being chapter name &
     * Edge weight being |avg_pages - pages in a chapter|
     * Adjacency matrix representation  */
    for (int i = 0; i <= CHAPTERS; i++)
    {
        for (int j = 0; j <= CHAPTERS; j++)
        {
            if (j <= i)
                DAG[i][j] = NOLINK;
            else
            {
                sum = abs(avg_pages - (S[j] - S[i]));
                DAG[i][j] = sum;
            }
        }
    }
 
    // 2) ............FIND OPTIMAL PATH................
    assignChapters(0, path, 0, 0, DAYS);
 
    // 3) ..PRINT OPTIMAL READ LIST USING OPTIMAL PATH....
    cout << "Optimal Chapter Assignment :" << endl;
    int ch;
    for (int i = 0; i < DAYS; i++)
    {
        ch = optimal_path[i];
        cout << "Day" << i+1 << ": " << ch << " ";
        ch++;
        while ( (i < DAYS-1 && ch < optimal_path[i+1]) ||
                (i == DAYS-1 && ch <= CHAPTERS))
        {
           cout <<  ch << " ";
           ch++;
        }
        cout << endl;
    }
}
 
// This funtion updates optimal_path[]
void updateAssignment(int* path, int path_len)
{
    for (int i = 0; i < path_len; i++)
        optimal_path[i] = path[i] + 1;
}
 
// Driver program to test the schedule
int main(void)
{
    int pages[CHAPTERS] = {7, 5, 6, 12};
 
    // Get read list for given days
    minAssignment(pages);
 
    return 0;
}


