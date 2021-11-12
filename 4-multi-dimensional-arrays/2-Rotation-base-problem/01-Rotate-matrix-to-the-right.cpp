O(N*M)
O(1)

vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k) {
	
    vector<int> rotated; 
    int r = k%m;
    for(int i = 0; i < n; i++){
        int first = m-r;
        while(first<m){
            rotated.push_back(mat[i][first]);
            first++;
        }
        for(int j = 0; j<m-r; j++)
            rotated.push_back(mat[i][j]);
    }
    return rotated;
}