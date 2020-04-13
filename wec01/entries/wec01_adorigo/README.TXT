this program works both to translate from morse to human and from human to morse
to execute the program do as follow :
./morsec "<YOUR MORSE HERE>"
or :
./morsec -r "<YOUR TEXT HERE>"

it is possible to modify the dictionary, to do so modify the dictionary.txt file like this :

[CHAR] [MORSE CODE]

there needs to be at least one space between the letter and the morse code, but more spaces is acceptable
ALSO there can only be one character before the space sparating the characters and morse code

the -r does not return errors in case you feed it a character that is not a dictionary, it will skip it as if it weren't there


ps : there is a norme error in the morsec.c file, it is a bug from the norminette that was confirmed by the paris bocal, there are no indentation problems, just ugly code
pps: I also didn't have the time to fix the errors given to me by valgrind for the bonus, and the leaks sorry :(
