pair<int,int>search(vector<vector<int>> matrix,int x)
{
	int n=matrix.size();

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(matrix[i][j]==x)
				return {i,j};
		}
	}
	return {-1,-1};
}