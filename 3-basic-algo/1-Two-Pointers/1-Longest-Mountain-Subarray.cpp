/*
    Time Complexity: O(N * N * N)
    Space Complexity: O(1)

    where 'N' is the size of the given array.
*/

int longestMountain(int *arr, int n)
{
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 2; j < n; ++j)
        {
            bool f = 1, isMountain = 1;

            for (int k = i; k < j; ++k)
            {
                if(arr[k] < arr[k+1])
                {
                    if(!f)
                    {
                        isMountain = 0;
                        break;
                    }
                }
                else if(arr[k] > arr[k+1])
                {
                    if(k == i && f)
                    {
                        isMountain = 0;
                        break;
                    }
                    f = 0;
                }
                else
                {
                    isMountain = 0;
                    break;
                }
            }

            if(isMountain && f == 0)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }

    return ans;
}


(2)

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the size of the given array.
*/

int longestMountain(int *arr, int n)
{
    if(n < 3)
    {
        return 0;
    }

    int start = -1, end = -1;
    int ans = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if(arr[i+1] > arr[i])
        {
            if(end != -1) {
                end = -1;
                start = -1;
            }

            if(start == -1) {
                start = i;
            }
        }
        else
        {
            if(arr[i+1] < arr[i])
            {
                if(start != -1) {
                    end = i + 1;
                }

                if(end != -1 && start != -1) {
                    ans = max(ans, end - start + 1);
                }
            }
            else
            {
                start = -1;
                end = -1;
            }
        }
    }

    if(end != -1 && start != -1)
    {
        ans = max(ans, end - start + 1);
    }

    return ans;
}