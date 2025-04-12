#include <iostream>
#include <climits>
#include <vector>
using namespace std;

float W(int i,int j,float p[], float q[]){
    if(i==j){
        return q[i];
    }
    return W(i, j-1, p, q)  + p[j] + q[j];
}

float optcost(int keys[], float p[], float q[],int i, int j,int root[][7]){
    if(j<i){
        return 0;
    }
    if(i==j){
        return 0;
    }
    float mincost=INT_MAX;
    for(int r=j;r>=i+1;r--){
        float cost = optcost(keys, p, q,i, r-1,root) + optcost(keys, p, q, r, j,root);
        if (cost<mincost){
            mincost=cost;
            root[i][j] = r;
        }
    }
    return mincost + W(i, j, p, q);
}

float optimal_bst(int keys[], float p[], float q[], int n,int root[][7]){
    return optcost(keys, p, q, 0, n,root);
}

void printTree(int root[][7],int keys[6],int current_root,int i,int j) {
    if(i==j) return;
    if (i != current_root-1){
        cout << "Left child of " << keys[current_root-1] << ": " << keys[root[i][current_root-1] - 1] << endl;
    }else{
        cout << "Left child of " << keys[current_root-1] << ": Null "<< endl;
    }
    
    if(current_root!=j){
        cout<<"right child of "<<keys[current_root-1]<<": "<<keys[root[current_root][j]-1]<<endl;
    }else{
        cout << "right child of " << keys[current_root-1] << ": Null " << endl;
    }
    cout<<endl;
    printTree(root, keys, root[i][current_root - 1], i, current_root - 1);
    printTree(root, keys, root[current_root][j], current_root , j);
}

int main(){
    int keys[6] = {5,15,30,45,55,65};
    float p[]={0,0.1,0.15,0.2,0.25,0.1,0.05};
    float q[] ={0.05,0.1,0.15,0.2,0.3,0.1,0.1};
    int root[7][7] = {0};
    cout << "Optimal BST Cost: " << optimal_bst(keys, p, q, 6, root) << endl;
    cout << "Root of full BST: " << keys[root[0][6]-1] << endl;
    printTree(root,keys,root[0][6],0,6);

    return 0;
}
