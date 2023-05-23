# INTERVIEW GAME


## Overview

Game called **INSTANCES WAR** created for interview.

Due to the lack of an insufficient amount of free time (studies, work) I was unable to implement the game exactly as 
it is presented in the instructions.

<br/>


I am aware that the game still needs a lot of refinement.

I hope that my current implementation of the game at least to a lesser extent qualifies for recruitment.

I failed to implement:

- Reading settings from files (map.txt, orders.txt and status.txt)
- Most unit tests
- Mediator program
- The mechanism of collecting gold from the mine by workers
- ID system for each character and building
- GUI interface


Thank you for the opportunity to participate in the recruitment process for the position of Junior C++ Developer!

<br/>
<br/>

## Installation and Compilation process in Ubuntu OS

0. You can use 'install.sh' script to install required programs and libs. If you install via script you can skip the next three steps.
1. Download g++ --> *sudo apt-get install g++*.
2. Download cmake --> *sudo apt-get install cmake*.
3. Download libncurses5 --> *apt-get install -y libncurses5-dev*.
4. Download repository from github.
5. Type --> *cmake -B build*.
6. If the project build files have been generated correctly, you can go to /build folder and type --> *make* to create executable file
7. If the build is successfull you can run ./interview ( main program ) and enjoy game!

<br/>
<br/>

### Author: Michal Dudziak