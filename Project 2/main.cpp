#include <iostream>

using namespace std;

class game;

class person
{
    friend game;
    private:
        int num;
        person *next;
    public:
        person(int pos):num(pos){}
};

class game
{
    private:
        int n;
        int m; 
        int s;
        int k;
        person *head;        


    public:
        void Initial();
        void start();
        void stop();

};


int main()
{
    game liveOrDie;    
    liveOrDie.Initial();
    liveOrDie.start();
    liveOrDie.stop();

}

void game::Initial()
{
    person *p,*tail;

    cout<<"请输入生死游戏的总人数N：";
    cin>>n;
    cout<<endl<<"请输入游戏开始的位置S：";
    cin>>s;
    cout<<endl<<"请输入死亡数字M：";
    cin>>m;
    cout<<endl<<"请输入剩余的生者人数K：";
    cin>>k;
    cout<<endl;

    head=new person(1);
    tail=head;

    for (int i=2;i<=n;i++)
    {
        p=new person(i);
        tail->next=p;
        tail=p;
    }

    tail->next=head;

}

void game::start()
{
  
    int i,j;
    person *p=head;
    s--;
    if (s==0)
        s=n;
    
   while (p->num!=s)
       p=p->next;

    for (i=0;i<n-k;i++)
    {
        for (j=0;j<m;j++)
            p=p->next;
        
        cout<<"第"<<i+1<<"个死者的位置是："<<p->num<<endl;

    }

}

void game::stop()
{
    int i;
    person *p=head;

    for (i=0;i<n;i++)
    {
        head=head->next;
        delete p;
        p=head;
    }

}










