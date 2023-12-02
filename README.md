# Packet Tracer Assistant

![img1](https://cdn.discordapp.com/attachments/800450151969456200/1180575178548322345/image.png?ex=657deb50&is=656b7650&hm=8d617448a89314e9e8d553cb56f6aef379b4563318f4c5728fd8c5288d5978c5&)

This program will make configuraiton prompts for you.
Soported protocols:
  - SSH
  - DHCPv4 on Router
  - HSRP
  - OSPF
  - RIP
  - Trunk Config

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

