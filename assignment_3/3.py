#!/usr/bin/env python3

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('file_r', type=argparse.FileType('r'))
parser.add_argument('file_w', type=argparse.FileType('w'))
args = parser.parse_args()

for line in args.file_r:
    args.file_w.write(line)
