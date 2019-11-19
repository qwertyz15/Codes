#include <bits/stdc++.h>
using namespace std;

vector <int> v[20100];
bool visited[22][22];
int dis[22][22];
int level[22];

int dirX[] = {0,0,1,-1};
int dirY[] = {1,-1,0,0};
int row,col;
char maze[22][22];
queue < pair<int,int> > q;

void bfs(int i,int j)
{
    q.push(make_pair(i,j));
    dis[i][j] = 0;
    visited[i][j] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int p = 0; p < 4;p++)
        {
            i = x + dirX[p];
            j = y + dirY[p];
            if(!visited[i][j] && i>= 0 && j >= 0 && i < row && j < col && maze[i][j] != 'm' && maze[i][j] != '#')
            {
                if(dis[i][j] == 0)
                {
                    dis[i][j] = dis[x][y] + 1;
                    visited[i][j] = true;
                    q.push(make_pair(i,j));
                   // cout << "(" << i << "," << j <<  ") = " << dis[i][j] << endl;
                }
            }
        }
    }
}

void clean()
{
    while(!q.empty()) q.pop();
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) {
            dis[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int Xa,Xb,Xc,Xh,Ya,Yb,Yc,Yh;

    for(int ii = 1; ii < t; ii++)
    {
        clean();
        cin >> row >> col;

        for(int i = 0;i < row; i++)
        {
            for(int j = 0;j < col; j++)
                cin >> maze[i][j];
        }

         for(int i = 0;i < row; i++)
        {
            for(int j = 0;j < col; j++)
            {
                if(maze[i][j] == 'a')
                {
                    Xa = i;
                    Ya = j;
                }
                else if(maze[i][j] == 'b')
                {
                    Xb = i;
                    Yb = j;
                }
                else if(maze[i][j] == 'c')
                {
                    Xc = i;
                    Yc = j;
                }
                else if(maze[i][j] == 'h')
                {
                    Xh = i;
                    Yh = j;
                }
            }
        }
        bfs(Xh,Yh);
        cout << "Case " << ii << ": " << max(max(dis[Xa][Ya],dis[Xb][Yb]),dis[Xc][Yc]) << endl;
        clean();
    }
    return 0;
}
