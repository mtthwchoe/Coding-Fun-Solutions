bool isValid(char * s){

    int iter = 0;
    bool paren = false;
    bool curly = false;
    bool square = false;

    while (s[iter] != '\0') {
        if(s[iter] == '(') {
            paren = true;
        }
        else if(s[iter] == '[') {
            square = true;
        }
        else if(s[iter] == '{') {
            curly = true;
        }
        else if(s[iter] == ')' && paren == false) {
            return(false);
        }
        else if(s[iter] == ')' && paren == true) {
            paren = false;
            if(square == true || curly == true) {
                return(false);
            }
        }
        else if(s[iter] == ']' && square == false) {
            return(false);
        }
        else if(s[iter] == ']' && square == true) {
            square = false;
            if(paren == true || curly == true) {
                return(false);
            }
        }
        else if(s[iter] == '}' && curly == false) {
            return(false);
        }
        else if(s[iter] == '}' && curly == true) {
            curly = false;
            if(square == true || paren == true) {
                return(false);
            }
        }
        else if(paren == true && (s[iter] == ']' || s[iter] == '}')) {
            return(false);
        }
        else if(square == true && (s[iter] == ')' || s[iter] == '}')) {
            return(false);
        }
        else if(curly == true && (s[iter] == ')' || s[iter] == ']')) {
            return(false);
        }

        iter++;
    }

    if(paren == true || square == true || curly == true) {
        return(false);
    }

    return(true);

}