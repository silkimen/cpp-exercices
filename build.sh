#!/bin/bash

for filePath in ./implementation/*.cpp; do
  sourceName="${filePath##*/}"
  targetName="${sourceName%%.cpp}"

  echo "Building '$sourceName' --> Output '$targetName'"
  clang++ -o "./implementation/$targetName" "$filePath"
done