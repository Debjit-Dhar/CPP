#include <iostream>
#include <ios>
#include <fstream>
#include <string.h>
using namespace std;
class Student_info
{
    long int roll;
    char name[100];
    float score[5];
    public:
    Student_info()
    {
        roll=0;
        strcpy(name,"");
        for(int i=0;i<5;i++)
            score[i]=0;
    }
    Student_info(long int a,char b[],float c[])
    {
        roll=a;
        strcpy(name,b);
        for(int i=0;i<5;i++)
            score[i]=c[i];
    }
    int get_roll()
    {
        return roll;
    }
    int set_roll()
    {
        roll=-1;
    }
    void display()
    {
        cout<<roll<<"\t "<<name<<'\t';
        for(int i=0;i<5;i++)
            cout<<score[i]<<'\t';
        cout<<'\n';
    }
};
class StudentFile
{
    public:
    int search(int r)
    {
        ifstream in("Student Records.dat",ios::binary|ios::in);
        if(!in)
            return -1;
        Student_info dat;
        int i=1;
        while(in.read((char*)&dat,sizeof(dat)))
        {
            if(dat.get_roll()==r)
            {
                in.close();
                return i;
            }
            i++;
        }
        return 0;
    }
    int append(Student_info &dat)
    {
        int ret_value=-1;
        ofstream out("Student Records.dat",ios::binary|ios::app);
        if(!out)
            return -1;
        if(search(dat.get_roll())==0)
        {
            out.write((char*)&dat,sizeof(dat));
            ret_value=1;
        }
        else
            ret_value=0;
        out.close();
        return ret_value;
    }
    int read()
    {
        ifstream in("Student Records.dat",ios::binary|ios::in);
        if(!in)
            return -1;
        Student_info dat;
        cout<<"Roll\tName\tScore1\tScore2\tScore3\tScore4\tScore5\n";
        while(in.read((char*)&dat,sizeof(dat)))
            if(dat.get_roll()!=-1)
                dat.display();
        in.close();
        return 0;
    }
    int logical_delete(int r)
    {
        int ind=search(r);
        if(ind<1)
            return 0;
        ind-=1;
        int c=1;
        fstream f("Student Records.dat",ios::binary|ios::in|ios::out);
        if(!f)
            return -1;
        Student_info dat;
        f.seekp(ind*sizeof(dat),ios::beg);
        f.read((char*)&dat,sizeof(dat));
        dat.set_roll();
        f.seekp(ind*sizeof(dat),ios::beg);
        f.write((char*)&dat,sizeof(dat));
        f.close();
        return 1;
    }
    int physical_delete()
    {
        fstream f("Student Records.dat",ios::binary|ios::in|ios::out);
        fstream f1("Temp.dat",ios::binary|ios::in|ios::out|ios::trunc);
        if(!f)
            return -1;
        Student_info dat;
        int ret_val=0;
        while(f.read((char*)&dat,sizeof(dat)))
        {
            if(dat.get_roll()!=-1)
                f1.write((char*)&dat,sizeof(dat));
            if(dat.get_roll()==-1)
                ret_val=1;
        }
        f.close();
        f.open("Student Records.dat",ios::binary|ios::out|ios::trunc);
        f1.seekg(0,ios::beg);
        while(f1.read((char*)&dat,sizeof(dat)))
            f.write((char*)&dat,sizeof(dat));
        f1.close();
        f.close();
        return ret_val;
    }
};
class Menu 
{
public:
    Menu() 
    {
        int ch;
        StudentFile studentFile;
        while (1){
            cout << "Enter choice: \n";
            cout << "1. Append\n";
            cout << "2. Read\n";
            cout << "3. Search\n";
            cout << "4. Logical Deletion\n";
            cout << "5. Physical Deletion\n";
            cout<<"Any other to exit\n";
            cin >> ch;
            switch (ch)
            {
                case 1:
                 {
                    long int roll;
                    char name[100];
                    float scores[5];

                    cout << "Enter Roll: ";
                    cin >> roll;
                    cout << "Enter Name: ";
                    cin>>name;
                    cout << "Enter Scores (5 scores): ";
                    for (int i = 0; i < 5; i++) {
                        cin >> scores[i];
                    }
                    Student_info student(roll, name, scores);
                    int result = studentFile.append(student);
                    if (result == 1)
                        cout << "Student information appended successfully.\n";
                    else if (result == 0)
                        cout << "Student with the same roll already exists.\n";
                    else
                        cout << "Failed to append student information.\n";
                    break;
                }
                case 2: {
                    int result = studentFile.read();
                    if (result == -1)
                        cout << "Failed to read student information.\n";
                    break;
                }
                case 3: {
                    int roll;
                    cout << "Enter Roll to search: ";
                    cin >> roll;
                    int result = studentFile.search(roll);
                    if (result == 0)
                        cout << "Student not found.\n";
                    else if(result>0)
                        cout << "Student found at record " << result << ".\n";
                    else
                        cout<<"Failed to search.\n";
                    break;
                }
                case 4: 
                {
                    int r;
                    cout<<"Enter roll to be deleted.\n";
                    cin>>r;
                    r=studentFile.logical_delete(r);
                    if(r==-1)
                        cout<<"Failed to delete.\n";
                    else if(r==0)
                        cout<<"Roll does not exist.\n";
                    else
                        cout<<"Record Deleted.\n";
                    
                }
                break;
                case 5:
                {
                    int res=studentFile.physical_delete();
                    if(res==-1)
                        cout<<"Failed to delete.\n";
                    else if(res==0)
                        cout<<"No Roll to be deleted.\n";
                    else
                        cout<<"Required Records Deleted.\n";
                }
                break;
                default: {
                    return;
                }
            }
        }
    }
};
int main()
{
    Menu ob;
    return 0;
}