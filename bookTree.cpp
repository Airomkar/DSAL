#include <iostream>
using namespace std;

struct node {
    string name;
    int count;
    node *child[10]; 
} *root;

class book {
public:
    book() {
        root = NULL;
    }

    void create() {
        root = new node();
        cout << "Enter the book name: ";
        cin >> root->name;
        cout << "Enter the total chapters: ";
        cin >> root->count;

        for (int i = 0; i < root->count; i++) {
            root->child[i] = new node();
            cout << "Enter the chapter name: ";
            cin >> root->child[i]->name;
            cout << "Enter the total sections: ";
            cin >> root->child[i]->count;

            for (int j = 0; j < root->child[i]->count; j++) {
                root->child[i]->child[j] = new node();  
                cout << "Enter the section name: ";
                cin >> root->child[i]->child[j]->name;
                cout << "Enter the total subsections: ";
                cin >> root->child[i]->child[j]->count;

                for (int k = 0; k < root->child[i]->child[j]->count; k++) {
                    root->child[i]->child[j]->child[k] = new node();
                    cout << "Enter the subsection name: ";
                    cin >> root->child[i]->child[j]->child[k]->name;
                }
            }
        }
    }

    void display() {
        cout << "Name of book: " << root->name << endl;
        cout << "The total chapters in the book: " << root->count << endl;
        for(int i = 0; i < root->count; i++) {
            cout << "Name of chapter " << i+1 << " is: " << root->child[i]->name << endl;
            cout << "The total sections in chapter " << i+1 << ": " << root->child[i]->count << endl;

            for (int j = 0; j < root->child[i]->count; j++) {
                cout << "Name of section " << j+1 << " is: " << root->child[i]->child[j]->name << endl;
                cout << "The total subsections in section " << j+1 << ": " << root->child[i]->child[j]->count << endl;

                for (int k = 0; k < root->child[i]->child[j]->count; k++) {
                    cout << "Name of subsection " << k+1 << " is: " << root->child[i]->child[j]->child[k]->name << endl;
                }
            }
        }
    }
};

int main() {
    book b1;
    b1.create();
    b1.display();
    return 0;
}

