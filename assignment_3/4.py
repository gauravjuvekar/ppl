#!/usr/bin/enb python3

import re
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('file_r', type=argparse.FileType('r'))
args = parser.parse_args()

line_re = re.compile(
    r'^\s*(?P<name>.+?)\s+(?P<marks>\d+\.?\d*)\s*$',
    re.MULTILINE)

convert = lambda _: {'name': _['name'], 'marks': int(_['marks'])}
students = [
    convert(line_re.match(line).groupdict())
    for line in args.file_r if line != '\n']

above_70 = filter(lambda s: s['marks'] >= 70, students)
counts = [
    (
        student['marks'],
        len(list(filter(lambda _:_['marks'] == student['marks'], students))))
    for student in students]

print(list(above_70))
print(counts)
