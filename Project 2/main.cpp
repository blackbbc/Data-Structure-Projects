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

    cin>>n;
    cin>>s;
    cin>>m;
    cin>>k;

    head=new person(n);
    tail=head;

    for (int i=n-1;i>0;i--)
    {
        p=new person(i);
        p->next=head;
        head=p;
    }

    tail->next=head;

}

void game::start()
{
    



}
