#!/usr/bin/python

import os
import argparse
import subprocess

parser = argparse.ArgumentParser(description='Test app for face recognition')
parser.add_argument('folder', metavar='FOLDER', help='Folder to check against')
parser.add_argument('db', metavar='DB', help='Database to check against')
args = parser.parse_args()
files = os.listdir(args.folder)
false_neg = 0
false_pos = 0
for file in files:
    result = int(subprocess.check_output(["facerecognition", args.folder+'/'+file, args.db]))
    print(str(file) + " -> " + str(result))
    if(result == -1):
        false_neg += 1
        continue
    expected, _ = file.split('_', 1) 
    if(result != int(expected)):
        false_pos += 1
print("False Negatives: " + str(false_neg))
print("False Positives: " + str(false_pos))
