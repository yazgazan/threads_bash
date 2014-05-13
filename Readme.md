threads\_bash
=============

threads\_bash is a command line tool for threading bash commands.
It's not actually using threads, but the fork & system functions.
It kind of works like a thread pool.

## Usage

```bash
./threads_bash <cmd file> <threads>
```

The cmd file (`-` for stdin) must be a list of commands separated by new lines.

The second argument is the number of commands to be run in parallel.

## Build & Install

(no build system yet :/)

```bash
make
sudo cp threads_bash /usr/local/bin
```


