# Josephus Problem using Doubly Circular Linked List in C


## Table of Contents
- [Introduction](#introduction)
- [Project Description](#project-description)
- [Installation](#installation)
- [Input File](#input-file)
- [Usage](#usage)
- [Example](#example)

## Introduction

This project implements the Josephus problem using a doubly circular linked list in the C programming language. The Josephus problem is a theoretical problem related to a famous historical event where a group of people is standing in a circle and every __`k`th__ person is eliminated in a clockwise or anticlockwise direction until only one person remains. The task is to find the position of the last person standing. This problem has practical applications in computer science, such as memory allocation and task scheduling.


## Project Description
In this project, I use a doubly circular linked list data structure to model the circle of people. The program reads a file named `names.txt`, which contains 100 names of different lengths. These names are assigned to the persons in the circular linked list. Each node in the list represents a person, and we connect them in a circular manner to form a circle.

The user will be prompted to enter the following options:

1. **Number of Persons (max 100):** This should be a positive integer not exceeding 100.
2. **Starting Point:** The position of the person from where the elimination process begins. This should be a positive integer between 1 and the total number of persons.
3. **Position of the Person to be Killed:** The k i.e. position of which person to be eliminated. This should be a positive integer between 2 and the total number of persons.
4. **Direction (Clockwise/Anticlockwise):** The direction in which the elimination process proceeds.

The program will then perform the elimination process according to the provided inputs and determine the position of the last person standing.


## Installation
1. Make sure you have a C compiler installed on your system (e.g., GCC).
2. Clone this repository to your local machine using **git clone**.
3. Navigate to the project directory.
    

## Input File
The program reads the **names.txt** file, which contains 100 names, each on a separate line. These names will be assigned to the persons in the circular linked list for the Josephus problem.

Ensure that the __names.txt__ file is formatted correctly, with one name per line.


## Usage

1. Compile the C program using your C compiler.
2. Run the compiled program


## Example
Suppose the `names.txt` file contains 100 names, and the user wants to solve the Josephus problem with 8 persons, starting from the 3rd person, eliminating every 3rd person in a clockwise direction. The program will output the position of the last person standing along with their name.

 ``` C

  Welcome to the text based Josephus Problem Program.

  Enter the total number of people (max 100): 8

  Enter starting point(1 to 8): 3

  Enter position of which person should be killed (2 to 8): 3

  Enter direction clockwise/anti-clockwise (c or a): c
  Person 3:     Name:   Fakhar
  Person 4:     Name:   Qadeer
  Person 5:     Name:   Barlas
  Person 6:     Name:   Ahmad
  Person 7:     Name:   Omair
  Person 8:     Name:   Jawad
  Person 1:     Name:   Abu Bakar
  Person 2:     Name:   Naqqash
  are sitting in a Circle.


  Remaining people after 1 iteration
  Person 4:     Name:   Qadeer
  Person 6:     Name:   Ahmad
  Person 7:     Name:   Omair
  Person 1:     Name:   Abu Bakar
  Person 2:     Name:   Naqqash



  Remaining people after 2 iteration
  Person 6:     Name:   Ahmad
  Person 1:     Name:   Abu Bakar
  Person 2:     Name:   Naqqash



  Remaining people after 3 iteration
  Person 6:     Name:   Ahmad
  Person 1:     Name:   Abu Bakar



  Remaining people after 4 iteration
  Person 1:     Name:   Abu Bakar



  So the winning person is
  Person 1:     Name:   Abu Bakar

  Exiting the program!
 ``` 
