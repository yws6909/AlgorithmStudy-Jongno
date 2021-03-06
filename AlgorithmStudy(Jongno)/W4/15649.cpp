#include <iostream>

int n, m;
bool check[9];
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
        if(check[i] == false)
        {
            set[depth] = i;
            check[i] = true;
            print(depth + 1);
            check[i] = false;
        }
    }
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= 8; ++i)
        check[i] = false;
    
    print(1);
    
    return 0;
}
