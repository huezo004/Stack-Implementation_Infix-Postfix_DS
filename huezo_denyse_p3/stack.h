#include<iostream> 
#include<list>

using namespace std; 

namespace cop4530{
template<typename T>
class Stack{
public:
   Stack();
   ~Stack(); 
   Stack(const Stack<T>& st); 
   Stack(Stack<T> && st);
   Stack<T>& operator= (const Stack <T>& st); 
   Stack<T> & operator=(Stack<T> && st);
   bool empty() const; 
   void clear(); 
   void push(const T& x);
   void push(T && x); 
   void pop(); 
   T& top(); 
   const T& top() const; 
   int size() const; 
   void print(std::ostream& os, char ofc = ' ') const; 

 private:
   std::list<T> List; 
   
 };

template<typename T>
 std::ostream& operator<< (std::ostream& os, const Stack<T>& a);

template<typename T>
 bool operator== (const Stack<T>&, const Stack <T>&);

template<typename T>
 bool operator!= (const Stack<T>&, const Stack <T>&); 

template<typename T>
 bool operator<= (const Stack<T>& a, const Stack <T>& b);

 #include "stack.hpp"
}//END OF NAMESPACE 4530 
