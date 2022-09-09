#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector <int> >& matrix) {
        vector<int> res;
        int start = 0;
        int rows = matrix.size();
        if(rows == 0)
            return res;
        int columns = matrix[0].size();
        while(columns > start*2 && rows > start*2)
        {
            PrintMatrixInCircle(matrix, rows, columns, start, res);
            ++start;
        }
        return res;
    }

    void PrintMatrixInCircle(vector<vector <int> >& matrix, int rows, int columns, int start, vector<int>& res) {
        int endX = rows - 1 - start;
        int endY = columns - 1 - start;
        for(int i = start; i <= endY; ++i)
        {
            res.push_back(matrix[start][i]);
        }
        if(start < endX)
        {
            for(int i = start + 1; i <= endX; ++i)
            {
                res.push_back(matrix[i][endY]);
            }
        }
        if(start < endY && start < endX)
        {
            for(int i = endY - 1; i >= start; --i)
            {
                res.push_back(matrix[endX][i]);
            }
        }
        if(start < endY && start < endX - 1)
        {
            for(int i = endX - 1; i >= start + 1; --i)
            {
                res.push_back(matrix[i][start]);
            }
        }
    }
};

int main()
{
    return 0;
}