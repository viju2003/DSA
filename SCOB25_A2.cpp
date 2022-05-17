#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

class student{
    public:
        int r;
        char m[10],dob[10],n[500],a[1000];
        char d;
        void createdata(){
            cout<<"\nEnter Roll Number: ";
            cin>>r;
            cin.ignore();
            cout<<"\nEnter Name: ";
            gets(n);
            cout<<"\nEnter Address: ";
            gets(a);
            cout<<"\nEnter Division: ";
            cin>>d;
        }
        void display(){
            cout<<"\nName: "<<n<<endl;
            cout<<"\nRoll number: "<<r<<endl;
            cout<<"\nDivision: "<<d<<endl;           
        }
};

void add(){
    ofstream ofile;
    ofile.open("StudData.dat",ios::binary|ios::app);
    student A;
    A.createdata();
    ofile.write((char*)&A,sizeof(A));
    ofile.close();
}

void show(){
    ifstream ifile;
    ifile.open("StudData.dat",ios::binary);
    student A;
    while(ifile.read((char*)&A,sizeof(A))){
        A.display();
    }
    ifile.close();
}

void Search(){
    int rn,f=0;
    cout<<"\n Enter roll number of student: ";
    cin>>rn;
    ifstream ifile;
    ifile.open("StudData.dat",ios::binary);
    student A;
    while(ifile.read((char*)&A,sizeof(A))){
        if(A.r==rn){
            f=1;
            A.display();
        }
    }
    if(f==0){
        cout<<"\n Students details not in the database";
    }
    ifile.close();
}
void Deletedata(){
    int n,f=0;
    student S;
    cout<<"\n Enter roll number to delete: ";
    cin>>n;
    ifstream ifile;
    ofstream ofile;
    ifile.open("StudData.dat",ios::binary);
    ofile.open("StempData.dat",ios::out|ios::binary);
    while(ifile.read((char*)&S,sizeof(S))){
        if(S.r!=n){
            ofile.write((char*)&S,sizeof(S));
        }
        else f=1;
    }
    if(f==0){
        cout<<"\n!!The student with roll number "<<n<<" is not present in the database!!";
    }
    else{
        cout<<"\n The data of student with roll number "<<n<<" is deleted";
    }
    ifile.close();
    ofile.close();
    remove("StudData.dat");
    rename("StempData.dat","StudData.dat");
}

int main(){
    int a;
    while(true){
        cout<<"\n\t\tMenu\n";
        cout<<"\t\t1--> Add Data\n";
        cout<<"\t\t2--> Show Data\n";
        cout<<"\t\t3--> Delete Data\n";
        cout<<"\t\t4--> Search in the Data\n";
        cout<<"\t\t5--> Exit\n";
        cout<<"\n\tENTER YOUR CHOICE: ";
        cin>>a;
        switch(a){
            case 1:
                add();
                break;
            case 2:
                show();
                break;
            case 3:
                Deletedata();
                break;
            case 4:
                Search();
                break;
            case 5:
                exit(0);
                break;
        }
    }
    return 0;
}
