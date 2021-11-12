https://www.geeksforgeeks.org/count-occurrences-of-anagrams/

(1)Brute Force
/*

*/


(2)sliding Window

/*
	Time:O(N)
	space:O(1)

*/
class Solution
{
  public:
	int search(string pat, string txt) 
	{
	  unordered_map <char, int=""> m;

	  for(auto start: pat)
	  	m[start]++;

	  int k = pat.size();
	  int count = m.size();
	  int ans = 0;
	  int start = 0, end = 0;

	  while(end < txt.size()) 
	  {

		  	if(m.find(txt[end]) != m.end()) 
		  	{
		  	  m[txt[end]]--;

			  if(m[txt[end]] == 0)
			  	count--;
		  	}

		  if(end - start + 1 < k) 
		  	end++;

		  	else if(end - start + 1 == k) 
		  	{
			  if(count == 0)
		      ans++;

			  if(m.find(txt[start]) != m.end()) 
			  {
			  	  m[txt[start]]++;

				  if(m[txt[start]] == 1)
				  	count++;
			  }

		  	  start++;
		  	  end++;
	   		}
	  	}

	  return ans;
	}
};