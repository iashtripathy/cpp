// CPP code to illustrate// priorit_queue and its// various function
#include<bits/stdc++.h>
using namespace std; 
struct Person {    
    int age;    
    float ht;        
    Person(int a, float h){        
        age = a;        
        ht = h;    
    }
}; 
struct myCmp {    
    bool operator()(Person const &p1, Person const &p2){        
        return p1.ht < p2.ht;    
    }
};

// Drivers Method

int main(){     
   // Creating a priority queue    
   priority_queue < Person, vector<Person>, myCmp> pq;     
   // Pushing elements into    // the priority_queue    
   // First Person    
   Person p1(21, 5);    
   pq.push(p1);        
   // Second Person    
   Person p2(22, 6);    
   pq.push(p2);        
   // Third Person    
   Person p3(23, 7);    
   pq.push(p3);     
   // Displaying the top elements    // of the queue    
   while (pq.empty() == false) {        
       cout<<pq.top().ht << " ";        
       pq.pop();    
   }    
   return 0;
}