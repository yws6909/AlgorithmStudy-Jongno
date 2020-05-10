#include <iostream>
#include <algorithm>

int n, m;
int input[9];
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
        set[depth] = input[i];
        print(depth + 1);
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; ++i)
        std::scanf("%d", input + i);
    
    std::sort(input + 1, input + 1 + n);
    
    print(1);
    
    return 0;
}
