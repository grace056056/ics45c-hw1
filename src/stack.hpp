//stack.hpp
#include <iostream>
#include <string>

constexpr int STK_MAX = 1000;

class Stack{
	int _top;
	char buf[STK_MAX];

public:
	//construct this Stack
	Stack(){
		_top=0;
	}

	//add c to the top of this Stack
	void push(char c){
		if(!isFull()){
			buf[_top] =c;
			++_top;
		}
	}	
	
	//removes and returns the top character of this Stack
	char pop(){
		if(isEmpty()){
			return '@';
		}
		--_top;
		return buf[_top];
	}

	//peeks at the top char and returns it without removing it
	char top(){
		if (isEmpty()){
			return '@';
		}
		return buf[_top-1];
	}

	//returns true iff this Stack is empty
	bool isEmpty(){
		return _top == 0;
	}

	//returns true iff this Stack is full
	bool isFull(){
		return _top == STK_MAX;
	}
};

void push_all(Stack& stk, std::string line){
	for (char c: line){
	stk.push(c);
	}
}

void pop_all(Stack& stk){
	while (!stk.isEmpty()){
		std::cout<<stk.pop();
	}
	std::cout<<'\n';
}
		
