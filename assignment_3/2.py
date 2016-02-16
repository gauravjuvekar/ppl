#!/usr/bin/env python3

try:
    while True:
        print(eval(input(">>> ").replace('i', 'j')))
except KeyboardInterrupt:
    pass
