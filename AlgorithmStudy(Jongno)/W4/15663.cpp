#include <iostream>
#include <algorithm>

int n, m;
int input[9];
int check[9];
int set[9];

void print(int depth)
{
    if(depth > m)
    {
        for(int i = 1; i <= m; ++i)
            std::printf("%d ", set[i]);
        
        std::printf("\n");
        
        return;
    }
    
    for(int i = 1; i <= n; ++i)
    {
        if(check[i] != 0)
        {
            set[depth] = input[i];
            --check[i];
            print(depth + 1);
            ++check[i];
        }
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= 8; ++i)
        check[i] = 1;
    
    {
        for(int i = 1; i <= n; ++i)
            std::scanf("%d", input + i);
        
        std::sort(input + 1, input + n + 1);
        
        int before = input[1];
        int duplicate = 0;
        
        for(int i = 2; i <= n; ++i)
        {
            if(before == input[i])
            {
                ++duplicate;
                ++check[i - duplicate];
            }
            else
            {
                input[i - duplicate] = input[i];
                before = input[i];
                check[i - duplicate] = 1;
            }
        }
        
        n -= duplicate;
    }
    
    print(1);
    
    return 0;
}
