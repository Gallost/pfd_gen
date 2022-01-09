#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

char lower_to_cap[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

char cap_to_lower[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

int main (int argc, char* argv[]) {
    if (argc != 1) {
        printf("Usage: ./pfdgen\n");
        return -1;
    }
    srand(time(NULL));

    while (1) {
        printf("Input string, 0 to quit: ");
        char str_to_convert[MAX_SIZE];
        scanf("%[^\n]%*c", str_to_convert);

        if (str_to_convert[0] == '0') {
            break;
        }

        int len = strlen(str_to_convert);

        for (int i = 0; i < len; i++) {
            int flag = rand()%2;

            int c = (int)(str_to_convert[i]);
            if (flag == 0) {    // lowercase
                if (c >= 65 && c <= 90) {
                    str_to_convert[i] = cap_to_lower[c - 65];
                }
            }
            else {              // uppercase
                if (c >= 97 && c <= 122) {
                    str_to_convert[i] = lower_to_cap[c - 97];
                }
            }
        }

        printf("%s\n", str_to_convert);
    }

    return 0;
}