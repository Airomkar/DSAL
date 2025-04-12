#include <iostream>
#include <list>
#include <iterator>
using namespace std;
class HashTable {
private:
 int size;
 list<pair<string, int>> *table;
 int hashFunction(string key) {
 int hashValue = 0;
 for (char c : key) {
 hashValue = (hashValue * 31 + c) % size;
 }
 return hashValue % size;
 }
public:
 HashTable(int s) {
 size = s;
 table = new list<pair<string, int>>[size];
 }
 void insert(string key, int value) {int index = hashFunction(key);
 for (auto &pair : table[index]) {
 if (pair.first == key) {
 pair.second = value;
 return;
 }
 }
 table[index].push_back(make_pair(key, value));
 }
 int find(string key) {
 int index = hashFunction(key);
 for (auto &pair : table[index]) {
 if (pair.first == key) {
 return pair.second;
 }
 }
 return -1;
 }
 bool deleteKey(string key) {
 int index = hashFunction(key);
 for (auto it = table[index].begin(); it !=
table[index].end(); ++it) {
 if (it->first == key) {
 table[index].erase(it);
 return true;
 }
 }
 return false;
 }
~HashTable() {
 delete[] table;
 }
};
int main() {
 HashTable ht(10);
 ht.insert("apple", 5);
 ht.insert("banana", 10);
 ht.insert("orange", 15);
 cout << "apple: " << ht.find("apple") << endl;
 cout << "banana: " << ht.find("banana") << endl;
 cout << "grape: " << ht.find("grape") << endl;
 cout << "Deleting 'banana': " <<
(ht.deleteKey("banana") ? "Success" : "Failed") <<
endl;
 cout << "banana: " << ht.find("banana") << endl;
 return 0;
}
