# bv2av - an av <=> bv converter

## Description

An av <=> bv converter, command-line program.

## Status

av => bv: available  
bv => av: available

## Usage

```shell
bv2av (enc/dec) string
```

notice if you are using enc mode then you shouldn't add prefix `av` before the number.  

## Source

based on `mcfx`'s code and algorithm. Link below:

https://www.zhihu.com/question/381784377/answer/1099438784

## Strange thing

When developing this tool, I found that it's strange when decoding bv => av. it always have a bug while multiplying. I fixed it in a clumsy way, and I still haven't tested it yet on other platforms...

## Compile

Tested on `Win32` platform.  
compile with `g++`using the single `bv2av.cc` in directory `src`.

Intend to add a `makefile` later.

## License

This tool is licensed under `WTFPL`, just do what you want to do.

## Contribute

Have a look at the strange stuff in my comments! Pull-Request is strongly welcomed!

