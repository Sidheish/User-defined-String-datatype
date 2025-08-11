#include<cstring>
#include"header.h"
using namespace std;
ostream& operator<<(ostream &out, String &str) {
	out << str.p;
	return out;
}

istream& operator>>(istream &in, String &str) {
	char temp[1000];
	in >> temp;
	delete[] str.p;
	str.p = new char[strlen(temp) + 1];
	std::strcpy(str.p, temp);
	return in;
}
void my_strcpy(String &s1, String s2){
	int i;
	delete[] s1.p;
	s1.p = new char[strlen(s2.p)+1];
	//strcpy(s1.p, s2.p);
	for(i = 0; s2.p[i] ; i++)
		s1.p[i] = s2.p[i];
	s1.p[i] = '\0';
	cout<<"String is copied successfully"<<endl;
}

void my_strncpy(String &s1, String s2, int n){
	delete[] s1.p;
	s1.p = new char[strlen(s2.p)+1];
	int i,len;
	for(len = 0; s2.p[len]; len++);
	for(i = 0; i<n; i++)
		s1.p[i] = s2.p[i];
	s1.p[i] = '\0';
}

int my_strcmp(String &s1, String s2){
	int i=0;
	while(s1.p[i] && s2.p[i]){
		if(s1.p[i]!=s2.p[i])
			return s1.p[i]-s2.p[i];
		i++;
	}
	return s1.p[i]-s2.p[i];
}
int my_strncmp(String &s1, String s2, int n){
	int i=0;
	while(s1.p[i]&&s2.p[i] && i<n){
		if(s1.p[i]!=s2.p[i])
			return s1.p[i] - s2.p[i];
		i++;
	}
	if(i == n)
		return 0;

	return s1.p[i] - s2.p[i];

}
int my_strlen(String& s1){
	int len;
	for(len=0; s1.p[len]; len++);
	return len;
}

String my_strstr(String &s1, char *sub) {
	int i, j;
	for (i = 0; s1.p[i]; i++) {
		if(s1.p[i] == sub[0]){
			for (j = 1; sub[j]; j++) {
				if (s1.p[i + j] != sub[j])
					break;
			}
			if (sub[j] == '\0') {
				String result;
				int len = strlen(s1.p + i);
				result.p = new char[len + 1];
				strcpy(result.p, s1.p + i);
				return result;
			}
		}
	}

	String empty;
	empty.p = new char[1];
	empty.p[0] = '\0';
	return empty;
}

String my_strchr(String &s1, char ch){
int i;
for(i=0; s1.p[i]; i++){
	if(s1.p[i] == ch)
	return &s1.p[i];
}
return String("");

}

String my_strrchr(String& s1, char ch){
int i;
//int len;
//for(len = 0; s1.p[len]; len++);
int len = s1.length();
for(i=len-1; i>=0; i--){
if(s1.p[i] == ch)
return &s1.p[i];

}
return String("");


}

void my_strrev(String &s1){
int i,j,len;
char t;
//for(len=0; s1.p[len]; len++);
len = s1.length();

for(i=0, j = len-1; i<j; i++,j--){
t = s1.p[i];
s1.p[i]= s1.p[j];
s1.p[j] = t;

}


}
void my_strlower(String &s1){
int i;
for(i=0; s1.p[i]; i++){
if(s1.p[i]>='A' && s1.p[i]<='Z')
s1.p[i]= s1.p[i]+32;
}



}

void my_strupper(String &s1){
int i;
for(i=0; s1.p[i]; i++){
if(s1.p[i]>='a' && s1.p[i]<='z')
s1.p[i]= s1.p[i]-32;
}
}

void my_strtoggle(String& s1){
int i;
for(i=0; s1.p[i]; i++){
if(s1.p[i]>='a' && s1.p[i]<='z')
s1.p[i] = s1.p[i]-32;
else if(s1.p[i]>='A' && s1.p[i]<='Z')
s1.p[i]= s1.p[i]+32;

}


}
String my_strcat(String& s1, String s2){
int len1 = s1.length();
int len2 = s2.length();
int i;
char *t = new char[len1 + len2+1];

for(i=0; i<len1; i++)
t[i] =s1[i];

for(i=0; i<len2; i++)
t[len1+i] = s2[i];

t[len1+len2] = '\0';
String ret(t);
delete[] t;	// delete temp buffer
return ret;
}

String my_strncat(String& s1, String s2, int n){
int len1 = s1.length();
int len2 = s2.length();
int i;
char *t = new char[len1 + len2+1];

if(n>len2)
n = len2;

for(i=0; i<len1; i++)
t[i] =s1[i];

for(i=0; i<n; i++)
t[len1+i] = s2[i];

t[len1+n] = '\0';
String ret(t);
delete[] t;	// delete temp buffer
return ret;
}
