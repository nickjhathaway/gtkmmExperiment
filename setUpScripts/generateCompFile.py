#!/usr/bin/python

import shutil, os, argparse, sys, stat

def generateCompfileFull(outFileName, externalDirLoc, cc, cxx, outName, installDirName, installDirLoc, neededLibs):
    availableLibs = ["CPPITERTOOLS","CPPPROGUTILS","ZI_LIB","BOOST","R","BAMTOOLS","CPPCMS","MATHGL","ARMADILLO","MLPACK","LIBLINEAR","PEAR","CURL","GTKMM", "BIBCPP"]
    neededLibs = map(lambda x:x.upper(), neededLibs)
    """@todo: Make some of these default to an envirnment CC and CXX and maybe even CXXFLAGS as well 
        @todo: Make availableLibs a more universal constant"""
    with open(outFileName, "w") as f:
        f.write("CC = {CC}\n".format(CC = cc))
        f.write("CXX = {CXX}\n".format(CXX = cxx))
        f.write("CXXOUTNAME = {NAME_OF_PROGRAM}\n".format(NAME_OF_PROGRAM = outName))
        f.write("CXXFLAGS = -std=c++11 -Wall\n")
        f.write("CXXOPT += -O2 -funroll-loops -DNDEBUG  \n")
        f.write("ifneq ($(shell uname -s),Darwin)\n")
        f.write("\tCXXOPT += -march=native -mtune=native\n" )
        f.write("endif\n")
        f.write("\n")
        f.write("#debug\n")
        f.write("CXXDEBUG = -g -gstabs+ \n")
        f.write("INSTALL_DIR={INSTALL_LOCATION}\n".format(INSTALL_LOCATION = os.path.join(installDirLoc,installDirName)))
        f.write("EXT_PATH=$(realpath {EXTERNAL})\n".format(EXTERNAL = externalDirLoc))
        f.write("SCRIPTS_DIR=$(realpath scripts)\n")
        f.write("\n")
        for lib in availableLibs:
            if lib in neededLibs:
                f.write("USE_{LIB} = 1\n".format(LIB = lib))
            else:
                f.write("USE_{LIB} = 0\n".format(LIB = lib))
def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-CC', type=str, nargs=1)
    parser.add_argument('-CXX', type=str, nargs=1)
    parser.add_argument('-outname', type=str, nargs=1)
    parser.add_argument('-outFilename', type=str, nargs=1, required = True)
    parser.add_argument('-externalLoc', type=str, nargs=1)
    parser.add_argument('-prefix', type=str, nargs=1)
    parser.add_argument('-installName', type=str, nargs=1)
    parser.add_argument('-neededLibs', type=str, nargs=1)
    return parser.parse_args()

def main():
    """@todo: Also add on adding CXXFLAGS or LDFLAGS and the such or look for environment ones"""
    args = parse_args()
    CC ="gcc-4.8"
    CXX = "g++-4.8"
    external = "external"
    outname = "out"
    prefix = "./"
    installName = "out"
    neededLibs = "none"
    if not args.CC:
        eCC = os.getenv("CC")
        if(eCC):
            CC =  eCC
    else:
        CC = args.CC[0]
    
    if not args.CXX:
        eCXX = os.getenv("CXX")
        if  eCXX:
            CXX = eCXX
    else:
        CXX = args.CXX[0]
        
    if args.externalLoc:
        external = args.externalLoc[0]
    if args.outname:
        outname = args.outname[0]
    if args.installName:
        installName = args.installName[0]
    if args.prefix:
        prefix = args.prefix[0]
    if args.neededLibs:
        neededLibs = args.neededLibs[0].split(",")
    generateCompfileFull(args.outFilename[0], external, CC, CXX, outname, installName, prefix, neededLibs)
    
main()
