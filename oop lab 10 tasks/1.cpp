// Task 1:
// Consider a String entered by the user which he wants to encrypt and then decrypt the
// information. Perform this functionality via the filling technique by first inserting the
// encrypted text in the outfile then read the encrypted text to decode it back to string.
// Input:
// Enter String = Hello World
// Output:
// Normal Text:= Hello World
// Encrypted text inserted in outfile
// Igopt&amp;amp;^w{vo
// Decrypted text Read then decoded from outfile
// Hello World
// (Note: For Encryption the algorithm would be is to take the length of the string then add
// the
// Number based on the index position of the character of the string when inserting into
// the outfile)
// Example:
// ABC = Here A is at position 1 B is at position 2 and c is at position 3 if we add these
// position values to their ascii code then the ascii values becomeOriginal values = 65 66
// 67; modified = 66 68 70 which converts the text to B D F
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream outfile;
    string sentence;
    int count = 1;
    cout << "Enter string: ";
    getline(cin, sentence);
    string encrypted = sentence;
    for (int i = 0; i < encrypted.size(); i++)
    {
        encrypted[i] += count;
        count++;
    }
    outfile.open("data.txt", ios::app);
    if (!outfile)
    {
        cerr << "Unable to open outfile";
        return 1;
    }
    outfile << encrypted << endl;
    ifstream infile;
    string line;
    count = 1;
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            encrypted = line;
        }
    }
    for (int i = 0; i < encrypted.size(); i++)
    {
        encrypted[i] -= count;
        count++;
    }
    sentence = encrypted;
    cout << "Decrypted sentence: " << sentence;
    outfile.close();
    infile.close();
}
