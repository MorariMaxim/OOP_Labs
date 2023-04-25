#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
class CompareModule
{
    map<string, int> *table;
public:
    CompareModule(map<string, int>* m) : table(m) {}

    bool operator() (const string &s1, const string& s2) const
    {
        int r=2;
        if ((*table)[s1] > (*table)[s2]) r = 1;
        else if ((*table)[s1] = (*table)[s2]) r = 0;        
        
        if (r == 1) return true;
        else if (r == 0) {
            r = s1.compare(s2);
            return (r == 1);
        }
    }
}; 
class res {
public:
    string s;
    int frecv;
    bool operator<(const res& r2) const {
        int r = 2;
        if (frecv < r2.frecv) r = 1;
        else if (frecv == r2.frecv) r = 0;

        if (r == 1) return true;
        else if (r == 0) {
            r = s.compare(r2.s);
            return (r >0);
        }
        return false;
    }

};
int main()
{ 
    ifstream MyReadFile("thefile.txt");

    map<string, int> table;


    string myText = "";

    while (getline(MyReadFile, myText)) {   
                
    } 

    std::transform(myText.begin(), myText.end(), myText.begin(),
        [](unsigned char c) { return std::tolower(c); }); 
    string copy = myText;
    int p = copy.find_first_not_of(" ,!?.\n");
    int l;
    while (p>=0 && p<copy.size()) {
        copy = copy.substr(p);
        l = copy.find_first_of(" ,!?.");
        table[copy.substr(0, l)]++;
        
        copy = copy.substr(l);
        p = copy.find_first_not_of(" ,!?.");
    } 

    priority_queue<string, vector<string>, CompareModule> myq(CompareModule(&table));
    
    myq.push("asd");
        
    priority_queue<res> q;
    for (auto  a : table) {
        //cout << a.first << " " << a.second << endl;
        q.push({ a.first,a.second });
    }
    while (!q.empty()) {

        cout << q.top().s<<" => "<<q.top().frecv << endl;
        q.pop();
    }


    MyReadFile.close();
} 