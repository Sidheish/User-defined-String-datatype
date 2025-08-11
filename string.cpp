#include <cstring>
#include "header.h"

String::String() {
	cout<<"Default constructor"<<endl;
	p = new char[1];
	p[0] = '\0';
}

String::String(const char* s) {
	cout<<"Parameterized constructor"<<endl;
	p = new char[strlen(s) + 1];
	strcpy(p, s);
}

String::String(const String &temp) {
	cout<<"Copy constructor"<<endl;
	p = new char[strlen(temp.p) + 1];
	strcpy(p, temp.p);
}

String::~String() {
	cout<<"Destructor"<<endl;
	delete[] p;
}

String& String::operator=(String &t) {
	cout<<"= Operator overloaded"<<endl;
	p = new char[strlen(t.p) + 1];
	strcpy(p, t.p);

	return *this;
}

String String::operator+(String &t) {
	cout<<"+ operator overloaded"<<endl;
	char *temp = new char[strlen(p) + strlen(t.p) + 1];
	strcpy(temp, p);
	strcat(temp, t.p);
	String result(temp);
	delete[] temp;
	return result;
}

char& String::operator[](int i) {
	return p[i];
}

int String::length() {
	return strlen(p);
}
void String::get_string(){
	cout<<p<<endl;
}

