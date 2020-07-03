#include <iostream>
#include <algorithm>
#include <map>

enum state { begin, end };

struct point
{
    point() = default;
    point(int x, int h, state s):x(x), h(h), s(s) {};
    
    int x, h;
    state s;
};

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    point set[200'000];
    {
        for(int i = 0; i < n; ++i)
        {
            int l, h, r;
            std::scanf("%d %d %d", &l, &h, &r);
            
            // 입력을 시작점 끝점으로 나눠서 저장
            set[2 * i] = point(l, h, begin);
            set[2 * i + 1] = point(r, h, end);
        }
        
        // 모든 점들을 좌표 기준으로 정렬
        std::sort(set, set + (n * 2), [](auto& l, auto& r) -> bool
        {
            // 시작점 끝점 좌표가 같으면 시작점을 먼저
            if(l.x == r.x)
                return l.s < r.s;
            else
                return l.x < r.x;
        });
    }
    
    {
        // 점 집합을 순회하면서 활성화상태에 포함되어 있는 것 저장
        // 키는 높이, 값은 개수의 형태. 같은 높이가 여러개 활성화 될 수 있음.
        std::map<int, int, std::greater<int>> contain;
        
        for(int i = 0; i < (n * 2); ++i)
        {
            int x = set[i].x;
            int h = set[i].h;
            
            switch(set[i].s)
            {
                case state::begin:
                {
                    // 기존에 가장 높은 높이
                    int top = (contain.empty())? 0 : contain.begin()->first;
                    
                    // 새로 추가되는 높이가 더 높으면 변화
                    if(top < h)
                        std::printf("%d %d ", x, h);
                    
                    // 활성화 리스트에 추가
                    ++contain[h];
                    
                    break;
                }
                case state::end:
                {
                    // 종료됬기때문에 활성화 리스트에서 빼줌.
                    if(--contain[h] == 0)
                        contain.erase(h);
                    
                    // 새로운 가장 높은 높이
                    int top = (contain.empty())? 0 : contain.begin()->first;
                    
                    // 종료된 높이가 새로운 가장 높은 높이보다 더 크면 변화
                    if(h > top)
                        std::printf("%d %d ", x, top);
                        
                    break;
                }
            }
        }
    }
    
    return 0;
}
