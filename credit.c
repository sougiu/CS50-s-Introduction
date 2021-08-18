// To run this code, go to: https://sandbox.cs50.io/ to get access of all libraries used.

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for a credit card number
    long creditCard = get_long("Number: ");

    // Determine if credit card number is syntactically valid
    long test = creditCard;
    long total = 0;

    do
    {
        // Total sum with every other digit, starting with the number’s first-to-last
        total = total + (test % 10);
        test = test / 10;

        // Multiplies interleaved digits by two, starting with the second-to-last
        int m = 0;

        m = (test % 10) * 2;

        // Total sum, adding the product of multiplication above
        while (m > 0)
        {
            total = total + (m % 10);
            m = m / 10;
        }
        test = test / 10;
    }
    while (test > 0);
    
    long m1amex = 340000000000000;
    long m2amex = 349999999999999;
    long m3amex = 370000000000000;
    long m4amex = 379999999999999;
    
    long m1visa = 4000000000000;
    long m2visa = 4999999999999;
    long m3visa = 4000000000000000;
    long m4visa = 4999999999999999;
    
    // Determine if credit card number belongs to a company registered in the system
    if (total % 10 == 0)
    {
        if ((creditCard >= m1amex && creditCard <= m2amex) || (creditCard >= m3amex && creditCard <= m4amex))
        {
            printf("AMEX\n");
        }
        else if (creditCard >= 5100000000000000 && creditCard <= 5599999999999999)
        {
            printf("MASTERCARD\n");
        }
        else if ((creditCard >= m1visa && creditCard <= m2visa) || (creditCard >= m3visa && creditCard <= m4visa))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}