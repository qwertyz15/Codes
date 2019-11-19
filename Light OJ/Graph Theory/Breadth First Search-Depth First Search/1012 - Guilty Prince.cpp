#include <bits/stdc++.h>
using namespace std;
using namespace std;

bool color[22][22];
int maze[22][22];
int row,col;
int Total;
int X[] = {0,0,1,-1};
int Y[] = {1,-1,0,0};

void dfs(int x,int y)
{
    color[x][y] = true;
    for(int i = 0;i<4;i++)
    {
        int vx,vy;
        vx = X[i] + x;
        vy = Y[i] + y;

        if(vx >= 0 && vx < row && vy >= 0 && vy < col)
        {
            if(!color[vx][vy] && maze[vx][vy] == '.')
            {
                Total++;
                dfs(vx,vy);
            }
        }
    }


}
int main()
{
    int T;
    scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++)
    {
        cin >> col >> row;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                scanf(" %c",&maze[i][j]);
            }
        }

        memset(color,0,sizeof(color));
         Total = 1;

        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(maze[i][j] == '@')
                {
                   dfs(i,j);
                }
            }
        }
        printf("Case %d: %d\n", tt ,Total);
    }
    return 0;
}
