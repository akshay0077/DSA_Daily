(1)Cycle rotation
/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    where ‘N’ is the side length of the given square matrix.
*/

void inplaceRotate(vector<vector<int>> &inputArray)
{
	int n = inputArray.size();
	for (int x = 0; x < n / 2; x++)
	{
		for (int y = x; y < n - x - 1; y++)
		{
			int temp = inputArray[x][y];
			inputArray[x][y] = inputArray[y][n - 1 - x];
			inputArray[y][n - 1 - x] = inputArray[n - 1 - x][n - 1 - y];
			inputArray[n - 1 - x][n - 1 - y] = inputArray[n - 1 - y][x];
			inputArray[n - 1 - y][x] = temp;
		}
	}
}

(2)Transpose and reverse
/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    where ‘N’ is the side length of the given square matrix.
*/

void transpose(vector<vector<int>> &inputArray)
{
    for (int i = 0; i < inputArray[0].size(); i++)
    {
        for (int j = i; j < inputArray[0].size(); j++)
        {
            swap(inputArray[j][i], inputArray[i][j]);
        }
    }
}

void reverseColumns(vector<vector<int>> &inputArray)
{
    for (int i = 0; i < inputArray[0].size(); i++)
    {
        for (int j = 0, k = inputArray[0].size() - 1; j < k; j++, k--)
        {
            swap(inputArray[j][i], inputArray[k][i]);
        }
    }
}

void inplaceRotate(vector<vector<int>> &inputArray)
{
    transpose(inputArray);
    reverseColumns(inputArray);
}