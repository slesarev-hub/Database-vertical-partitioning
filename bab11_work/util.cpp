#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "util.hpp"

using namespace std;

vector<string> split(string str, char delim){
    istringstream ss(str);
    vector<string> result;
    string element;

    while(getline(ss, element, delim))
        result.push_back(element);

    return result;
}

string join(vector<string> strings, string delim){
    if(strings.size() == 0) return "";

    string result;
    size_t len = 0;
    for(string s : strings) len += s.size();
    len += delim.size() * (strings.size() - 1);
    result = strings[0];
    result.reserve(len);
    for(int i = 1; i < strings.size(); ++i)
        result += delim + strings[i];
    return result;
}

int replaceAll(string& str, string sub_old, string sub_new){
     if(sub_old == sub_new) return 0;
     size_t old_len = sub_old.size();
     size_t pos = str.find(sub_old, 0);
     int replaces = 0;
     while(pos != string::npos){
         str.replace(pos, old_len, sub_new);
         ++replaces;
         pos = str.find(sub_old, pos);
     }
     return replaces;
}

int find_not_quoted(string& str, string substr, int pos){
    // only single quotes are expected
    // substr will be short, so no fancy algorithms
    // pos is expected to be a result of a previous call
    bool quoted = false;
    int counter = 0;
    int subquery_brace = -1;
    for(int i = pos; i < str.size(); ++i){
        if(str[i] == '\\') ++i;
        else if(str[i] == '\'') quoted = !quoted;
        else if(!quoted && str[i] == '('){
            ++counter;
            do ++i;
            while(str[i] == ' ');
            if(subquery_brace == -1 && str.substr(i, 6) == "select"){
                subquery_brace = counter;
            } else --i;
        } else if(!quoted && str[i] == ')'){
            if(counter-- == subquery_brace){
                subquery_brace = -1;
            }
        }
        else if(!quoted && subquery_brace == -1){
            bool found = true;
            for(int j = 0; j < substr.size(); ++j)
                if(tolower(str[i+j]) != tolower(substr[j])){
                    found = false;
                    break;
                }
            if(found) return i;
        }
    }
    return str.size();
}

int replace_not_quoted(string& str, string one, string another){
    int pos = -1;
    int count = 0;
    while(1){
        pos = find_not_quoted(str, one, pos+1);
        if(pos == str.size()) return count;
        str.replace(pos, one.size(), another);
        pos += another.size() - one.size();
        ++count;
    }
}