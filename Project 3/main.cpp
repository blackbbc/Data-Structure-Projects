#include <iostream>

using namespace std;

struct point
{
    int x;
    int y;
};

int n,m;
char map[50][50];
point dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
point start,goal;
bool flag=false;

void getmap();
bool dfs(int,int);
void printAns();

int main()
{
    
    getmap();
    
    if (dfs(start.x,start.y))
        printAns();
    else
        cout<<"No Answer!";
    
    return 0;
}

void getmap()
{
    char temp;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            cin>>temp;
            cin>>map[i][j];
        }

}


bool dfs(int x,int y)
{
    if ((x==goal.x)&&(y=goal.y))
    {
        flag=true;
        return true;
    }

    for (int i=0;i<4;i++)
        if (map[x+dir[i].x][y+dir[i].y]=='0')
            if (dfs(x+dir[i].x,y+dir[i].y))
            {
                map[x][y]='x';
                return true;
            }

    return false;

}

void printAns()
{
    int x=start.x;
    int y=start.y;

    cout<<"<"<<x<<","<<y<<"> ---> ";

    while ((x!=goal.x)&&(y!=goal.y))
    {
        for (int i=0;i<4;i++)
            if (map[x+dir[i].x][y+dir[i].y]=='x')
            {
                x+=dir[i].x;
                y+=dir[i].y;
                break;
            }

        cout<<"<"<<x<<","<<y<<"> ---> ";
    }
}
