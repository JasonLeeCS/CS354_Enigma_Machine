/**
 * Jason Lee (jlee967@wisc.edu)
 * 908 223 8909
 * 
 **/
#include "enigma.h"

const char *ROTOR_CONSTANTS[] = 
{
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // Identity Rotor (index 0 - and useful for testing):
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",
        "VZBRGITYUPSDNHLXAWMJQOFECK",
        "JPGVOUMFYQBENHZRDKASXLICTW",
        "NZJHGRCXMYSWBOUFAIVLPEKQDT",
        "FKQHTLXOCBJSPDZRAMEWNIUYGV",
};

// This function prints out the encryption rotor
// Used for testing purposes only
void printER(char encryption_rotors[4][27])
{
    printf("\n PRINTING ER \n");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 27; j++)
        {
            printf("%c",encryption_rotors[i][j]);
        }
        printf(" end\n");
    }
    printf("FINISHED PRINTING \n");
}

// This method reads a character string from the keyboard and 
// stores the string in the parameter msg.
// Keyboard input will be entirely uppercase and spaces followed by 
// the enter key.  
// The string msg should contain only uppercase letters spaces and 
// terminated by the '\0' character
// Do not include the \n entered from the keyboard
void Get_Message(char msg[])
{
    scanf("%[^\n]", msg);
    // printf("%s", msg);

    //printf("C is the worst language ever");
    //return;
}

// This function reads up to 4 characters from the keyboard
// These characters will be only digits 1 through 4. The user
// will press enter when finished entering the digits.
// The rotor string filled in by the function should only contain 
// the digits terminated by the '\0' character. Do not include
// the \n entered by the user. 
// The function returns the number of active rotors.
int Get_Which_Rotors(char which_rotors[])
{
    scanf(" %[^\n]", which_rotors);
    // printf("%s\n", which_rotors);

    // printf("%lu", strlen(which_rotors));
    return (int) strlen(which_rotors);

    //return 0;
} 

// This function reads an integer from the keyboard and returns it 
// This number represents the number of rotations to apply to the 
// encryption rotors.  The input will be between 0 and 25 inclusive
int Get_Rotations()
{
    int numRotations = 0;

    scanf("%i", &numRotations);
    // printf("%i\n", numRotations);

    return numRotations;
}


// This function copies the rotors indicated in the which_rotors string 
// into the encryption_rotors.  For example if which rotors contains the string 
// {'3', '1', '\0'} Then this function copies the third and first rotors into the 
// encryption rotors array in positions 0 and 1.  
// encryptions_rotors[0] = "BDFHJLCPRTXVZNYEIWGAKMUSQO"
// encryptions_rotors[1] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
void Set_Up_Rotors(char encryption_rotors[4][27], char which_rotors[5])
{
    // printf("This is set up rotors");
    int i = 0;
    for( ; i < strlen(which_rotors); i++)
    {
        for(int j = 0; j < 27; j++)
        {
            encryption_rotors[i][j] = ROTOR_CONSTANTS[(int) which_rotors[i] - '0'][j];
            //printf("\ner[%i][%i]: %c",i,j, encryption_rotors[i][j]);
        }
    }
    for( ; i < 4; i++)
    {
        for(int j = 0; j < 27; j++)
        {
            encryption_rotors[i][j] = ' ';
        }
    }
    //printf("this is end of set up rotors");
}


// This function rotates the characters in each of the active encryption rotors
// to the right by rotations.  For example if rotations is 3 encryption_rotors[0]
// contains "BDFHJLCPRTXVZNYEIWGAKMUSQO" then after rotation this row will contain
// SQOBDFHJLCPRTXVZNYEIWGAKMU.  Apply the same rotation to all for strings in 
// encryption_rotors
void Apply_Rotation(int rotations, char encryption_rotors[4][27])
{
    //printf("this is apply rotors");
    char temp[27];
    temp[26] = '\0';
    int count = 0;
    int condition = 1;

    while(count < 4) // Iterates through number of rows
    {
        for(int i = 0; i < 26; i++) // Iterates through each character in the row
        {

            temp[i] = encryption_rotors[count][(i - rotations + 26) % 26];
            //printf("\ntemp[%i]: %c",i,temp[i]);
            
            if(encryption_rotors[count][i] == ' ')
            {
                condition = 0;
                break;
            }
        }
        for(int j = 0; j < 27; j++) // Iterates through each character in the row
        {

            encryption_rotors[count][j] = temp[j];

            if(condition == 0)
            {
                break;
            }         
        }

        count++;

        if(condition == 0)
        {
            break;
        }
        //printER(encryption_rotors);
    }
    //printf("this is end of apply rotations");
}

// This function takes a string msg and applys the enigma machine to encrypt the message
// The encrypted message is stored in the string encrypted_msg 
// Do not change spaces, make sure your encrypted_msg is a \0 terminated string
void Encrypt(char encryption_rotors[4][27], int num_active_rotors, char msg[], char encrypted_msg[])
{
    char currLetter = ' ';
    for(int iWantToDie = 0; iWantToDie < 80; iWantToDie++)
    {
        encrypted_msg[iWantToDie] = '\0';
    }
    for(int i = 0; i < strlen(msg); i++)
    {
        if(msg[i] == ' ')
        {
            encrypted_msg[i] = msg[i];
            continue;
        }
        currLetter = msg[i];

        for(int j = 0; j < num_active_rotors; j++)
        {
            currLetter = encryption_rotors[j][(int) currLetter - 'A'];
            //printf("%c\n", currLetter);
        }
        encrypted_msg[i] = currLetter;
        //printf("%c\n", encrypted_msg[i]);

    }
}

int pleaseMakeItStopIDontWantToDoThisAnymorePleaseSendHelp(char encryption_rotors[4][27], int activeRotor, char pleaseNoMore)
{
    for(int i = 0; i < 26; i++)
    {
        if(encryption_rotors[activeRotor - 1][i] == pleaseNoMore)
        {
            //printf("\nhere: %i", i);
            return i;
        }
    }
    return -1;
}

// This function takes a string msg and applys the enigma machine to decrypt the message
// The encrypted message is stored in the string encryped_msg and the decrypted_message 
// is returned as a call by reference variable
// remember the encryption rotors must be used in the reverse order to decrypt a message
// Do not change spaces, make sure your decrytped_msg is a \0 terminated string
void Decrypt(char encryption_rotors[4][27], int num_active_rotors, char encrypted_msg[], char decrypted_msg[]) 
{
    char currLetter = ' ';
    for(int iWantToDie = 0; iWantToDie < 80; iWantToDie++)
    {
        decrypted_msg[iWantToDie] = '\0';
    }
    for(int i = 0; i < strlen(encrypted_msg); i++)
    {
        if(encrypted_msg[i] == ' ')
        {
            decrypted_msg[i] = encrypted_msg[i];
            continue;
        }
        currLetter = encrypted_msg[i];

        for(int j = num_active_rotors; j > 0; j--)
        {
            currLetter = ROTOR_CONSTANTS[0][pleaseMakeItStopIDontWantToDoThisAnymorePleaseSendHelp(encryption_rotors, j, currLetter)];
            //printf("i:%i j:%i %c\n",i , j, currLetter);
        }
        decrypted_msg[i] = currLetter;
        //printf("%c\n", decrypted_msg[i]);
    }
    return;
}

//c programming makes me want to die
