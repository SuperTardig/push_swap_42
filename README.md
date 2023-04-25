# push_swap
The goal of this 42 school project is to create a sorting algorithm that uses 2 stacks and 11 different move. This project helps us learn the basics of algorithms and an introduction to the concept of complexity. There is a maximum number of moves that could be done before failling the project. The program takes a list of positive or negative number within the limits of an int.
## Operations
The operations that we had acces to are the following:
  - pa (push a): Take the first element at the top of **b** and put it at the top of **a**
  - pb (push b): Take the first element at the top of **a** and put it at the top of **b**
  - sa (swap a): Swap the first 2 elements at the top of stack **a**
  - sb (swap b): Swap the first 2 elements at the top of stack **b**
  - ss: **sa** and **sb** at the same time
  - ra (rotate a): Shift up all elements of stack **a** by 1
  - rb (rotate b): Shift up all elements of stack **b** by 1
  - rr: **ra** and **rb** at the same time
  - rra (reverse rotate a): Shift down all elements of stack **a** by 1
  - rrb (reverse rotate b): Shift down all elements of stack **b** by 1
  - rrr: **rra** and **rrb** at the same time
## Bonus
The bonus requirement for this project is the creation of a checker program. This program takes the same arguments has the main one. You can either use it by piping the output of the main program or manually writing the operations. It will then write the number of moves that have been made and if the numbers have been sorted.
## Usage
To use the mandatory part of this project, you need to:
1. Clone this repository
2. Go to the root of the repository and use `make`
3. Run `./push_swap <list of numbers>`

To use the bonus part of this project, you need to:

  - To use with the main program:
  1. Clone this repository
  2. Go to the root of the repository and use `make` and `make bonus`
  3. Run `./push_swap <list of numbers> | ./checker <list of numbers>`
  
  - To use alone:
  1. Clone this repository
  2. Go to the root of the repository and use `make`
  3. Run `./checker <list of numbers>`
  4. Then run the operation you want
  5. Finish by pressing `"CTRL-D"`
