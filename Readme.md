threads\_bash
=============

threads\_bash is a command line tool for threading bash commands.
It's not using threads actually, but fork & system.
It works kind of like a thread pool.

## Usage

```
./threads_bash <cmd file> <threads>
```

The cmd file (`-` for stdin) must be a list of commands separated by new lines.

The second argument is the number of command to be run in parallel.

## Build & Install

```shell
make
cp threads_bash /usr/local/bin
```


