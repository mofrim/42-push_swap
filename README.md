# 42-minitalk
42's Minitalk Project

## Progress

- somehow it already fulfills all the bonus requirements 🙃. even unicode chars are
working because we send/receive print raw bytes 🥳

# Notes

## How to start msg transfer?

maybe send a SIGUSR1 then sleep for 100usec then send the msg with 5 usec pause
in between bits. but how to stop? maybe just by using control chars. Stop would
be sending NUL = 0 = 0000000 = 7x SIGUSR1. Start would be 1111111 = 7x SIGUSR2.

## nice command for stress-testing

```sh
for i in $(seq 1 100); do ./client 529054 "$(echo $(seq 100 200) | tr -d "\n")"; done 

```
