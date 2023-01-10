#include <string.h>  // for some reason, leetcode submission detects lower runtime with line

char stack[10000] = {'0'};
int stackMax = 10000;
int sp = 0;

void push(char c) {
    if(sp < stackMax) {
        stack[sp] = c;
        sp++;
    }
    else {
        printf("stack full\n");
    }
}

void pop() {
    if(sp > 0) {
        sp--;
    }
    else {
        printf("stack empty\n");
    }
}

char peek() {
    if(sp > 0 && sp < stackMax) {
        return(stack[sp-1]);
    }
    else {
        printf("cant peek\n");
        return('n');
    }
}

void printStack() {
    int i = 0;
    while(i<sp) {
        printf("i:%d---%c\n",i,stack[i]);
        i++;
    }
}

bool isValid(char * s){
    sp = 0;     // needed for some reason
    int i = 0;
    while(s[i] != '\0') {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
        }
        else if(s[i] == ')') {
            if(peek() != '(') {
                return(false);
            }
            else {
                pop();
            }
        }
        else if(s[i] == ']') {
            if(peek() != '[') {
                return(false);
            }
            else {
                pop();
            }
        }
        else if(s[i] == '}') {
            if(peek() != '{') {
                return(false);
            }
            else {
                pop();
            }
        }
        i++;
    }

    if(peek() == '(' || peek() == '[' || peek() == '{') {
       return(false);
    }
    return(true);
}