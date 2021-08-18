### CS50's Introduction to Computer Science

______________________________________________________________________________________________________

##### Week 0 | Scratch

###### Problem Set 0 - Scratch

Implement in Scratch any project, be it an  interactive story, game, animation, or anything else, subject only to  the [following requirements](https://cs50.harvard.edu/x/2021/psets/0/scratch/#scratch):

I've made a simple game: https://scratch.mit.edu/projects/554520421/



##### Week 1 | C

###### Lab 1 - Hello

The first assignment is to greet the user.

```
$ ./hello
What is your name?
Giu
Hello, Giu
```



###### Lab 1 - Population Growth

Determine how long it takes for a population to reach a particular size.

```
$ ./population
Start size: 100
End size: 200
Years: 9
```



###### Problem Set 1 - Credit

Write a program that prompts the user for a credit card number and then reports (via `printf`) whether it is a valid American Express, MasterCard, or Visa card number.

```
$ ./credit
Number: 4003600000000014
VISA
```



###### Problem Set 1 - Mario

Recreate Mario's pyramids in C, albeit in text, using hashes (`#`) for bricks. Each hash is a bit taller than it is wide,  so the pyramids themselves are also be taller than they are wide.

```
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```



##### Week 2 | Arrays

###### Lab 2 - Scrabble

Complete the implementation of `scrabble.c`, such that it determines the winner of a short scrabble-like game, where two players each enter their word, and the higher scoring player wins.

```
$ ./scrabble
Player 1: Oh,
Player 2: hai!
Player 2 wins!
```



###### Problem Set 2 - Readability

Implement a program that computes the approximate grade level needed to comprehend some text, according to [specifications]( https://cs50.harvard.edu/x/2021/psets/2/readability/#specification]).

```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```



###### Problem Set 2 - Substitution

Implement a program that implements a substitution cipher, according to [specifications](https://cs50.harvard.edu/x/2021/psets/2/substitution/#specification).

```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```

##### 

##### Week 3 | Algorithms

###### Lab 3 - Sort

Analyze three sorting programs to determine which algorithms they use.



###### Problem Set 3 - Plurality

Implement a program that runs a plurality election, according to [specifications](https://cs50.harvard.edu/x/2021/psets/3/plurality/#specification).

```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```



###### Problem Set 3 - Runoff

Implement a program that runs a runoff election, according to [specifications](https://cs50.harvard.edu/x/2021/psets/3/runoff/#specification).

```
./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```



##### Week 4 | Memory

###### Lab 4 - Volume

Write a program to modify the volume of an audio file, according to [implementation details](https://cs50.harvard.edu/x/2021/labs/4/#implementation-details).

```
$ ./volume input.wav output.wav 2.0
```



###### Problem Set 4 - Filter

Implement a program that applies filters to BMPs, according to [specifications](https://cs50.harvard.edu/x/2021/psets/4/filter/more/#specification).

```
$ ./filter -g infile.bmp outfile.bmp

$ ./filter -r infile.bmp outfile.bmp

$ ./filter -b infile.bmp outfile.bmp

$ ./filter -e infile.bmp outfile.bmp
```



###### Problem Set 4 - Recover

Implement a program that recovers JPEGs from a forensic image, according to [specifications]([Specification](https://cs50.harvard.edu/x/2021/psets/4/recover/#specification)).

```
$ ./recover card.raw
```

