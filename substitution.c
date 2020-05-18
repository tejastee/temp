    #include <stdio.h>
    #include <math.h>
    #include <string.h>

    int get_length(char text[])
    {
        return strlen(text);
    }

    int check_frequency(char text[])
    {
        int len = strlen(text), count = 0;

        for (int i = 0; i < len; i++)
        {
            if (!((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')))
            {
                printf("Not a Character!\n");
                return 0;
            }
            count = 0;
            for (int j = i; j < len; j++)
            {
                if (text[j] == text[i])
                    count++;
                if (count > 1)
                {
                    printf("Repeated!\n");
                    return 0;
                }
            }
        }
        return 1;
    }

    int conver_cipher(char key[], char text[])
    {
        printf("ciphertext:");
        int len = strlen(text), case_integer = 0, diff = 0;
        char cipher_char;

        for (int i = 0; i < len; i++)
        {
            case_integer = 0;
            printf("<%c>", text[i]);

            if (text[i] >= 'a' && text[i] <= 'z')
                case_integer = 97;
            else if (text[i] >= 'A' && text[i] <= 'Z')
                case_integer = 65;


            if (case_integer != 0)
            {
                diff = text[i] - case_integer;
                cipher_char = key[diff];
                if (!(case_integer <= cipher_char && cipher_char <= (case_integer + 25)))
                {
                    if(case_integer == 65){
                        cipher_char = cipher_char-32;
                    }
                    else
                    {
                        cipher_char = cipher_char+32;
                    }
                    
                }

                printf("%c", cipher_char);
            }
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
    }

    int main(int argc, char *argv[])
    {

        if (argc != 2)
        {
            printf("Wrong arguments passed");
            return 1;
        }

        if (strlen(argv[1]) != 26)
        {
            printf("26 Characters not present!");
            return 1;
        }

        if (check_frequency(argv[1]))
        {
            char s[100];
            printf("plaintext:");
            scanf("%s", s);
            conver_cipher(argv[1], s);
        }
        else
        {
            return 1;
        }

        return 0;
    }