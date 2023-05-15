#!/bin/bash

packages=$(apt list --installed)

for package in $packages
do
  echo $package
done
