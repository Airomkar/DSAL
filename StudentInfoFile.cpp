#include<iostream>
#include<fstream>
using namespace std;

 class stud{
      public:
       int roll;
       char name[10];
       char div;
       char add[10];
 
         void getinfo(){
            cout<<"enter name:";
            cin>>name;
            cout<<"enter roll:";
            cin>>roll;
            cout<<"enter div:";
            cin>>div;
            cout<<"enter addresss:";
            cin>>add;
           }
    
        void display(){
            cout<<"name:"<<name<<endl;
            cout<<"roll:"<<roll<<endl;
            cout<<"div:"<<div<<endl;
            cout<<"add:"<<add<<endl;
            cout<<endl;
           }
           void writedata();
           void readdata();
           void search();
           
        int getroll(){
            return roll;
        }  
        
 };
  
       void stud:: writedata(){
           ofstream f1;
           stud s1;
           f1.open("stud.dat",ios::binary|(ios::app));
           s1.getinfo();
           f1.write((char*)&s1,sizeof(s1));
           f1.close();
         }
         
       void stud:: readdata(){
           ifstream f1;
           stud s1;
           f1.open("stud.dat",ios::binary);
           while(f1.read((char*)&s1,sizeof(s1))){
                s1.display();
           }
           
           f1.close();
           cout<<endl;
         }
         
       void stud:: search(){
       int search_ele;
       cout<<"enter roll no which u want to search:";
       cin>>search_ele;  
       ifstream f1;
       stud s1;
       f1.open("stud.dat",ios::binary);
       int flag=0;
       while(f1.read((char*)&s1,sizeof(s1))){
         if (search_ele==s1.getroll()){
                flag=1;
                break;}     
          } 
       if (flag==1){
         cout<<"found";
         }
         
       else{
          cout<<"not found"; }       
             f1.close();
             cout<<endl;
         }
       
             void Delete(int r) {
             
             ofstream t1;
             ifstream f1;
             stud s1;
              f1.open("stud.dat",ios::binary);
              t1.open("studt.dat",ios::binary);
              
            while(f1.read((char*)&s1,sizeof(s1))){
                if(s1.roll!=r){
                  t1.write((char*)&s1,sizeof(s1));
                }
           }
              remove("stud.dat");
              rename("studt.dat","stud.dat");
              t1.close();
            
        
        }
   
 
 int main(){
        stud s1;
        int key;
        char ans='y';
        while(ans=='y'){
        
        cout<<"functions:-"<<endl;
        cout<<"1:writedata"<<endl;
        cout<<"2:readdata"<<endl;
        cout<<"3:search"<<endl;
        cout<<"4:Delete"<<endl;
        cout<<"enter choice:"<<endl;
        cin>>key;
        
        
        switch (key){
          case 1:
            {  s1.writedata();
              break;}
          case 2:  
              {  s1.readdata();
                break;}
         case 3:  
               {s1.getroll();
                s1.search();
                break;} 
         case 4:{
          cout<<"enter roll number:";
          int r;
          cin>>r;
          Delete(r);
          break;
         }
                

       }
       cout<<"continue(y/n):";
       cin>>ans;
       cout<<endl;
       }
 
  return 0;
 }
 
  
  
 

