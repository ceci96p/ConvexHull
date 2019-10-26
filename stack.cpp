#include "stack.h"

Point Stack::peek(){
	Point def = Point(0,0);

	if (isEmpty() == true){
		return def;

	}
	return st.back();
}

int Stack::size(){
	return st.size();
}

bool Stack::isEmpty(){
	if (st.empty() == true){
		return true;
	}
		return false;

}

void Stack::push(Point p){
	st.push_back(p);
}

Point Stack::pop(){
	Point def = Point(0,0);

	if (isEmpty() == true){
		return def; 
	}

	def = st.back();

	st.pop_back(); 

	return def; 
}