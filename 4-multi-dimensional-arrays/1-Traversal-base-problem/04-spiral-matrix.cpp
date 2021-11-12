(1)Spiral Path - Recursively

/*
    Time Complexity : O(N * M)
    Space Complexity : O(max(N, M))

    Where N is the number of rows in the matrix,
    and M is the number of columns in the matrix.
*/

void spiralPathHelper(vector< vector<int> > matrix,int r, int c, int rows, int cols, vector<int> &ans)
{
    // If outside the matrix.
    if (r >= rows || c >= cols)
    {
        return;
    }

    // Push First Row.
    for (int p = r; p < cols; p++)
    {
        ans.push_back(matrix[r][p]);
    }
 
    // Push Last Column.
    for (int p = r + 1; p < rows; p++)
    {
        ans.push_back(matrix[p][cols - 1]);
    }
 
    // Push Last Row,if Last and First Row are not same.
    if ((rows - 1) != r)
    {
        for (int p = cols - 2; p >= c; p--)
        {
            ans.push_back(matrix[rows - 1][p]);
        }
    }
 
    // Print First Column,if Last and First Column are not same.
    if ((cols - 1) != c)
    {
        for (int p = rows - 2; p > r; p--)
        {
            ans.push_back(matrix[p][c]);
        }
    }

    // Make recursive call on smaller submatrix.
    spiralPathHelper(matrix, r + 1, c + 1, rows - 1, cols - 1 ,ans);
}

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m)
{
    int r = 0;
    int c = 0;

    vector<int> ans;

    // Take help of helper function to pass recursive calls.
    spiralPathHelper(matrix, r, c, n, m, ans);

    return ans;    
}

(2)Spiral Path - Iteratively
/*
    Time Complexity : O(N * M)
    Space Complexity : O(1)

    Where N is the number of rows in the matrix,
    and M is the number of columns in the matrix.
*/

vector<int> spiralPathMatrix(vector<vector<int> > matrix, int n, int m)
{
     int i;
     int r = 0;
     int rows = n;
     int c = 0;
     int cols = m;
 
    /*  
        r - starting row index,
        rows - ending row index,
        c - starting column index,
        cols - ending column index,
        i - iterator.
    */
 
    // Make vector to store the path.
    vector<int> path;

    while (r < rows && c < cols) 
    {
        // Push the first row from the remaining rows .
        for (i = c; i < cols; ++i) 
        {
            path.push_back(matrix[r][i]);
        }
        r = r + 1;
 
        // Push the last column from the remaining columns.
        for (i = r; i < rows; ++i) 
        {
            path.push_back(matrix[i][cols - 1]);
        }
        cols = cols - 1;
 
        // Push the last row from the remaining rows. 
        if (r < rows)
        {
            for (i = cols - 1; i >= c; --i) 
            {
                path.push_back(matrix[rows - 1][i]);
            }
            rows = rows - 1;
        }
 
        // Push the first column from the remaining columns. 
        if (c < cols) 
        {
            for (i = rows - 1; i >= r; --i) 
            {
                path.push_back(matrix[i][c]);
            }
            c = c + 1;
        }
    }

    return path;
}