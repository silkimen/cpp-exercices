#!/bin/bash

filePath="./implementation/$1.cpp"
sourceName="${filePath##*/}"
targetName="${sourceName%%.cpp}"

echo "Building '$sourceName' --> Output '$targetName'"
clang++ -o "./implementation/$targetName" "$filePath" && ./implementation/$1