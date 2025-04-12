#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the number of cities:";
cin>>n;
string city[n];
cout<<"Enter the cities name"<<endl;
for(int i=0 ; i<n ; i++){
cin>>city[i];
}
cout<<endl;
cout<<"Enter the Time required"<<endl;
int time[n][n];
for(int i=0 ; i<n ; i++){
for(int j=0 ; j<n ; j++){
cout<<"for "<<city[i]<<" To "<<city[j]<<" : ";
cin>>time[i][j];
}
}
cout<<"This is time required to travel city to city"<<endl;
for(int i=0 ; i<n ; i++){
for(int j=0 ; j<n ; j++){
cout<<time[i][j]<<" ";
}
cout<<endl;
}
}
