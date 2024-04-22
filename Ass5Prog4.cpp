#include <iostream>
#include <string>
using namespace std;
class Cricketer
{
    string name;
    string dob;
    protected:
    int nom;//number of matches played
    public:
    Cricketer()
    {
        name="";
        dob="";
        nom=0;
    }
    Cricketer(string a,string b,int c)
    {
        name=a; 
        dob=b;
        nom=c;
    }
    void display()
    {
        cout<<"Name= "<<name<<'\n';
        cout<<"DOB= "<<dob<<'\n';
        cout<<"Number of matches played= "<<nom<<'\n';
    }
};
class Bowler:virtual public Cricketer
{
    int now;//number of wickets tacken
    float av_ec;//average economy
    public:
    Bowler(string a,string b,int c,int d,float e):Cricketer(a,b,c)
    {
        now=d;
        av_ec=e;
    }
    void display()
    {
        Cricketer::display();
    }
    void display_specific()
    {
        cout<<"Number of wickets taken= "<<now<<'\n';
        cout<<"Average Economy= "<<av_ec<<'\n';
    }
};
class Batsman:virtual public Cricketer
{
    int tot_run;//total runs scored
    float av_score;//average score
    public:
    Batsman(string a,string b,int c,int d):Cricketer(a,b,c)
    {
        tot_run=d;
        av_score=(tot_run*1.0)/Cricketer::nom;
    }
    void display()
    {
        Cricketer::display();
    }
    void display_specific()
    {
        cout<<"Total Runs= "<<tot_run<<'\n';
        cout<<"Average Score= "<<av_score<<'\n';
    }
};
class Double_Wicket_Pair
{
    Batsman batter;
    Bowler  bowler;
    public:
    Double_Wicket_Pair(string a1,string b1,int c1,int d1,string a,string b,int c,int d,float e):batter(Batsman(a1,b1,c1,d1)),bowler(Bowler(a,b,c,d,e))
    {
        //batter=Batsman(a1,b1,c1,d1);
        //bowler=Bowler(a,b,c,d,e);
    }
    void display()
    {
        bowler.display();
        bowler.display_specific();
        batter.display();
        batter.display_specific();
    }
};
class AllRounder:public Bowler,public Batsman
{
    public:
    AllRounder(string a,string b,int c,int d,int e,float f):Cricketer(a,b,c),Batsman(a,b,c,d),Bowler(a,b,c,e,f)
    {
    }
};
class Cricket_Team
{
    public:
    Cricket_Team()
    {
       while(1)
       {
            int ch;
            cout<<"Enter choice\n1. to create a bowler\n2. to create a batsman\n3. to create a all rounder\n4. to create a double wicket pair.\n";
            cin>>ch;
            switch(ch)
            {
                case 1:
                {
                    string a,b;int c,d;float e;
                    cout<<"Enter bowler name.\n";
                    cin>>a;
                    cout<<"Enter bowler dob.\n";
                    cin>>b;
                    cout<<"Enter bowler number played matches.\n";
                    cin>>c;
                    cout<<"Enter number of wickets taken.\n";
                    cin>>d;
                    cout<<"Enter bowler average economy.\n";
                    cin>>e;
                    Bowler bowl(a,b,c,d,e);
                    bowl.display();
                    bowl.display_specific();
                    break;
                }
case 2:
{
string a,b;int c,d;float e;
cout<<"Enter batsman name.\n";
cin>>a;
cout<<"Enter batsman dob.\n";
cin>>b;
cout<<"Enter batsman number played matches.\n";
cin>>c;
cout<<"Enter batsman of total runs taken.\n";
cin>>d;
Batsman bat(a,b,c,d);
bat.display();
bat.display_specific();
break;
}
case 3:
{
string a,b;int c,d,f;float e;
cout<<"Enter all rounder name.\n";
cin>>a;
cout<<"Enter all rounder dob.\n";
cin>>b;
cout<<"Enter all rounder number played matches.\n";
cin>>c;
cout<<"Enter all rounder number of wickets taken.\n";
cin>>d;
cout<<"Enter all rounder average economy.\n";
cin>>e;
cout<<"Enter batsman of total runs taken.\n";
cin>>f;
AllRounder ar(a,b,c,d,e,f);
ar.Bowler::display();
ar.Bowler::display_specific();
ar.Batsman::display_specific();
break;
}
case 4:
{
string a,b;int c,d;float e;
cout<<"Enter bowler name.\n";
cin>>a;
cout<<"Enter bowler dob.\n";
cin>>b;
cout<<"Enter bowler number played matches.\n";
cin>>c;
cout<<"Enter number of wickets taken.\n";
cin>>d;
cout<<"Enter bowler average economy.\n";
cin>>e;
string a1,b1;int c1,d1;
cout<<"Enter batsman name.\n";
cin>>a1;
cout<<"Enter batsman dob.\n";
cin>>b1;
cout<<"Enter batsman number played matches.\n";
cin>>c1;
cout<<"Enter batsman of total runs taken.\n";
cin>>d1;
Double_Wicket_Pair dwp(a1,b1,c1,d1,a,b,c,d,e);
dwp.display();
}
break;
default:
cout<<"Exiting\n";
return;
}
}
}
};
int main()
{
    Cricket_Team ob;
    return 0;
}