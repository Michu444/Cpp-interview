# INTERVIEW GAME


## Overview

Game called **INSTANCES WAR** created for interview.

Due to the lack of an insufficient amount of free time (studies, work) I was unable to implement the game exactly as 
it is presented in the instructions.


I placed two bases on the map and a Knight unit belong to base '1' and some obstacles. Everything happens on a 12x12 map.
You can of course create units in bases and attack enemy bases, or add them manually in the addTestUnits() method.

I also did not manage to implement the game mechanism with the computer, so you can also control the second player.

<br/>


I am aware that the game still needs a lot of refinement.

I hope that my current implementation of the game at least to a lesser extent qualifies for recruitment.

I failed to implement:

- Reading settings from files (map.txt, orders.txt and status.txt)
- Working unit tests
- Mediator program
- The mechanism of collecting gold from the mine by workers
- ID system for each character and building
- GUI interface


Thank you for the opportunity to participate in the recruitment process for the position of Junior C++ Developer!

<br/>
<br/>

## Installation and Compilation game process in Ubuntu OS

1. Download repository from GitHub.
2. Navigate to the main project folder.
3. You can use 'install.sh' script to install required programs and libs. If you install via script you can skip the next three steps.
4. Download g++ --> *sudo apt-get install g++*.
5. Download cmake --> *sudo apt-get install cmake*.
6. Download ncurses5 --> *sudo apt-get install -y libncurses5-dev*.
5. Type --> *cmake -B build*.
6. If the project build files have been generated correctly, you can go to /build folder and type --> *make* to create executable file
7. If the build is successfully you can run ./interview ( main program ) and enjoy game!


I implemented the skeleton of two unit tests, but I haven't connected them to the project yet due to lack of time.
I wanted to use the *gtest* framework.

<br/>

### Author: Michal Dudziak