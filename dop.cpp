#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main() {
    FILE* file=fopen("text.txt", "r");
    if(!file)return 1;
    vector<string> words;
    char buffer[1000];
    while(fscanf(file,"%s",buffer)!=EOF){
        words.push_back(string(buffer));
    }
    fclose(file);
    vector<string> line;
    ll currentLen=0;
    const ll MAX_W=30;
    for(ll i=0;i<words.size();i++){
        string w=words[i];
        if(currentLen+line.size()+w.length()>MAX_W){
            ll totalSpaces=MAX_W-currentLen;
            ll gaps=line.size()-1;
            for(ll j=0;j<line.size();j++){
                cout<<line[j];
                if(j<gaps){
                    ll spacesToAdd=(totalSpaces/gaps)+(j<(totalSpaces%gaps)?1:0);
                    for(ll k=0;k<spacesToAdd;k++)cout<<" ";
                }
            }
            cout<<endl;
            line.clear();
            currentLen=0;
        }
        line.push_back(w);
        currentLen+=w.length();
    }
    if(!line.empty()){
        for(size_t j=0;j<line.size();j++){
            cout<<line[j]<<(j<line.size()-1?" ":"");
        }
        cout<<endl;
    }
    return 0;
}