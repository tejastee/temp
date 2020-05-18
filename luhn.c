#include <stdio.h>
#include <math.h>


int check_card(long int card_number)
{
    long int temp = card_number;
    int counter = 0, first_seq = 0, sec_seq = 0, i = 0;

    while (temp > 0)
    {
        i = temp % 10;
        if (counter == 0)
        {
            first_seq += i;
            counter = 1;
        }
        else if (counter == 1)
        {
            i = i * 2;
            while (i > 0)
            {
                sec_seq += i % 10;
                i = i / 10;
            }
            counter = 0;
        }
        temp = temp / 10;
    }
    if ((first_seq + sec_seq) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_length(long int number)
{
    int len = 0;
    while (number > 0)
    {
        len += 1;
        number = number / 10;
    }
    return len;
}

char* get_card_type(long int card_number)
{
    int length = get_length(card_number);
    int starting_numbers = 0;
    if (length == 15)
    {
        starting_numbers = (int)(card_number / pow(10, length-2));
        if (starting_numbers == 34 | starting_numbers == 37)
            return ("AMEX\n");
    }
    else if (length == 16)
    {
        starting_numbers = (int)(card_number / pow(10, length-2));
        if (starting_numbers >= 51 && starting_numbers <= 55){
            return "MASTERCARD\n";
        }
        starting_numbers = (int)(card_number / pow(10, length-1));
        printf("%d , %d", length, starting_numbers);
        if (starting_numbers == 4){
            return "VISA\n";
        }
    }
    else if (length == 13){

        starting_numbers = (int)(card_number / pow(10, length-1));
        printf("%d , %d", length, starting_numbers);
        if (starting_numbers == 4){
            return "VISA\n";
        }
    }
    printf("%d",length);
    printf("Check Type Failed");
    return "INVALID\n";
}

int main(void)
{
    long int card_number;

    printf("Number :");
    scanf("%ld", &card_number);

    if (check_card(card_number) == 1)
    {
        printf("%s", get_card_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}