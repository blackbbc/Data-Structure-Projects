#include <iostream>

using namespace std;

struct point
{
    int x;
    int y;
};

int n=7,m=7;
char map[50][50]={"#######",
				  "#0#0000",
				  "#0#0###",
				  "#000#0#",
				  "#0#000#",
				  "#0#0#0#",
				  "#######"};
point dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
point start,goal;

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
	start.x=1;start.y=1;
	goal.x=5;goal.y=5;
}


bool dfs(int x,int y)
{
    if ((x==goal.x)&&(y=goal.y))
    {
    	map[x][y]='x';
        return true;
    }

    for (int i=0;i<4;i++)
        if (map[x+dir[i].x][y+dir[i].y]=='0')
        {
        	map[x][y]='x';
            if (dfs(x+dir[i].x,y+dir[i].y))
                return true;
            map[x][y]='0';
        	
        }


    return false;

}

void printAns()
{
    int x=start.x;
    int y=start.y;

    cout<<"<"<<x<<","<<y<<">";

    while ((x!=goal.x)||(y!=goal.y))
    {
        for (int i=0;i<4;i++)
            if (map[x+dir[i].x][y+dir[i].y]=='x')
            {
            	map[x][y]='0';
                x+=dir[i].x;
                y+=dir[i].y;
                break;
            }

        cout<<" ---> "<<"<"<<x<<","<<y<<">";
    }
}
