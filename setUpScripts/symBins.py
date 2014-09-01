#!/usr/bin/python

import shutil, os, argparse, sys, stat, fnmatch

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-dest', type=str, nargs=1, required = True)
    return parser.parse_args()

def main():
    args = parse_args()
    currentDirs = os.listdir(args.dest[0])
    for d in currentDirs:
        if os.path.isdir(d):
            nextDirs = fnmatch.filter(os.listdir(d), 'bin') 
            if nextDirs:
                for e in os.listdir(os.path.realpath(os.path.join(d,nextDirs[0]) )):
                    print e
                    os.symlink(os.path.realpath(os.path.join(d,nextDirs[0], e) ), os.path.realpath(os.path.join(args.dest[0], "bin", e) )) 
    
main()
