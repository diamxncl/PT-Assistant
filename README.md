# Packet Tracer Assistant

![img1](https://cdn.discordapp.com/attachments/800450151969456200/1180610735806623754/image.png?ex=657e0c6e&is=656b976e&hm=3373cf635545a5406d9c095ccfb5121169ec050ab2bc73ce0449ee15ac4985d5&)

This program will make configuration prompts for you.

Supported protocols:
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
Then install the following programs: 
  ```bash
  sudo apt install g++ figlet
  ```

To compile the file with g++, do:
  ```bash
  g++ pt-assistant.cpp -o PTAssistant.out
  ```

Then execute it with:
  ```bash
  ./PTAssistant.out
  ```

