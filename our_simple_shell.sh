#!/bin/bash
while true; do
read -p "$ " command
#excute
eval "$command"
done
