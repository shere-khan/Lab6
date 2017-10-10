//Header

#include <stdio.h>
#include <ctype.h>

//MAX is the maximum number of incorrect guesses
//WORDSIZE is the number of letters in the word
#define MAX 5
#define WORDSIZE 7

int main() {
    //the word and it's length are predetermined.  To test with a different word,
    //change the string in word and update WORDSIZE to match the length of the new word.
    char word[WORDSIZE + 1] = "COCONUT";
    int print[WORDSIZE], guesses = 0, i, letterflag, wordflag = 0;
    char guess;

    /***The "print" array is an array of flags.  Each index
    corresponds to an index in the word.  The value in the array
    specifies whether or not the corresponding letter has been
    discovered yet.  Initialize this array so that all the values
    are zero to indicate no letters have been discovered yet.***/
    for (int i = 0; i < WORDSIZE; i++)
        print[i] = 0;

    //Only incorrect guesses count against the user
    while (guesses < MAX) {
        printf("Here is the word: ");

        /***To print the word, loop through the print array.  If the
        value in the print array is zero, print an "_".  If the value
        in the print array is one, print the corresponding letter
        from the word array.***/
        for (int i = 0; i < WORDSIZE; i++) {
            if (print[i] == 1)
                printf("%c", print[i]);
            else
                printf("_");
        }
        //prompt the user for their guess
        printf("\n");

        printf("Guess a letter:\n");
        scanf(" %c", &guess);

        /*letterflag indicates whether or not the letter the
        user guessed is in the word.  It is initialized to zero
        to indicate we haven't found their guess in the word yet.
        The toupper function causes the users guess to always be
        an uppercase letter.*/
        letterflag = 0;
        guess = toupper(guess);

        /***Loop through the word and determine if guess is part of
        the word. If it is, set letterflag to 1 and the corresponding
        location in the print array to 1.***/

        for (int i = 0; i < WORDSIZE; i++) {
            if (word[i] == guess) {
                letterflag = 1;
                print[i] = 1;
            }
        }


        printf("\n");

        //If their guess is not in the word, update the number of incorrect guesses
        if (!letterflag) {
            printf("%c is not in the word.\n", guess);
            guesses++;
            printf("Only %d more incorrect guesses allowed.\n\n", MAX - guesses);
        }

        /*Check to see if the user has guessed all the letters by checking to see
        if all the letters are flagged to print.*/
        letterflag = 0;

        /***Loop through the print array.  If any flag is still zero, set
        letterflag to zero.  This will indicate there is still at least one
        undiscovered letter.***/
        for (int i = 0; i < WORDSIZE; i++) {
            if (print[i] == 0) {
                letterflag = 1;
            }
        }

        //if all the letters have been discovered, set the wordflag and
        //break out of the loop
        if (!letterflag) {
            printf("%s\n", word);
            printf("You uncovered the word!\n");
            wordflag = 1;
            break;
        }
    }

    //If the user ran out of guesses and did not determine the word, print the word
    if (!wordflag) {
        printf("Sorry, you ran out of guesses.\nThe word was %s.\n", word);
    }

    return 0;
}
