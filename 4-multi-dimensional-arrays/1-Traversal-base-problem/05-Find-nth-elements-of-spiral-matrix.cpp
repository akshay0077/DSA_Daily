(1)Spiral order traversal
/*
    Time complexity: O(N * M)
    Space complexity: O(1)

    Where 'N' is number of rows and 'M' is number of columns in matrix. 
*/

int findKthElement(vector<vector<int>> matrix, int k) {
    int startRow = 0;  // Indicate starting index of row
    int startCol = 0;  // Indicate starting index of column
    int count = 0;     // Track the count is 'k' or not

    int n = matrix.size();     // Number of rows
    int m = matrix[0].size();  // Number of columns

    while (startRow < n && startCol < m) {
        
        // Check first row in remianing un-traversed matrix
        for (int i = startCol; i < m; i++) {
            count += 1;

            if (count == k) {
                return matrix[startRow][i];
            }
        }

        // Next time iterate from next row
        startRow += 1;

        // Check last column in remaining columns.
        for (int i = startRow; i < n; i++) {
            count += 1;
            if (count == k) {
                return matrix[i][m - 1];
            }
        }

        // Ending of remaining columns
        m -= 1;

        // Check last row in remaining  rows
        if (startRow < n) {
            for (int i = m - 1; i > startCol - 1; i--) {
                count += 1;
                if (count == k) {
                    return matrix[n - 1][i];
                }
            }
            // Ending of remaining rows
            n -= 1;
        }
        // Check the first column in remaining columns.
        if (startCol < m) {
            for (int i = n - 1; i > startRow - 1; i--) {
                count += 1;
                if (count == k) {
                    return matrix[i][startCol];
                }
            }

            // Next time iterate from next row
            startCol += 1;
        }
    }
}

(2)Level wise traversal
/*
    Time complexity: O(max(N, M))
    Space complexity: O(1)

    Where 'N' is number of rows and 'M' is number of columns in matrix.
*/

int findKthElement(vector<vector<int>> matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int level = 0; level < min(n, m); level++) {

        // If k'th element in first row in remianing un-traversed matrix
        if (k <= m - level) {
            return (matrix[level][k - 1 + level]);
        }

        // If k'th element in last column in remaining columns.
        else if (k <= n + m - 1 - level - level) {
            return (matrix[k - m + level + level][m - 1]);
        }

        // If k'th element in last row in remaining columns.
        else if (k <= m + n - 1 + m - 1 - level - level - level) {
            return (matrix[n - 1][m - (k - n - m + 1 + level + level) - 1]);
        }

        // If k'th element in first column in remaining columns.
        else if (k <= m + n - 1 + m - 1 + n - 2 - level - level - level - level) {
            return (matrix[n - (k - m - n + 1 - m + 1 + level + level + level) - 1][level]);
        }

        // Update k, m, n
        k -= 2 * (n - level) + 2 * (m - level) - 4;
        m -= 1;
        n -= 1;
    }
}