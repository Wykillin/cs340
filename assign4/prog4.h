#ifndef prog4_h
#define prog4_h
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <map>
#include <locale>
const int NO_ITEMS = 3;
const int ITEM_W = 16;
void get_words(std::map<std::string, int>&);
void print_words(const std::map<std::string, int>&);
void clean_entry(const std::string&, std::string&);
#endif

