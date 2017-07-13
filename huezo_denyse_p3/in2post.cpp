//#include<stdlib.h>
#include "stack.h"  
#include<iostream> 
#include<string>
#include<ctype.h>
//#include<cstring>
//#include<sstream>
//break after errros

using namespace std;
using namespace cop4530;

int main(){
  string variable="";
  string postfix=""; 
  string expression; 
  Stack<char>op; 

  cout<<"Enter infix expression (exit to quit)"<<endl;

  while(getline(cin,expression)){
      if(expression=="exit")return 0;
    
    for(int i=0; i!=expression.size(); ++i){
      
      if(isalnum(expression[i])||expression[i]=='_'||expression[i]=='.' )//|| i== expression.size()-1)
	  variable += expression[i]; 

      if(expression[i]==' ' || i== expression.size() -1 ){ // || string.end     
	   postfix+= variable; 
	   postfix+=" ";
           variable.clear();
       }
 	if(expression[i]=='(')  //CASE (
	  op.push(expression[i]);
     
	if(expression[i]==')'){
	  while(!op.empty() && op.top()!='('){
	    postfix+=op.top();
	    op.pop(); 
	  }
	  if(op.top()!= '('){
	    cout<< "Mismatched parenthesis"<<endl;
	    return 0;
	}
	  op.pop();
	}
	if(expression[i]=='*' || expression[i]=='/'){
	  while(!op.empty() && op.top()!= '+' && op.top()!= '-' && op.top()!='('){
	    postfix+=op.top(); 
	    op.pop();
	    postfix+=" ";
	  }
	  op.push(expression[i]);       
	} 
	
	if(expression[i]=='+'||expression[i]=='-'){
	  while(!op.empty() && op.top()!= '('){
	    postfix+= op.top();
	    op.pop();
	    postfix+=" ";
	  }
	  op.push(expression[i]);
	}
    }//for 

    while(!op.empty()) {
      postfix+=op.top();
      postfix+=" ";
      op.pop();

      if(op.top()=='('){
	cout<<"Mismatched Parenthesis"<<endl;
	return 0; 
      }
	
      }
   
    int letter=0;
    for(int i=0; i!= postfix.size(); ++i){
      if(isalpha(postfix[i]))
	 letter++;
      
      //if(!isalpha(postfix[i]))
      //letter=1;
      }

    if(letter>0){ 
    cout<<"Postfix evaluation: "<<postfix<< " = " << postfix<<endl;
    }
    
 if(letter==0){
 Stack<double>rs;
 double  a=0; 
 double  b=0;
 double  x=0;
 string hold="";

for(int i=0; i!= postfix.size(); ++i){
   if(isdigit(postfix[i]) || postfix[i]=='.')
     hold+=postfix[i];
  
   if(postfix[i]==' ' && !hold.empty()){
      rs.push(stod(hold));
      hold.clear();
   }
   if(postfix[i]=='+'){
     
     /*if(rs.size() < 2){
	 cout<<"Operator Error";
	 return 0;
	 }*/
	a=rs.top();
	rs.pop();
       
	/*if(rs.size()< 2){
	 cout<<"Operator Error";
	 return 0;
	 }*/
	b=rs.top();
	rs.pop(); 
	rs.push(b+a);	
   }
   if(postfix[i]== '-'){

     /*if(rs.size() < 2){
	 cout<<"Operator Error";
	 return 0;
	 }*/
	a=rs.top();
	rs.pop();

	/*if(rs.size() < 2){
	 cout<<"Operator Error";
	 return 0;
	 }*/	      
	b= rs.top();
	rs.pop(); 
	rs.push(b-a);	
	}
   if(postfix[i]== '*'){
     
     /*if(rs.size() < 2){
	 cout<<"Operator Error";
	 return 0;
	 }*/
       
	 a=rs.top();
	 rs.pop();
	
	 /*if(rs.size() < 2){
	 cout<<"Operator Error";
	 return 0;
	 }*/
	b= rs.top();
	rs.pop(); 
	rs.push(b*a);
	} 
    if(postfix[i]== '/'){
      /*if(rs.size() < 2){
	 cout<<"Operator Error";
	 return 0;
	 }*/
	a=rs.top();
	rs.pop();

	/*if(rs.size() < 2){
	 cout<<"Operator Error";
	 return 0;
	 }*/
        b= rs.top();
	rs.pop();
	rs.push(b/a);	
   }
 }

 if(rs.size() > 1){
	 cout<<"Operand Error";
	 return 0;
	 }
 
 cout<<"Postfix evaluation: "<<postfix<<" = ";
 cout<<rs.top()<<endl;

 }  
  postfix.clear();
  expression.clear();
  cout<<"Enter infix expression (exit to quit)"<<endl;
 }  
return 0;
  
}
// end main


