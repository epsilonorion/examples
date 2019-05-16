#!/bin/bash

echo "Batch script that runs all application example programs"

for file in ../bin/*
do
  echo "**************************************************"
  echo "Executing: $file"
  echo "**************************************************"

  "$file"
done
