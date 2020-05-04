#include <iostream>

int main(int argc, const char* argv[])
{
    const int div = 1'000'000'009;
    
    int t;
    std::scanf("%d", &t);
    
    int set[100'000 + 1][4];
    {
        set[1][1] = 1;
        set[1][2] = set[1][3] = 0;
        set[2][2] = 1;
        set[2][1] = set[2][3] = 0;
        set[3][1] = set[3][2] = set[3][3] = 1;
        
        for(int i = 4; i <= 100'000; ++i)
        {
            set[i][1] = set[i - 1][2] + set[i - 1][3];
            
            if(set[i][1] >= div)
                set[i][1] -= div;
            
            set[i][2] = set[i - 2][1] + set[i - 2][3];
            
            if(set[i][2] >= div)
                set[i][2] -= div;
            
            set[i][3] = set[i - 3][1] + set[i - 3][2];
            
            if(set[i][3] >= div)
                set[i][3] -= div;
        }
    }
    
    for(int i = 0; i < t; ++i)
    {
        int n;
        std::scanf("%d", &n);
        
        int r;
        {
            r = set[n][1] + set[n][2];
            
            if(r >= div)
                r -= div;
            
            r += set[n][3];
            
            if(r >= div)
                r -= div;
        }
        printf("%d\n", r);
    }
    
    return 0;
}
