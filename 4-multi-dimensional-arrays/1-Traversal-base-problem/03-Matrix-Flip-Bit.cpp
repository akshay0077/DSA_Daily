(1)Brute Force Approach
/*
	Time Complexity: O(N ^ 3)
	Space Complexity: O(1)

	Where 'N' is the number of rows and columns in matrix 'MAT'.
*/

int countFlip(vector<vector<int>> &mat)
{
	int n = mat.size();

	// Mark the flipped bits as -1 and increment count.
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0)
			{
				// Use 'k' as a variable to iterate through row and column.
				for (int k = 0; k < n; k++)
				{
					// Check every column.
					if (mat[i][k] == 1)
					{
						count++;
						mat[i][k] = -1;
					}
					// Check every row.
					if (mat[k][j] == 1)
					{
						count++;
						mat[k][j] = -1;
					}
				}
			}
		}
	}

	return count;
}

(2)Optimised Approach
/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)

    Where 'N' is the number of rows and columns in matrix 'MAT'.
*/

int countFlip(vector<vector<int>> &mat)
{
    int n = mat.size();

    // Initialise both visited row and col as 0.
    vector<bool> visitedRow(n, false), visitedCol(n, false);

    int count = 0;
    vector<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                s.push_back(make_pair(i, j));
            }
        }
    }

    for (auto element : s) {
        // Fixing column.
        if (visitedCol[element.second] == false)
        {
            for (int k = 0; k < n; k++)
            {
                if (mat[k][element.second] == 1)
                {
                    count++;
                    mat[k][element.second] = -1;
                }

                if (k == n - 1) {
                    visitedCol[element.second] = true;
                }
            }
        }
        // Fixing row.
        if (visitedRow[element.first] == 0)
        {
            for (int k = 0; k < n; k++)
            {
                if (mat[element.first][k] == 1)
                {
                    count++;
                    mat[element.first][k] = -1;
                }

                if (k == n - 1) {
                    visitedRow[element.first] = true;
                }
            }
        }
    }

    return count;
}

(3)Deriving a formula
/*
	Time Complexity : O(N ^ 2)
	Space Complexity : O(1)

	Where 'N' is the number of rows and columns in matrix 'MAT'.
*/

int countFlip(vector<vector<int>> &mat)
{
	int n = mat.size(), row = 0, col = 0, zeros = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0)
			{
				zeros++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0)
			{
				row++;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[j][i] == 0)
			{
				col++;
				break;
			}
		}
	}

	int res = (n * row) + ((n - row) * col) - zeros;

	return res;
}