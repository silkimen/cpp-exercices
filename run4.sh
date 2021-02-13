#!/bin/bash

filePath="./implementation/Ilkimen_Sergen_1610216_Aufgabe_4.cpp"
sourceName="${filePath##*/}"
targetName="${sourceName%%.cpp}"

echo "Building '$sourceName' --> Output '$targetName'"
clang++ -o "./implementation/$targetName" "$filePath" && ./implementation/$targetName