#include<bits/stdc++.h>
#define size 1000
using namespace std;
class patientdata
{
    int patient_id;
    string patient_name;
    int patient_age;
    string blood_group;
    string patient_diseases;
    string phone;
public:
    void setpatient_id(int n)
    {
        patient_id=n;
    }
    void setpatient_name(string s)
    {
        patient_name=s;
    }
    void setpatient_age(int n)
    {
        patient_age=n;
    }
    void setblood_group(string s)
    {
        blood_group=s;
    }
    void setpatient_diseases(string s)
    {
        patient_diseases=s;
    }
    void setphone(string n)
    {
        phone=n;
    }
    /*void set_patientdata(int id,string name,int age,string bg,string pd,int p)
    {
        patient_id=id;
        patient_name=name;
        patient_age=age;
        blood_group=bg;
        patient_diseases=pd;
        phone=p;
    }*/
    void set_patientdata()
    {
        cout<<"\t\tEnter patient's id(integer)             : ";
        cin>>patient_id;
        cin.ignore();
        cout<<"\t\tEnter patient's name                    : ";
        getline(cin,patient_name);
        cout<<"\t\tEnter patient's age                     : ";
        cin>>patient_age;
        cin.ignore();
        cout<<"\t\tEnter patient's blood group             : ";
        //getline(cin,blood_group);
        cin>>blood_group;
        cin.ignore();
        cout<<"\t\tEnter patient's diseases                : ";
        getline(cin,patient_diseases);
        cout<<"\t\tEnter patient's phone number            : ";
        cin>>phone;
    }
    int getpatient_id()
    {
        return patient_id;
    }
    string getpatient_name()
    {
        return patient_name;
    }
    int getpatient_age()
    {
        return patient_age;
    }
    string getblood_group()
    {
        return blood_group;
    }
    string getpatient_diseases()
    {
        return patient_diseases;
    }
    string getphone()
    {
        return phone;
    }

};
int c=0;
fstream file("file.txt",ios::in|ios::out|ios::app);

void new_entry(patientdata a[])
{
    cout<<endl;
    cout<<"==============================================================================\n";
    cout<<"\t\t\t    New Patient Entry   \n";
    cout<<"==============================================================================\n";
    a[c].set_patientdata();
    file<<a[c].getpatient_id()<<endl;
    file<<a[c].getpatient_name()<<endl;
    file<<a[c].getpatient_age()<<endl;
    file<<a[c].getblood_group()<<endl;
    file<<a[c].getpatient_diseases()<<endl;
    file<<a[c].getphone()<<endl;
    ++c;
    system("cls");
    cout<<"Entry Completed..."<<endl;
    system("pause");
}
void view(patientdata a[])
{
    int id,age;
    string phone,name,bg,des;
    cout<<"==================================================================="<<endl;
    cout<<"\t\t\tPatient Database"<<endl;
    for(int i=0; i<c; ++i)
    {
        cout<<"==================================================================="<<endl;
        cout<<"==================================================================="<<endl;
        //file>>id;
        cout<<"Patient's ID            : "<<a[i].getpatient_id()<<endl;
        //file>>name;
        cout<<"Patient's name          : "<<a[i].getpatient_name()<<endl;
        //file>>age;
        cout<<"Patient's age           : "<<a[i].getpatient_age()<<endl;
        //file>>bg;
        cout<<"Patient's blood group   : "<<a[i].getblood_group()<<endl;
        //file>>des;
        cout<<"Patient's diseases      : "<<a[i].getpatient_diseases()<<endl;
        //file>>phone;
        cout<<"Patient's phone number  : "<<a[i].getphone()<<endl;
    }
    if(c==0)
    {
        cout<<"No patient data found!"<<endl;
    }
    system("pause");
}
void edit(patientdata a[])
{
    system("cls");
    int i,id,y=0;
    cout<<"\tEnter patient ID :";
    cin>>id;
    for(i=0; i<c; ++i)
    {
        if(a[i].getpatient_id()==id)
        {
            cout<<"Record Found...."<<endl;
            while(1)
            {
                system("cls");
                cout<<endl;
                cout<<"==============================================================================\n";
                cout<<"\t\t\t    Edit Patient data   \n";
                cout<<"==============================================================================\n";
                cout<<"\n\t 1 . Edit ID";
                cout<<"\n\t 2 . Edit name";
                cout<<"\n\t 3 . Edit age";
                cout<<"\n\t 4 . Edit blood group";
                cout<<"\n\t 5 . Edit diseases";
                cout<<"\n\t 6 . Edit phone number";
                cout<<"\n\t 7 . Main menu";
                int b;
                cout<<"\n\n\n\tEnter your Choice:";
                cin>>b;
                //system("cls");
                switch(b)
                {
                case 1:
                    if(b==1)
                    {
                        //system("cls");
                        int id1;
                        cout<<"\tEnter new ID       :";
                        cin>>id1;
                        cout<<"\tWant to save new ID?"<<endl;
                        cout<<"\t1.Agree"<<endl;
                        cout<<"\t2.Disagree"<<endl;
                        cout<<"\tEnter your choice:";
                        int x;
                        cin>>x;
                        if(x==1)
                        {
                            a[i].setpatient_id(id1);
                            system("cls");
                            cout<<"Successfully edited."<<endl;
                            system("pause");
                            break;
                        }
                        if(x==2)
                        {
                            system("cls");
                            cout<<"Not edited!"<<endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout<<"Invalid input!!!"<<endl;
                            system("pause");
                            break;
                        }
                    }
                case 2:
                    if(b==2)
                    {
                        //system("cls");
                        cout<<"\tEnter new name       :";
                        string n;
                        cin>>n;
                        cout<<"\tWant to save new name for ID "<<a[i].getpatient_id()<<"?"<<endl;
                        cout<<"\t1.Agree"<<endl;
                        cout<<"\t2.Disagree"<<endl;
                        cout<<"\tEnter your choice:";
                        int x;
                        cin>>x;
                        if(x==1)
                        {
                            a[i].setpatient_name(n);
                            system("cls");
                            cout<<"Successfully edited."<<endl;
                            system("pause");
                            break;
                        }
                        if(x==2)
                        {
                            system("cls");
                            cout<<"Not edited!"<<endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout<<"Invalid input!!!"<<endl;
                            system("pause");
                            break;
                        }
                    }
                case 3:
                    if(b==3)
                    {
                        //system("cls");
                        cout<<"\tEnter new age       :";
                        int ag;
                        cin>>ag;
                        cout<<"\tWant to save new age for ID "<<a[i].getpatient_id()<<"?"<<endl;
                        cout<<"\t1.Agree"<<endl;
                        cout<<"\t2.Disagree"<<endl;
                        cout<<"\tEnter your choice:";
                        int x;
                        cin>>x;
                        if(x==1)
                        {
                            a[i].setpatient_age(ag);
                            system("cls");
                            cout<<"Successfully edited."<<endl;
                            system("pause");
                            break;
                        }
                        if(x==2)
                        {
                            system("cls");
                            cout<<"Not edited!"<<endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout<<"Invalid input!!!"<<endl;
                            system("pause");
                            break;
                        }
                    }
                case 4:
                    if(b==4)
                    {
                        //system("cls");
                        cout<<"\tEnter new blood group       :";
                        string bg;
                        cin>>bg;
                        cout<<"\tWant to save new blood group for ID "<<a[i].getpatient_id()<<"?"<<endl;
                        cout<<"\t1.Agree"<<endl;
                        cout<<"\t2.Disagree"<<endl;
                        cout<<"\tEnter your choice:";
                        int x;
                        cin>>x;
                        if(x==1)
                        {
                            a[i].setblood_group(bg);
                            system("cls");
                            cout<<"Successfully edited."<<endl;
                            system("pause");
                            break;
                        }
                        if(x==2)
                        {
                            system("cls");
                            cout<<"Not edited!"<<endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout<<"Invalid input!!!"<<endl;
                            system("pause");
                            break;
                        }
                    }
                case 5:
                    if(b=5)
                    {
                        //system("cls");
                        cout<<"\tEnter new diseases       :";
                        string d;
                        cin>>d;
                        cout<<"\tWant to save new diseases for ID "<<a[i].getpatient_id()<<"?"<<endl;
                        cout<<"\t1.Agree"<<endl;
                        cout<<"\t2.Disagree"<<endl;
                        cout<<"\tEnter your choice:";
                        int x;
                        cin>>x;
                        if(x==1)
                        {
                            a[i].setpatient_diseases(d);
                            system("cls");
                            cout<<"Successfully edited."<<endl;
                            system("pause");
                            break;
                        }
                        if(x==2)
                        {
                            system("cls");
                            cout<<"Not edited!"<<endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout<<"Invalid input!!!"<<endl;
                            system("pause");
                            break;
                        }
                    }
                case 6:
                    if(b==6)
                    {
                        //system("cls");
                        cout<<"\tEnter new phone number       :";
                        string phn;
                        cin>>phn;
                        cout<<"\tWant to save new phone number for ID "<<a[i].getpatient_id()<<"?"<<endl;
                        cout<<"\t1.Agree"<<endl;
                        cout<<"\t2.Disagree"<<endl;
                        cout<<"\tEnter your choice:";
                        int x;
                        cin>>x;
                        if(x==1)
                        {
                            a[i].setphone(phn);
                            system("cls");
                            cout<<"Successfully edited."<<endl;
                            system("pause");
                            break;
                        }
                        if(x==2)
                        {
                            system("cls");
                            cout<<"Not edited!"<<endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout<<"Record not found!!!"<<endl;
                            system("pause");
                            break;
                        }
                    }
                case 7:
                    if(b==7)
                    {
                        //system("cls");
                        return;
                    }
                default:
                    if(b!=1 && b!=7)
                    {
                        system("cls");
                        cout<<"Invalid choice...!!!"<<endl;
                        system("pause");
                        return;
                    }

                }
            }
        }
        else
        {
            ++y;
        }
    }
    if(y==0)
    {
        cout<<"\tRecord not found!"<<endl;
        system("pause");
    }
}
void searchdata(patientdata a[])
{
    system("cls");
    int id,counter=0;
    cout<<"\tEnter patient id            :";
    cin>>id;
    for(int i=0; i<c; ++i)
    {
        //cout<<"success.."<<endl;
        if(a[i].getpatient_id()==id)
        {
            cout<<"\tRecord found..."<<endl;
            cout<<endl;
            cout<<"\tPatient's ID            : "<<a[i].getpatient_id()<<endl;
            cout<<"\tPatient's name          : "<<a[i].getpatient_name()<<endl;
            cout<<"\tPatient's age           : "<<a[i].getpatient_age()<<endl;
            cout<<"\tPatient's blood group   : "<<a[i].getblood_group()<<endl;
            cout<<"\tPatient's diseases      : "<<a[i].getpatient_diseases()<<endl;
            cout<<"\tPatient's phone number  : "<<a[i].getphone()<<endl;
            counter++;
            system("pause");
            break;
        }
    }
    if(counter==0)
    {
        cout<<"Record not found!!!"<<endl;
        system("pause");
    }
}
void deletedata(patientdata a[])
{
    system("cls");
    int id1,i,counter=0;
    cout<<"\tEnter patient ID            :";
    cin>>id1;
    for(i=0; i<c; ++i)
    {
        if(a[i].getpatient_id()==id1)
        {
            cout<<"\tWant to delete data for ID "<<a[i].getpatient_id()<<"?"<<endl;
            cout<<"\t1.Agree"<<endl;
            cout<<"\t2.Disagree"<<endl;
            cout<<"\tEnter your choice:";
            int x;
            cin>>x;
            if(x==1)
            {
                a[i].setpatient_id(a[i+1].getpatient_id());
                a[i].setpatient_name(a[i+1].getpatient_name());
                a[i].setpatient_age(a[i+1].getpatient_age());
                a[i].setblood_group(a[i+1].getblood_group());
                a[i].setpatient_diseases(a[i+1].getpatient_diseases());
                a[i].setphone(a[i+1].getphone());
                for(int j=i+1; j<c-1; ++j)
                {
                    a[j].setpatient_id(a[j+1].getpatient_id());
                    a[j].setpatient_name(a[j+1].getpatient_name());
                    a[j].setpatient_age(a[j+1].getpatient_age());
                    a[j].setblood_group(a[j+1].getblood_group());
                    a[j].setpatient_diseases(a[j+1].getpatient_diseases());
                    a[j].setphone(a[j+1].getphone());
                }
                cout<<"\tData deleted!"<<endl;
                counter++;
                --c;
                system("pause");
                break;
            }
            if(x==2)
            {
                cout<<"\tNot deleted!"<<endl;
                counter++;
                system("pause");
                break;
            }

            //break;
        }
    }
    if(counter==0)
    {
        cout<<"\tRecord not found!!!"<<endl;
        system("pause");
    }
}
int main()
{
    patientdata p[size];
    //fstream file("file.txt",ios::in|ios::out|ios::app);
    if(file.is_open())
    {
        while(1)
        {
            system("cls");
            cout<<"\tProgram Developed by :-";
            cout<<"\tMd. Jusef and Swakshar Debnath\n";
            cout<<endl;
            cout<<"==============================================================================\n";
            cout<<"\t\t\t ***Hospital Management System***\n";
            cout<<"==============================================================================\n";
            cout<<"\n\t 1 . Enter New Patient Data";
            cout<<"\n\t 2 . View Patient Database";
            cout<<"\n\t 3 . Edit Patient Data";
            cout<<"\n\t 4 . Search Patient Data";
            cout<<"\n\t 5 . Delete Patient Information";
            cout<<"\n\t 6 . Exit ";
            int a;
            cout<<"\n\n\n\tEnter your Choice:";
            cin>>a;
            //system("cls");
            switch(a)
            {
            case 1:
                if(a==1)
                {
                    system("cls");
                    new_entry(p);
                    break;
                }
            case 2:
                if(a==2)
                {
                    system("cls");
                    view(p);
                    //system("cls");
                    break;
                }
            case 3:
                if(a==3)
                {
                    system("cls");
                    edit(p);
                    break;

                }
            case 4:
                if(a==4)
                {
                    //system("cls");
                    searchdata(p);
                    break;
                }
            case 5:
                if(a==5)
                {
                    system("cls");
                    deletedata(p);
                    break;

                }
            case 6:
                if(a==6)
                {
                    system("cls");
                    cout<<"\n\tProgram terminated..."<<endl;
                    return 0;
                }
            default:
                if(a!=1 && a!=6)
                {
                    cout<<"\tInvalid input..."<<endl;
                    return 0;
                }
            }

        }
    }
    else
    {
        cout<<"File not found!"<<endl;
    }

}
