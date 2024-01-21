#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
using namespace std;

class Object {
	private:
		char type;
	public:
		Object();
		Object(char type);
		~Object();
		char getType() const;
		void setType(char type);
		friend ostream& operator<<(ostream& out, const Object& o);
};

#endif /* OBJECT_H_ */
