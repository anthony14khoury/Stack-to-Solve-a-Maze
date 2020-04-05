#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

vector<vector<int>> getInput()
{
    string line;
    getline(cin, line);

    string token;

    int rowNum = 0;
    int colNum = 0;
    int size = 0;
    int currSize = 0;

    int test;


    //get size
    stringstream lineStream(line);
    while (lineStream >> token)
    {
        size++;
    }

    //initialize 2D vector
    vector<vector<int>> numbers(size, vector<int>(size, 0));

    //read lines

    for (int k = 0; k < size - 1; k++)
    {

        stringstream lineStream2(line);
        currSize = 0;
        while (lineStream2 >> token)
        {

            test = stoi(token);
            numbers[rowNum][currSize] = test;
            currSize++;
        }
        rowNum++;
        getline(cin, line);

    }
    //do the last line
    stringstream lineStream2(line);
    currSize = 0;
    while (lineStream2 >> token)
    {

        test = stoi(token);
        numbers[rowNum][currSize] = test;
        currSize++;
    }

    return numbers;
}

void solveMaze(vector<vector<int>> maze, int x, int y)
{
    stack<pair<int, int>> path;
    stack<pair<int, int>> printOut;

    int row = 0;
    int col = 0;

    pair<int, int> nextStep = make_pair(0, 0);
    pair<int, int> exit = make_pair(x, y);

    path.push(make_pair(row, col));
    maze[x][y] = 9;
    maze[row][col] = 2;

    while (maze[row][col] != 9)
    {
        bool rowFarEdge = false;
        bool rowCloseEdge = false;
        bool colFarEdge = false;
        bool colCloseEdge = false;

        if (row == (maze.size() - 1))
        {
            rowFarEdge = true;
        }
        if (row == 0)
        {
            rowCloseEdge = true;
        }
        if (col == (maze.at(0).size() - 1))
        {
            colFarEdge = true;
        }
        if (col == 0)
        {
            colCloseEdge = true;
        }
        if (rowFarEdge == false && maze[row + 1][col] != 0 && maze[row +1][col] != 2)
        {
            if (maze[row + 1][col] == 9)
            {
                row++;
                nextStep = make_pair(row, col);
                path.push(nextStep);
                break;
            }
            else
            {
                maze[row + 1][col] = 2;
                nextStep = make_pair(row + 1, col);
                path.push(nextStep);
                row++;
            }
        }
        else if (colFarEdge == false && maze[row][col + 1] != 0 && maze[row][col+1] != 2)
        {
            if (maze[row][col + 1] == 9)
            {
                col++;
                nextStep = make_pair(row, col);
                path.push(nextStep);
                break;
            }
            else
            {
                maze[row][col + 1] = 2;
                nextStep = make_pair(row, col + 1);
                path.push(nextStep);
                col++;
            }
        }
        else if (rowCloseEdge == false && maze[row - 1][col] != 0 && maze[row -1][col] != 2)
        {
            if (maze[row - 1][col] == 9)
            {
                row--;
                nextStep = make_pair(row, col);
                path.push(nextStep);
                break;
            }
            else
            {
                maze[row - 1][col] = 2;
                nextStep = make_pair(row - 1, col);
                path.push(nextStep);
                row--;
            }
        }
        else if (colCloseEdge == false && maze[row][col - 1] != 0 && maze[row][col - 1] != 2)
        {
            if (maze[row][col - 1] == 9)
            {
                col--;
                nextStep = make_pair(row, col);
                path.push(nextStep);
                break;
            }
            else
            {
                maze[row][col - 1] = 2;
                nextStep = make_pair(row, col - 1);
                path.push(nextStep);
                col--;
            }
        }
        else
        {
            path.pop();
            nextStep = path.top();
            row = nextStep.first;
            col = nextStep.second;

        }
    }

    while (!path.empty())
    {
        printOut.push(path.top());
        path.pop();
    }
    while (!printOut.empty())
    {
        cout << "(" << printOut.top().first << ", " << printOut.top().second << ")";

        printOut.pop();

        if (!printOut.empty())
        {
            cout << " -> ";
        }

    }
}

int main()
{
    vector<vector<int>> maze;
    maze = getInput();
    int x;
    cin >> x;
    int y;
    cin >> y;

    solveMaze(maze, x, y);

    return 0;
}