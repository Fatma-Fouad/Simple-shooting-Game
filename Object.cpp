#include "Object.hpp"
#include <iostream>
using namespace std;

Object::Object(){
	type = 'O';
}

Object::Object(char type){
	this->type = type;
}

char Object::getType() const {
	return type;
}

void Object::setType(char type) {
	this->type = type;
}

Object::~Object() {
}

ostream& operator<<(ostream& out, const Object& o){
	out << o.type << endl;
	return out;
}
