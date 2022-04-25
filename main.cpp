#include <iostream>
#include <vector>
using namespace std;

vector<double> methodGauss(vector<vector<double>> a){
    for(int k=1;k<a.size();++k)
        for(int j=k;j<a.size();++j){
            double m = a[j][k-1]/a[k-1][k-1];
            for(int i=0;i<=a.size();++i)
                a[j][i] = a[j][i] - m*a[k-1][i];
        }
    vector<double> x(a.size());
    for(int i = a.size()-1;i>=0; --i){
        x[i]=a[i][a.size()] / a[i][i];
        for(int c=a.size()-1;c>i;--c)
            x[i]=x[i]-a[i][c]*x[c]/a[i][i];
    }
    return x;
}

int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    vector<vector<double>>a(n,vector<double>(n+1));
    cout<<"enter coefficients:\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n+1;++j){
            cin>>a[i][j];
        }
    }
    vector<double> x = methodGauss(a);
    cout<<"solution:";
    for(int i=0;i<x.size();++i){
        cout<<x[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
