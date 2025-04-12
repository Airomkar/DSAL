#include <iostream>
using namespace std;
class Node {
public:
string name;
string meaning;
Node *ln;
Node *rn;
Node(){
ln=NULL;
rn=NULL;
}
};
class BSTD{
public:
Node* root;
Node* createTree (string name , string meaning){
root = new Node();
root->name = name;
root->meaning = meaning;
root->ln = NULL;
root->rn = NULL;
return root;
}
void insert (Node* root , string name , string meaning){
Node* temp = new Node();
temp->name = name;
temp->meaning = meaning;
if (root->name >= name){
if (root->ln == NULL){
root->ln = temp;
}
else
insert (root->ln , name , meaning);
}
else if (root->name < name)
{
if (root->rn == NULL){
root->rn = temp;
}
else
insert (root->rn , name , meaning);
}
}
void displayInOrder(Node* root){
if(root != NULL){
displayInOrder(root->ln);
cout<<root->name << " : " << root->meaning<<"\n";
displayInOrder(root->rn);
}
}
};
int main (){
BSTD B;
Node* root = B.createTree("Great" , "excellent or superior");
B.insert(root , "Procrastination" , "the action of delaying or postponing something.");
B.insert(root , "Multimedia" , "using more than one medium");
B.insert(root , "Angular" , "having angles or sharp corners.");
B.insert(root , "Coding" , "giving a computer a set of instructions");
B.insert(root , "Debugging" , " finding and fixing errors or bugs");
B.displayInOrder(root);
return 0;
}
