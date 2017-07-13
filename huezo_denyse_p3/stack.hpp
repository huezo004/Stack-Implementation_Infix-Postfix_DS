template<typename T>
Stack<T>::Stack(){
  //List;  
}

template<typename T>
Stack<T>::~Stack(){
  //~List; 
}

template<typename T>
Stack<T>::Stack(const Stack<T>& st){
  List=st.List; 
}

template<typename T>
Stack<T>::Stack(Stack<T> && st){
  List= std::move(st.List);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st){
  List=st.List; 
  return *this; 
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> && st){
  List= std::move(st.List); 
}

template<typename T>
bool Stack<T>::empty() const{
  if(List.size()==0)
    return true; 
  else 
    return false; 
}

template<typename T>
void Stack<T>::clear(){
  List.clear();
}

template<typename T>
void Stack<T>::push(const T& x){
  List.push_front(x);
}

template<typename T>
void Stack<T>::push(T && x){
  List.push_front(std::move(x));
}

template<typename T>
void Stack<T>::pop(){
  List.pop_front();
}

template<typename T>
T& Stack<T>::top(){
  return List.front();
}

template<typename T>
const T& Stack<T>::top() const{
  return List.front();
}

template<typename T>
int Stack<T>::size() const{
  return List.size();
}

template<typename T>
void Stack<T>::print(std::ostream& os, char ofc) const{
      
  for(auto itr = --List.end(); itr!= List.begin();  --itr)
      os<<*itr<<ofc;
      os<<top()<<ofc; 
}

template<typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a){
   a.print(os);
   return os;
}

template<typename T>
bool operator== (const Stack<T>& a, const Stack <T>& b){
  Stack<T> C1=a;
  Stack<T> C2=b;
  
  if(C1.size() == C2.size()){
      for(int i=0; i != C1.size() ; ++i){
       if(C1.top() == C2.top()){
	 C1.pop(); C2.pop();
	return true;
      }

       else
	 return false; 
      }

  }
  return false;
 
}

template<typename T>
bool operator!= (const Stack<T>& a, const Stack <T>& b){
  return (!(a==b));
  
}

template<typename T>
bool operator<= (const Stack<T>& a, const Stack <T>& b){
  Stack<T> C1=a;
  Stack<T> C2=b;
  for(int i =0; i != C1.size(); ++i){
      if(C1.top() <= C2.top()){
	C1.pop();
        C2.pop(); 
	return true;
      }
      else
	return false; 
  }

  return false;
}
