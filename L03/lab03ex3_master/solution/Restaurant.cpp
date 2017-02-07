//=====================================================================
// FILE: Restaurant.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <vector>
#include <iostream>
#include "Table.h"
using namespace std;


Table* findTable(const vector<Table*> &tables, const string &name) {
  for (vector<Table*>::size_type i = 0; i < tables.size(); i++) {
    if (tables[i]->getName() == name) {
      return tables[i];
    }
  }
  return NULL;
}

Group* findGroup(const vector<Group*> &groups, const string &name) {
  for (vector<Group*>::size_type i = 0; i < groups.size(); i++) {
    if (groups[i]->getName() == name) {
      return groups[i];
    }
  }
  return NULL;
}

Table* findFitting(const vector<Table*> &tables, const int &people) {
  Table* currentAnswer = NULL;
  for (vector<Table*>::size_type i = 0; i < tables.size(); i++) {
    if (tables[i]->getGroup() == NULL && tables[i]->getCapacity() >= people) {
      if (currentAnswer == NULL || currentAnswer->getName() > tables[i]->getName()) {
        currentAnswer = tables[i];
      }
    }
  }
  return currentAnswer;
}

Table* findTableFromGroup(const vector<Table*> &tables, Group* const &group) {
  for (vector<Table*>::size_type i = 0; i < tables.size(); i++) {
    if (tables[i]->getGroup() == group) {
      return tables[i];
    }
  }
  return NULL;
}

int main() {
  vector<Table*> tables;
  vector<Group*> groups;
  
  //input
  int n, q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    int size;
    cin >> name >> size;
    Table* table = new Table(name, size);
    tables.push_back(table);
  }

  //process queries
  cin >> q;
  for (int i = 0; i < q; i++) {
    int queryType;
    cin >> queryType;
    if (queryType == 1) {
      string groupName;
      int numPeople;
      string tableName;
      cin >> groupName >> numPeople >> tableName;
      Group* group = new Group(groupName, numPeople);
      groups.push_back(group);
      Table* table = findTable(tables, tableName);
      if (table->addGroup(group)) {
        cout << table->getName() << endl;
      } else {
        cout << "not possible" << endl;
      }
    } else if (queryType == 2) {
      string groupName;
      int numPeople;
      cin >> groupName >> numPeople;
      Group* group = new Group(groupName, numPeople);
      groups.push_back(group);
      Table* table = findFitting(tables, group->getSize());
      if (table != NULL) {
        table->addGroup(group);
        cout << table->getName() << endl;
      } else {
        cout << "not possible" << endl;
      }
    } else if (queryType == 3) {
      string groupName;
      cin >> groupName;
      Group* group = findGroup(groups, groupName);
      Table* table = findTableFromGroup(tables, group);
      if (table != NULL) {
        table->removeGroup();
      }
    } else if (queryType == 4) {
      string groupName;
      cin >> groupName;
      Group* group = findGroup(groups, groupName);
      if (group == NULL) {
        cout << "invalid" << endl;
      }
      else {
        Table* table = findTableFromGroup(tables, group);
        if (table != NULL) {
          cout << table->getName() << endl;
        } else {
          cout << "invalid" << endl;
        }
      }
    } else if (queryType == 5) {
      string tableName;
      cin >> tableName;
      Table* table = findTable(tables, tableName);
      if (table == NULL) {
        cout << "invalid" << endl;
      } else {
        Group* group = table->getGroup();
        if (group == NULL) {
          cout << "invalid" << endl;
        } else {
          cout << group->getName() << endl;
        }
      }
    }
  }
}
