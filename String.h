#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
	char* content;
public:
	String() {
		content = NULL;
	}
	String(char* src) {
		if (src != NULL) {
			content = new char[strlen(src) + 1];
			strcpy_s(content, strlen(src) + 1, src);
		}
		else content = NULL;
	}
	String(const String& src) {
		content = new char[strlen(src.content) + 1];
		strcpy_s(content, strlen(src.content) + 1, src.content);
	}
	~String() {
		delete[] this->content;
	}
	String& operator=(const String& src) {
		if (this != &src) {
			delete[] this->content;
			content = new char[strlen(src.content) + 1];
			strcpy_s(content, strlen(src.content) + 1, src.content);
		}
		return *this;
	}
	/*String& operator=(const char* src) {
		delete[] this->content;
		content = new char[strlen(src) + 1];
		strcpy_s(content, strlen(src) + 1, content);
		
		return *this;
	}*/
	friend  ostream& operator<<(ostream& out, const String & other) {

		if (other.content) {
			out << other.content;
		}
		return out;
	}
	bool operator==(const String& src) {
		if (strcmp(content, src.content) == 0) {
			return true;
		}
	}
	bool operator!=(const String& src) const {
		if (src.content == NULL) return false;
		for (int i = 0; i < strlen(src.content); i++) {
			if (content[i] != src.content[i]) return false;
		}
		return true;
	}
	
	String& operator+=(const String& src) {
		char* helper = new char[strlen(content) + strlen(src.content) + 1];
		strcpy_s(helper, strlen(content) + 1, content);
		//strcat_s(helper, strlen(src.content) + 1, src.content);
		int h = 0;
		for (int i = strlen(helper); i < strlen(helper) + strlen(src.content); i++) {
			helper[i] = src.content[h];
			h++;
		}
		helper[strlen(content) + strlen(src.content)] = '\0';
		
		delete[] this->content;
		content = helper;
		return *this;
	}
	/*String& operator+=(const char* src) {
		char* helper = new char[strlen(content) + strlen(src) + 1];
		strcpy_s(helper, strlen(content) + 1, content);
		int h = strlen(helper);
		for (int i = 0; src[i] != '\0'; i++) {
			helper[h] = src[i];
			h++;
		}
		helper[strlen(helper)] = '\0';

		delete[] this->content;
		content = helper;
		return *this;
	}*/
	const char* c_str() {
		return content;
	}
};
