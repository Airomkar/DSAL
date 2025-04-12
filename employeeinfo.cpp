#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

struct IndexEntry {
    int id;
    long position;
};

IndexEntry indexTable[MAX];
int indexCount = 0;

void loadIndex() {
    indexCount = 0;
    ifstream indexFile("index.txt");
    while (indexFile >> indexTable[indexCount].id >> indexTable[indexCount].position) {
        indexCount++;
    }
    indexFile.close();
}

void saveIndex() {
    ofstream indexFile("index.txt");
    for (int i = 0; i < indexCount; i++) {
        indexFile << indexTable[i].id << " " << indexTable[i].position << endl;
    }
    indexFile.close();
}

int searchIndex(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexTable[i].id == id)
            return i;
    }
    return -1;
}

void addEmployee() {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;

    if (searchIndex(emp.id) != -1) {
        cout << "Employee ID already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(emp.name, 50);
    cout << "Enter Designation: ";
    cin.getline(emp.designation, 50);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    ofstream dataFile("data.txt", ios::binary | ios::app);
    long pos = dataFile.tellp();
    dataFile.write((char *)&emp, sizeof(emp));
    dataFile.close();

    indexTable[indexCount].id = emp.id;
    indexTable[indexCount].position = pos;
    indexCount++;
    saveIndex();

    cout << "Employee added successfully!\n";
}

void displayEmployee() {
    int id;
    cout << "Enter Employee ID to display: ";
    cin >> id;

    int idx = searchIndex(id);
    if (idx == -1) {
        cout << "Employee not found!\n";
        return;
    }

    Employee emp;
    ifstream dataFile("data.txt", ios::binary);
    dataFile.seekg(indexTable[idx].position);
    dataFile.read((char *)&emp, sizeof(emp));
    dataFile.close();

    cout << "\n--- Employee Details ---\n";
    cout << "ID: " << emp.id << "\n";
    cout << "Name: " << emp.name << "\n";
    cout << "Designation: " << emp.designation << "\n";
    cout << "Salary: " << emp.salary << "\n";
}

void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    int idx = searchIndex(id);
    if (idx == -1) {
        cout << "Employee not found!\n";
        return;
    }

    ifstream dataFile("data.txt", ios::binary);
    ofstream tempFile("temp.txt", ios::binary);
    Employee emp;
    long newIndexPos = 0;
    indexCount = 0;

    while (dataFile.read((char *)&emp, sizeof(emp))) {
        if (emp.id != id) {
            tempFile.write((char *)&emp, sizeof(emp));
            indexTable[indexCount].id = emp.id;
            indexTable[indexCount].position = newIndexPos;
            newIndexPos += sizeof(emp);
            indexCount++;
        }
    }

    dataFile.close();
    tempFile.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");

    saveIndex();
    cout << "Employee deleted successfully!\n";
}

int main() {
    loadIndex();
    int choice;
    while (true) {
        cout << "\n- Employee Info -\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employee\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployee(); break;
            case 3: deleteEmployee(); break;
            case 4: return 0;
            default: cout << "Invalid choice!\n"; break;
        }
    }
}
