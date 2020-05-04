#include <iostream>

int main(int argc, const char* argv[])
{
    int n;
    scanf("%d", &n);
    
    int set[1'000];
    int opt[1'000];
    
    int r = 0;
    
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", set + i);
        
        opt[i] = 1;
        
        for(int j = 0; j < i; ++j)
        {
            if(set[j] < set[i])
                opt[i] = std::max(opt[i], opt[j] + 1);
        }
        
        r = std::max(r, opt[i]);
    }
    
    printf("%d", r);
    
    return 0;
}
