#include <iostream>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int opt_inc[1000];
    int opt_dec[1000];
    {
        int set[1000];
        {
            for(int i = 0; i < n; ++i)
                std::scanf("%d", set + i);
        }
        
        for(int i = 0; i < n; ++i)
        {
            opt_inc[i] = 1;
            
            for(int j = 0; j < i; ++j)
            {
                if(set[i] > set[j])
                    opt_inc[i] = std::max(opt_inc[i], opt_inc[j] + 1);
                
            }
        }
        
        for(int i = n - 1; i >= 0; --i)
        {
            opt_dec[i] = 1;
            
            for(int j = n - 1; j > i; --j)
            {
                if(set[i] > set[j])
                    opt_dec[i] = std::max(opt_dec[i], opt_dec[j] + 1);
            }
        }
    }
    
    int r;
    {
        r = 1;
        
        for(int i = 0; i < n; ++i)
            r = std::max(r, opt_inc[i] + opt_dec[i] - 1);
    }
    std::printf("%d", r);
    
    return 0;
}
