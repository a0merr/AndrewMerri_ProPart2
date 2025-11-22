#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BST.h"
using namespace std;

int main() {
    BST tree;
    ifstream file("education-economy-data_modified_P2.csv");
    if (!file.is_open()) {
        cerr << "Error: Could not open education-economy-data_modified_P2.csv\n";
        return 1;
    }

    string header;
    if (!getline(file, header)) {
        cerr << "Error: Empty file\n";
        return 1;
    }

    string line;
    int id_counter = 1;
    while (getline(file, line)) {
        if(line.size()==0) continue;
        stringstream ss(line);
        vector<string> cols;
        string token;
        bool inQuotes = false;
        string cur = "";
        for (char c : line) {
            if (c == '"') inQuotes = !inQuotes;
            else if (c == ',' && !inQuotes) { cols.push_back(cur); cur.clear(); }
            else cur.push_back(c);
        }
        cols.push_back(cur);

        string country = "";
        double value = 0.0;
        bool gotValue = false;
        for (size_t i = 0; i < cols.size(); ++i) {
            string s = cols[i];
            while (!s.empty() && (s.front()==' ' || s.front()=='\t')) s.erase(0,1);
            while (!s.empty() && (s.back()==' ' || s.back()=='\t')) s.pop_back();
            try {
                size_t idx; double d = stod(s,&idx);
                if (idx == s.size()) { value = d; gotValue = true; }
            } catch(...) {
                if (country.empty()) country = s;
            }
        }

        if (!gotValue) continue;

        Record r;
        r.id = id_counter++;
        r.country = country;
        r.value = value;
        tree.Insert(r);
    }

    file.close();

    double threshold;
    cout << "Enter threshold for Literacy Rate: ";
    if (!(cin >> threshold)) { cerr << "Invalid input\n"; return 1; }

    cout << "\nRecords with Literacy Rate >= " << threshold << ":\n";
    tree.PrintRecordsAbove(threshold);

    return 0;
}
