#include <iostream>
#include <stack>

int Reverse_Polish_notation(std::string str) {
        std::stack<int> stack;

        for (int i = 0; i < str.length(); i++) {
                if (str[i] >= '0' && str[i] <= '9') {
                        stack.push(str[i] - '0');
                } else {
                        int a = stack.top(); stack.pop();
                        int b = stack.top(); stack.pop();

                        switch(str[i]) {
                                case '+': stack.push(b + a); break;
                                case '*': stack.push(b * a); break;
                                case '-': stack.push(b - a); break;
                                case '/': stack.push(b / a); break;
                                case '%': stack.push(b % a); break;
                        }
                }

        }
        return stack.top();
}


int main(){
    std::string str;
    std::getline(std::cin, str);
    std::cout << Reverse_Polish_notation(str) << std::endl;
    return 0;
}