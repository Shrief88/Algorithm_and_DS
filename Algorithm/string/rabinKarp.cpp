#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int polyHash(string s){
    long long hash = 0;
    int a = 122;
    int p = 1000000007;
    for(int i=s.length()-1;i>=0;i--){
        hash = ((hash*a)+int(s[i]))%p;
    }
    return hash;
}


vector<long long> preComputedHash(string p,string t){
    int x = 122;
    int prime = 1000000007;
    vector<long long> hashValues(t.length()-p.length()+1);
    string s = t.substr(t.length()-p.length(),t.length());
    hashValues[t.length()-p.length()] = polyHash(s);
    long long y=1;
    for(int i=0;i<p.length();i++)
        y = (((y*x) % prime)+prime)%prime;
    
    for(int i=t.length()-p.length()-1;i>=0;i--){
        hashValues[i] = (((x*hashValues[i+1]+ int(t[i]) - y* int(t[i+p.length()]))%prime)+prime)%prime;
    }

    return hashValues;
}

vector<int> rabinKarp(string p,string t){
    vector<int>res;
    int pHash = polyHash(p);
    vector<long long> hashes = preComputedHash(p,t);
    for(int i=0;i<=t.length()-p.length();i++){
        if(pHash == hashes[i]){
            bool flag = true;
            int k=i;
            for(int j=0;j<p.length();j++,k++){
                if(p[j] != t[k])
                    flag = false;
            }
            if(flag)
                res.push_back(i);
        }
    }
    return res;
}



int main(){
   string p,t;
   cin >> p >> t;
   vector<int> res = rabinKarp(p,t);
   for(int i=0;i<res.size();i++)
        cout << res[i] << " "; 

    
}