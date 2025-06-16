# Minecraft shop script script generator
Application made by Dylan Beppu  
Inspired by [gabedala](https://www.youtube.com/@gabedala)

## About
Based on Youtube user [gabedala](https://www.youtube.com/@gabedala) tutorials on making a minecraft [scoreboard shop](https://youtu.be/874Cvdg-gNA?si=KaSbctfDGIqeM8yf) and [npc](https://youtu.be/mDe2l9E5OWU?si=YjMMu1r2xs6yWaMP) systems. This is a program to create the scripts for the npc tutorial.

## Requirements
* gcc compiler >= 12.1.0
> For a install tutorial, see [GeekforGeeks guide on installing MInGW tools fo C/C++](https://www.geeksforgeeks.org/cpp/installing-mingw-tools-for-c-c-and-changing-environment-variable/)


## Instructions

### How to compile

1. Make sure that gcc is installed
2. Go to the root directery of this repo clone
3. Open command prompt in this directory
4. Run ``g++ main.cpp -o CSVtoScript`` in the command prompt

### Usage

To use this program, run in command prompt where the executable is located:
```
./CSVtoScript <File name here>
```
### CSV file setup

The csv is formatted as fallows
* First column  = item name (as it is when using the give command)
* Second column = buy/sell (what the npc will do with the item)
* Third column = Price number (what the buy/sell price of the item is)
* Fourth column =  quantity number (how much to buy/sell)

This is a example of the npc selling 10 iron for 100 currency, and buying 1 diamond for 100 currency.

```
item, buy/sell, value, quantity
diamond, buy, 100, 1
iron_ingot, sell, 10, 100
```
> Note that the first row is a header row and will be ignored by the program.


### Advanced setup (or need to change things)
There are several global variables located at the top of the main.cpp file that can be changed to configure the program to a new state.

* SCOREBOARD_VALUE - Scoreboard vlaue that is use as the currency.
* ERROR_COLOR - Color of the error text.
* SUCCESS_COLOR - Color of the success text.
* ERROR_SOUND - Minecraft sound that is used as the error sound
* SUCCESS_SOUND - Minecraft sound that is used as the success sound