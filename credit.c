// progrme to check the validity of a credit card

#include<cs50.h>
#include<stdio.h>
#include<math.h>


int check_size(long cnum)
{
    int count;
    
    for (count = 0; cnum != 0; cnum /= 10)
    {
        ++ count;
    }

    return count;
}

bool check_valid(long cnum, int csize)
{
    if (cnum > 0)
    {
        //checking the size of card numbers
        if (csize >= 13 || csize <= 16)
        {
            int evensum = 0;
            int oddsum = 0;
            
            while (cnum)
            {
                int rem;
                // extracting odd position number .
                rem = cnum % 10;
                oddsum += rem;
                
                // updating cnum
                cnum /= 10;
                
                // extracing even position number
                rem = cnum % 10;
                rem *= 2;
                evensum += ((rem / 10) + (rem % 10));
                
                // updating cnum
                cnum /= 10;
            }

            // if remainder is not 0        
            if ((evensum + oddsum) % 10)  
            {
                return false;
            }
            // if remainder is 0
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void card_brand(long cnum, int csize)
{
    int startingdigits = cnum / (long)(pow(10, csize - 2));

    // checks for American Express 
    if ((csize == 15) && (startingdigits == 34 || startingdigits == 37))
    {
        printf("AMEX\n");
    }
    
    // checks for MASTERCARD
    else if ((csize == 16) && (startingdigits >= 51 && startingdigits <= 55))
    {
        printf("MASTERCARD\n");
    }
    
    // checks for VISA
    else if ((csize == 16 || csize == 13) && ((startingdigits / 10) == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main()
{
    unsigned long cardno ;
    cardno  = get_long("Number  :\t");
    
    int card_size = check_size(cardno);

    if (check_valid(cardno, card_size))
    {
        card_brand(cardno, card_size);
    }
    else
    {
        printf("INVALID\n");
    }
}