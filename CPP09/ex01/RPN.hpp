#pragma once
#include <iostream>
#include <stack>

int is_operator(char a);
void start(std::stack<int> &stack, std::string input);
void operation(std::stack<int> &stack, char op);