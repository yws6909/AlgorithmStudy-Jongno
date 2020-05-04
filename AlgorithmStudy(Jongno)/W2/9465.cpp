#include <iostream>

int main(int argc, const char* argv[])
{
    int t;
    std::scanf("%d", &t);
    
    int set0[100'000];
    int set1[100'000];
    
    for(int i = 0; i < t; ++i)
    {
        int n;
        std::scanf("%d", &n);
        
        for(int i = 0; i < n; ++i)
            scanf("%d", &set0[i]);
        
        for(int i = 0; i < n; ++i)
            scanf("%d", &set1[i]);
        
        set0[1] += set1[0];
        set1[1] += set0[0];
        
        for(int i = 2; i < n; ++i)
        {
            set0[i] += std::max(set1[i - 1], set1[i - 2]);
            set1[i] += std::max(set0[i - 1], set0[i - 2]);
        }
        
        const int r = std::max(set0[n - 1], set1[n - 1]);
        std::printf("%d\n", r);
    }
    
    return 0;
}

