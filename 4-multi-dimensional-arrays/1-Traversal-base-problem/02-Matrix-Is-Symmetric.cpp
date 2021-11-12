(1)Brute Force
/*

	Time Complexity : O(N^2)
	Space Complexity :  O(N^2)

	Where N is the size of the square matrix.

*/
bool isMatrixSymmetric(vector<vector<int>> matrix){

    // Variable defines the size of the matrix.
    int n = matrix.size();

    // Make transpose of given matrix.
    vector< vector<int> > transpose(n,vector<int>(n,0));

    // Store matrix(i, j) in transpose (j, i). 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            transpose[i][j] = matrix[j][i];
        }
    } 

    // Check both matrix and transpose matrices. 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] != transpose[i][j]){
                return false;
            }
        }
    }

    // Since we have reached here it means the matrix is symmetric.
    return true;
}

(2)Optimised Approach
/*

	Time Complexity : O(N^2)
	Space Complexity :  O(1)

	Where N is the size of the square matrix.

*/

bool isMatrixSymmetric(vector<vector<int>> matrix){

    // Variable defines the size of the matrix.
    int n = matrix.size();

    // Compare matrix(i, j) with matrix (j, i) 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] != matrix[j][i]){
                return false;
            }
        }
    } 
    
    // Since we have reached here it means the matrix is symmetric.  
    return true;
}