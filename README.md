# Corewar

## Table of Contents
1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Usage](#usage)
5. [The Champions](#the-champion)
6. [The Arena](#the-arena)

## Introduction
Corewar is a classic programming game, where programs (written in a simplified assembly language) fight in the memory of a virtual computer. These programs, also known as 'champions', have the task to prevent the opponent from executing its code, mainly by causing it to read incorrect instructions. The game ends when all but one of the champions are no longer able to execute any instruction.

## Installation
You'll need GCC and Make to build and run the Corewar game. The code has been tested on Linux and MacOS. 

To clone and build the project, you can run the following commands:

```sh
git clone git@github.com:EpitechPromo2027/B-CPE-200-BDX-2-1-corewar-gaetan.dubernat.git
make
```
## Usage
There are two main components of this project, the `asm` assembler and the `corewar` virtual machine.

### Assembler (asm)
This will convert an assembly code file (.s file) into bytecode (.cor file) which can be run in the virtual machine. The usage is:

```sh
./asm [champion.s]
```
This will create a .cor file with the same name as the .s file.

### Coreware (VM)
This is the virtual machine in which the champions will fight. You can run up to 4 champions in one game. The usage is:
```sh
./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
```
-dump nbr_cycle dumps the memory after the nbr_cycle execution
-n prog_number sets the next program’s number.
-a load_address sets the next program’s loading address. When no address is
specified, optimize the addresses so that the processes are as far
away from each other as possible.

## The Champions

The champions are the competitors in the Corewar game. Each champion is a program written in asm, a low-level language specific to the Corewar game. The objective for each champion is to stay "alive" by making sure its code continues to execute within the arena.

Here is an example of a simple champions program:

## The Arena

The game happens in a virtual environment called "The Arena". The arena is a circular buffer of `MEM_SIZE` bytes. This memory is initialized with the programs of each champion. The champions are loaded into memory one after another, starting at the zero address, and they all begin executing from their starting position.

Each champion's program is executed sequentially by a virtual process. A new process is created at the time of the champion's launch. During the execution of a program, new processes can be created, and existing processes can be killed.
```sh
.name "Jon Snow"
.comment "Winter is coming"
sti r1, %:crow, %1
crow: live %234
ld %0, r3
zjmp %:crow
```

