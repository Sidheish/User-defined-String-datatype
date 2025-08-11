#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

class String {
	char *p;

	public:
	String();                          // Default constructor
	String(const char*);               // Parameterized constructor
	String(const String &);            // Copy constructor
	~String();                         // Destructor

	String& operator=(String &); // Assignment operator
	String operator+(String &);  // + operator
	char& operator[](int);             // [] operator

	int length();                      // Length
	void get_string();
	friend ostream& operator<<(ostream &,  String &); // << operator
	friend istream& operator>>(istream &, String &);       // >> operator

	friend void my_strcpy(String&, String);
	friend void my_strncpy(String&, String, int);
	friend int my_strcmp( String &, String);
	friend int my_strncmp(String &, String, int);
	friend int my_strlen(String &);
	friend String my_strstr(String &, char *);
	friend String my_strchr(String &, char);
	friend String my_strrchr(String &, char );
	friend void my_strrev(String&);
	friend void my_strlower(String&);
	friend void my_strupper(String&);
	friend void my_strtoggle(String&);
	friend String my_strcat(String& , String);
	friend String my_strncat(String&, String, int);

};

#endif

