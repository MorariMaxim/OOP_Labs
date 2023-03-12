#define _CRT_SECURE_NO_WARNINGS
#include<iostream>    
#include<algorithm>
#include <vector>
using namespace std;

int len(char* c) {
    int i=0;
    while (c[i] != 0)i++;
    return i;
}

int len(char** c) {
    int i = 0;
    while (c[i] != 0)i++;
    return i;
}

void sort(char** buffer, int n){
    int ultim = n - 1;
    while (ultim > 0) {
        int n1 = ultim - 1; ultim = 0;
        for (int i = 0; i <= n1;i++) {
            if (len(buffer[i]) < len(buffer[i+1])) {
                swap(buffer[i], buffer[i+1]);
                    ultim = i;
            }
            if (len(buffer[i]) == len(buffer[i + 1])) {
                if (strcmp(buffer[i], buffer[i + 1])>0) {
                    swap(buffer[i+1], buffer[i ]);
                    ultim = i;
                }
            }
        }
    }
}
int main()
{

    char buffer[256];     
    scanf(" %[^\n]", buffer);
    char* v[25];

    int it=0;
    const char s[2] = " ";
    char* token;
    
    token = strtok(buffer, s);

    while (token != NULL) {        
        v[it++] = token;
        token = strtok(NULL, s); 
    }
    v[it] = 0;
    int i = 0;
    int ln = len(v);
    sort(v, ln);

    for (int i = 0; i < ln; i++)
    {
        cout<< v[i]<<'\n';
    }
    return 0;
}