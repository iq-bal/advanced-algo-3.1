#include <iostream>

using namespace std;

int knapsack(int w_v, int w_m, int v[], int wt[], int p[], int n){
    if(w_v==0 || n==0 || w_m==0)    return 0;
    if(v[n-1]>w_v || wt[n-1]>w_m)
        return knapsack(w_v,w_m,v,wt,p,n-1);
    else{
        return max(knapsack(w_v,w_m,v,wt,p,n-1), p[n-1]+knapsack(w_v-v[n-1],w_m-wt[n-1],v,wt,p,n-1));
    }
}

int main()
{
    cout<< "Number of items: " << endl;
    int n;
    cin>>n;
    cout<< "Enter prices of each items: " << endl;
    int p[n];
    for(int i=0; i<n; i++)
        cin>>p[i];
    cout<< "Enter mass of each item: "<< endl;
    int wt[n];
    for(int i=0; i<n; i++)
        cin>>wt[i];
    cout<< "Enter volume of each item: "<< endl;
    int v[n];
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<< "Enter mass capacity and volume capacity of the bag: "<< endl;
    int c_m,c_v;
    cin>>c_m>>c_v;
    cout<< knapsack(c_v,c_m, v,wt,p,n)<<endl;
    return 0;
}