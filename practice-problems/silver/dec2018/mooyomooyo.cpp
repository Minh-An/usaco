#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void removeHaybales(vector<vector<int>>& grid, int r, int c, int k)
{
    int height = grid.size();
    int width = grid[0].size();

    int color = grid[r][c];
    stack<int> haybales;
    unordered_set<int> visited;
    haybales.emplace(r*width+c);
    while(!haybales.empty())
    {
        r = haybales.top()/width;
        c = haybales.top()%width;
        visited.emplace(haybales.top());
        haybales.pop();

        if ( c < width-1 &&  grid[r][c+1] == grid[r][c] &&
            visited.find(r*width+c+1) == visited.end()) haybales.emplace(r*width+c+1); //right
        if ( c > 0 &&  grid[r][c-1] == grid[r][c] &&
            visited.find(r*width+c-1) == visited.end()) haybales.emplace(r*width+c-1); //left
        if (r < height-1 &&  grid[r+1][c] == grid[r][c] &&
            visited.find((r+1)*width+c) == visited.end()) haybales.emplace((r+1)*width+c); //down
        if (r > 0 &&  grid[r-1][c] == grid[r][c] &&
            visited.find((r-1)*width+c) == visited.end()) haybales.emplace((r-1)*width+c); //up
    }

    if(visited.size() < k) return; 
    for(int index: visited)
    {
        grid[index/width][index%width] = 0;
    }

    for(int j = 0; j < width; j++)
    {
        for(int i = height-2; i >= 0; i--)
        {
            if(grid[i][j] == 0) continue;
            int k = i;
            while(++k < height && grid[k][j] == 0)
            {
                grid[k][j] = grid[k-1][j];
                grid[k-1][j] = 0;
            }
        }
    }

}

int main(int argc, char const *argv[])
{
    //ifstream ifs(argv[1], ifstream::in);
    ifstream ifs("mooyomooyo.in", ifstream::in);
    ofstream ofs("mooyomooyo.out", ofstream::out);

    int width = 10;

    int height, k;

    ifs >> height >> k;
    

    vector<vector<int>> grid(height, vector<int>(width, 0));

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            char c;
            ifs >> c;            
            grid[i][j] = c - '0';
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    for(int i = height-1; i >= 0; i--)
    {
        for(int j = 0; j < width; j++)
        {
            if(grid[i][j] != 0)
            {
                removeHaybales(grid, i, j, k);
            }
        }
    }

    cout << "?" << endl;
    

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            ofs << grid[i][j];
        }
        ofs << endl;
    }
}

