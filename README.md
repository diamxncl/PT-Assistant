# Packet Tracer Assistant

This program will make configuraiton prompts for you

## How to build

First you need to clone this repository.

  ```bash
  git clone https://github.com/diamxncl/PT-Assistant
  ```
Go into the directory you just cloned:

  ```bash
  cd PT-Assistant
  ```

You will need to compile the file before using it.
To compile it you can install g++ in your linux by doing this:

First update your linux:
  ```bash
  sudo apt update
  ```
Then install the program: 
  ```bash
  sudo apt install g++
  ```

To compile the file with g++, do:
  ```bash
  g++ pt-assistant.cpp -o PTAssistant.out
  ```

Then execute it with:
  ```bash
  ./PTAssistant.out
  ```

