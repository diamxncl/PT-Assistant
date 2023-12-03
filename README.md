# Packet Tracer Assistant

![img0](https://cdn.discordapp.com/attachments/824682628455071795/1180835429306605618/image.png?ex=657eddb1&is=656c68b1&hm=902031f6295f46accf874b589b5431212c3254ac2b05ecd0046facc2bfca1a31&)


![img1](https://cdn.discordapp.com/attachments/824682628455071795/1180835470863773696/image.png?ex=657eddbb&is=656c68bb&hm=62026385627ba3918ea034c3f255a9a3164f1e5cb893f5f6a5627b98235a85f7&)

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

