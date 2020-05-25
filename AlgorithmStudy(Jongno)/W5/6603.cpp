#include <iostream>

int k;
int input[13];
int list[6];

void solve(int idx, int count)
{
    if((k - idx) >= (6 - count))
    {
        if(count == 6)
        {
            for(int i = 0; i < 6; ++i)
                printf("%d ", list[i]);
            printf("\n");
        }
        else
        {
            list[count] = input[idx];
            
            solve(idx + 1, count + 1);
            solve(idx + 1, count);
        }
    }
}

int main (int argc, const char* argv[])
{
    while(true)
    {
        scanf("%d", &k);
        
        if(k == 0)
            break;
        
        for(int i = 0; i < k; ++i)
            scanf("%d", &input[i]);
        
        solve(0, 0);
        
        printf("\n");
    }
    
    return 0;
}

