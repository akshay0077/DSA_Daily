(1)Brute force
/*
        Time Complexity - O(N ^ 2)
        Space Complexity - O(1)

        Where 'N' is the size of the vector.
*/

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int n = matrix.size();
    
    // Check each row.
    for (int i = 0; i < n; ++i)
    {
        
        // Check each element.
        for (int j = 0; j < n; ++j) 
        {
            if(matrix[i][j] == x) 
            {
                return {i, j};
            }
        }
    }
    
    return {-1, -1};
}

(2)Binary Search

/*
        Time Complexity - O(N * log N)
        Space Complexity - O(1)

        Where 'N' is the size of the vector.
*/

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int n = matrix.size();
    
    for (int i = 0; i < n; ++i)
    {
        int l = 0;
        int r = n - 1;

        // Binary search each row.
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if(matrix[i][mid] == x) 
            {
                return {i, mid};
            }
            if(matrix[i][mid] > x) 
            {
                r = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
        }
    }
    
    return {-1, -1};
}

(3)Optimal Solution
/*
        Time Complexity - O(N)
        Space Complexity - O(1)

        Where 'N' is the size of the vector.
*/


pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int n = matrix.size();
    
    if(n == 0) {
        return {-1, -1};
    }

    int i = 0;
    int j = n - 1;

    while (i < n && j >= 0) 
    {
        if(matrix[i][j] == x) 
        {
            return {i, j};
        }
        // Move to the previous column.
        if(matrix[i][j] > x) 
        {
            j--;
        }
        // Move to the next row.
        else
        {
            i++;
        }
    }
    
    return {-1, -1};
}