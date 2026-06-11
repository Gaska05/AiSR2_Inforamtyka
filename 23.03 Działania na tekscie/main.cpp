#include <iostream>

void toHigh(char *text){
    while(*text) {
        if ('a' <= *text && *text <= 'z') {
            *text += ('A' - 'a');
        }
        text++;
    }
}
void toLow(char *text){
    while(*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}
int textSize(const char *text){
    int size = 0;
    while(*(text + size)){
        size++;
    }
    return size;
}

int main() {
    char text[100];
    do {
        fgets(text,100, stdin);
        text[textSize(text) - 1 ] = 0;
        if(!text[0]){
            return 0;
        }
        printf("%s\n", text);
        toHigh(text);
        printf("%s\n", text);
        toLow(text);
        printf("%s\n", text);
        printf("%d\n", textSize(text));
    }while(true);
    return 0;

}
