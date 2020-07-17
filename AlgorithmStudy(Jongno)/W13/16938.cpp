#include <iostream>
#include <algorithm>

int n, l, r, x;
int set[17];

int combination(int begin, int end, int min, int max)
{
    if(begin == end + 1)
    {
        return min <= 0 && max >= 0;
    }
    
    int ret = 0;
    {
        int next = begin + 1;
        ret += combination(next, end, min - set[begin], max - set[begin]);
        ret += combination(next, end, min, max);
    }
    return ret;
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d %d %d", &n, &l, &r, &x);
    
    for(int i = 0; i < n; ++i)
        std::scanf("%d", set + i);
    
    std::sort(set, set + n, [](auto l, auto r) { return l < r; });
    
    int ret = 0;
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = n - 1; j > i; --j)
            {
                if(set[j] - set[i] >= x)
                {
                    int sum = set[j] + set[i];
                    
                    ret += combination(i + 1, j - 1, l - sum, r - sum);
                }
                else
                {
                    break;
                }
            }
        }
    }
    std::printf("%d", ret);
    
    return 0;
}

