#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <math.h>
using namespace std;

typedef long long ll;

ll priority(const string &s){
    if (s=="_")return 3;
    if (s=="^")return 3;
    if (s=="*" || s=="/")return 2;
    if (s=="+" || s=="-")return 1;
    return 0;
}

bool left(const string &s){
    return(s!="_" && s!="^");
}

vector<string> tokenize(const string &s){
    vector<string> t;
    for(ll i=0;i<s.size(); ){
        if (isdigit(s[i])){
            string num;
            while (i<s.size() && isdigit(s[i])){
                num+=s[i];
                i++;
            }
            t.push_back(num);
        } 
        else if(s[i]=='-'){
            if (t.empty() || t.back()=="(" || priority(t.back())>0)t.push_back("_");
            else
                t.push_back("-");
            i++;
        }
        else if(s[i]=='+' || s[i]=='*' || s[i]=='/' || s[i]=='^' || s[i]=='(' || s[i]==')'){
            t.push_back(string(1, s[i]));
            i++;
        }
        else i++;
    }
    return t;
}

vector<string> ETPN(const vector<string>& t){
    vector<string> out;
    stack<string> st;
    for(auto &x : t){
        if(isdigit(x[0])){
            out.push_back(x);
        } 
        else if(x=="(")st.push(x);
        else if(x == ")"){
            while(st.top()!="("){
                out.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && st.top()!="(" && (priority(st.top())>priority(x) || (priority(st.top())==priority(x) && left(x)))) 
            {
                out.push_back(st.top());
                st.pop();
            }
            st.push(x);
        }
    }
    while(!st.empty()){
        out.push_back(st.top());
        st.pop();
    }
    return out;
}

ll eval(const vector<string>& t) {
    stack<ll> st;
    for(auto &x : t){
        if(isdigit(x[0])){
            st.push(stoi(x));
        }
        else if(x=="_"){
            ll a=st.top(); 
            st.pop();
            st.push(-a);
        }
        else {
            ll b=st.top();
            st.pop();
            ll a=st.top();
            st.pop();
            if(x=="+")st.push(a+b);
            else if(x=="-")st.push(a-b);
            else if(x=="*")st.push(a*b);
            else if(x=="/")st.push(a/b);
            else if(x=="^")st.push(pow(a,b));
        }
    }
    return st.top();
}

int main(){
    string s;
    getline(cin, s);
    auto t=tokenize(s);
    auto res=ETPN(t);
    for(auto &x:res)cout<<x<<" ";
    cout<<endl;
    cout<<eval(res)<<endl;
}
