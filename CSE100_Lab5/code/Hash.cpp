/*
 Nimitt Tripathy
 CSE 100 Lab 04L
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Hash.h"

using namespace std;


Hash::Hash(int _bNo) {
    this->bNo = _bNo;
    table.resize(_bNo);
}

Hash::~Hash() {
    // if(Hash!=NULL){
    //    delete [] Hash;
    // }
}

void Hash::Insert(int toInsert) {
    int key = toInsert % bNo;
    //h(k) = k mod m
    table[key].push_front(toInsert);
    //Key is put at the beggining of the link list for collisions
}


/*bool Delete(int key,int size){
 //MUST BE PRESENT @ KEY MOD SIZE
 //Same structure as Search
 int mod = key%size;
 //list<int>::iterator T;
 //list<int> N=hashTable[mod];
 
 //case 1
 if(N.empty())
 return false; //list empty means delete failed
 //case 2
 for (T=N.begin(); T!=N.end(); ++T)//search the list for key
 {
 //erases element from the list
 if(key==*T)
 {
 N.erase(T);
 hashTable[mod]=N;
 //IF DELETE SUCCESSFUL, THEN OUTPUT
 return true;
 }
 }
 return false;
 
 }
 */
bool Hash::Delete(int toDelete) {
    list<int>::iterator T;
    int key = toDelete % bNo;
    // list<int> N=table[key];
    //  list<int>::iterator i = table[key];
   // int mod = key%size;
    list<int> N=table[key];
    //case 1
    if(N.empty())
        return false; //list empty means delete failed
   //case 2
    for (T = table[key].begin(); T != table[key].end(); T++) //search the list for key
    {
        if(toDelete==*T)
        {
            //print when found
            table[key].erase(T);
            //IF DELETE SUCCESSFUL
            return true;
        }
    }
    
    return false;
}


bool Hash::Search(int key, int& _bucket, int& _pos)
{
     int mod = key % bNo;
    _bucket = mod;
    _pos = 0;

    list<int>::iterator T;
    list<int> N=table[mod];
   
    
  
    for(T = N.begin(); T != N.end(); T++)
    {
        
        if(*T ==key)
        {
            return true;
        }
        
        
        _pos++;
        //position++
    }
    
   
    return false;
}
void Hash::Print()
{
    list<int> N;
    list<int>::iterator T;
    //list <int> X;
    for(int i=0;i<bNo;i++){
            if(N.empty())
            {}
            cout<< i << " : ";
            //PRINTS LIST
            N=table[i];
            for (T=N.begin(); T!=N.end(); ++T)
            {
                //cout<< *T<<"->";
                cout << *T;
               
                //check if we are on the END, if not,only then can we print ->
                if(++T != N.end())
                    cout << "->";
                    --T;
                
            }
           // cout<<";";
            cout<<endl;
        
    
}

}

