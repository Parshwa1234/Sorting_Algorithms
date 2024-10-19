#include<bits/stdc++.h>
#include<chrono>

using namespace std;

void bubblesort(vector<int>&v)//Best:O(N),Average:O(N^2),Worst:O(N^2)
{
    for(int i=0;i<v.size();i++)
    {
        bool ch=0;
        for(int j=0;j<v.size()-1;j++)
        {
            if(v[j]>v[j+1])
            {
                ch=1;
                swap(v[j+1],v[j]);
            }
        }
        if(!ch)
        {
            break;
        }
    }
}

void insertionsort(vector<int>&v)//Best:O(N),Average:O(N^2),Worst:O(N^2) More swaps
{
    for(int i=0;i<v.size();i++)
    {
        int j=i;
        while(j>0 && v[j-1]>v[j])
        {
            swap(v[j],v[j-1]);
            --j;
        }
    }
}

void selectionsort(vector<int>&v)//Best:O(N^2),Average:O(N^2),Worst:O(N^2) Less swaps
{
    for(int i=0;i<v.size();i++)
    {
        int k=-1;
        int val=v[i];
        for(int j=i+1;j<v.size();j++)
        {
            if(v[j]<val)
            {
                val=v[j];
                k=j;
            }
        }
        if(k!=-1)
        {
            swap(v[i],v[k]);
        }
    }
}

void recursive_bubblesort(vector<int>&v,int i,int j,bool &ch)
{
    if(i>=v.size()-1)
    {
        return;
    }
   if(j>=v.size()-1)
   {
       if(!ch)
       {
           return;
       }
       else
       {
          ch=0;
          recursive_bubblesort(v,i+1,0,ch);
       }
   }
   else{
       if(v[j]>v[j+1])
       {
           swap(v[j],v[j+1]);
           ch=1;
       }
       recursive_bubblesort(v,i,j+1,ch);
   }
   return;
}

void recursive_insertionsort(vector<int>&v,int i)
{
    if(i==v.size())
    {
        return ;
    }
    int j=i-1,curr=i;
    while(j>=0 && v[curr]<v[j])
    {
        swap(v[curr],v[j]);
        --curr;
        --j;
    }
    recursive_insertionsort(v,i+1);
}

void recursive_selectionsort(vector<int>&v,int i,int j,int val,int k)
{
    if(i>=v.size())
    {
        return;
    }
    else if(j>=v.size())
    {
        if(k!=-1)
        {
            swap(v[k],v[i]);
        }
        if(i+1<v.size())
        {
        recursive_selectionsort(v,i+1,i+2,v[i+1],-1);
        }
        else
        {
            return;
        }
    }
    else
    {
        if(v[j]<val)
        {
            val=v[j];
            k=j;
        }
        recursive_selectionsort(v,i,j+1,val,k);
    }
    return;
}

void mergesort(vector<int>&v,vector<int>&temp,int l,int r)//O(NlogN) used widely 
{
    if(l==r)
    {
        return;
    }
    int mid=(l+r)/2;
    mergesort(v,temp,l,mid);
    mergesort(v,temp,mid+1,r);
    int a=l,b=mid+1,c=l;
    while(a<=mid || b<=r)
    {
        if(a<=mid && b<=r)
        {
            if(v[a]<=v[b])
            {
                temp[c]=v[a];
                ++c;
                ++a;
            }
            else
            {
                temp[c]=v[b];
                ++c;
                ++b;
            }
        }
        else if(a<=mid)
        {
            temp[c]=v[a];
                ++c;
                ++a;
        }
        else
        {
            temp[c]=v[b];
                ++c;
                ++b;
        }
    }
    for(int i=l;i<=r;i++)
    {
        v[i]=temp[i];
    }
}

int main(){
    vector<int>v,temp;
    srand(static_cast<unsigned int>(time(0)));
    int n=100;
    for(int i=0;i<n;i++)
    {
        v.push_back(rand()%1000);
    }
    temp=v;
    bool ch=0;
    auto start=chrono::high_resolution_clock::now();
    // bubblesort(v);
    // insertionsort(v);
    // selectionsort(v);
    // recursive_bubblesort(v,0,0,ch);
    // recursive_insertionsort(v,0);
    //  recursive_selectionsort(v,0,1,v[0],-1);
    //  mergesort(v,temp,0,v.size()-1);
    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"Timetaken to sort:"<<duration<<" nano seconds"<<endl;
    
}
