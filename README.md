# Packet Tracer Assistant

![img0](https://cdn.discordapp.com/attachments/824682628455071795/1180833954916487219/image.png?ex=657edc51&is=656c6751&hm=c8c477ff574a8e5f881a10bf9433f3c7a21b53d084a94e13107236aec0581d75&)
![img1](https://cdn.discordapp.com/attachments/824682628455071795/1180834198840414309/image.png?ex=657edc8b&is=656c678b&hm=ba3719fec1a8cb63d07755a184b69d4ebc044e546fca717b384116785e3ccdc2&)

This program will make configuration prompts for you.

Supported protocols:
  - SSH
  - DHCPv4 on Router
  - HSRP
  - OSPF
  - RIP
  - Trunk Config
  - Router dot1Q

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

