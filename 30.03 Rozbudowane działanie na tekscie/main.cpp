#include <iostream>
#include <cstring>



void toHigh(char *text) {
    while(*text) {
        if ('a' <= *text && *text <= 'z') {
            *text += ('A' - 'a');
        }
        text++;
    }
}

void toLow(char *text) {
    while(*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}

int textSize(const char *text) {
    int size = 0;
    while(*(text + size)){
        size++;
    }
    return size;
}

void usage(char *programName) {
    printf("Usage: %s operation \"text to process\"\n", programName);
    printf("Available operations:\n");
    printf("\tupper\n");
    printf("\tlower\n");
    printf("\tsize\n");
    printf("\tall\n");
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }


    char text[100];

    strncpy(text, argv[2], 99);
    text[99] = '\0';


    if (!strcmp("upper", argv[1])) {
        toHigh(text);
        printf("%s\n", text);
        return 0;
    }

    if (!strcmp("lower", argv[1])) {
        toLow(text);
        printf("%s\n", text);
        return 0;
    }

    if (!strcmp("size", argv[1])) {
        printf("%d\n", textSize(text));
        return 0;
    }

    if (!strcmp("all", argv[1])) {

        printf("Oryginal: %s\n", text);
        toHigh(text);
        printf("Wielkie: %s\n", text);
        toLow(text);
        printf("Male: %s\n", text);
        printf("Rozmiar: %d\n", textSize(argv[2]));
        return 0;
    }