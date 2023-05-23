#!/bin/bash


if [ $# -eq 0 ]; then
  echo "Invalid action."
  echo "Run 'install.sh -h' to check available options."
  exit 1
fi


while getopts ":gclah" opt; do
  case ${opt} in
    g)
        echo "g++ Installation"
        sudo apt-get update
        sudo apt-get install -y g++
        ;;
    c)
        echo "cmake installation"
        sudo apt-get update
        sudo apt-get install -y cmake
        ;;
    l)
        echo "libncurses5 installation"
        sudo apt-get update
        sudo apt-get install -y libncurses5-dev
        ;;
    a)
        echo "cmake, g++ and ncurses lib installation"
        sudo apt-get update
        sudo apt-get install -y g++ cmake
        sudo apt-get install -y libncurses5-dev
        ;;
    h)
        echo "Options:"
        echo "  -g   Install g++"
        echo "  -c   Install cmake"
        echo "  -l   Install libncurses5-dev"
        echo "  -a   Install cmake, g++, and libncurses5-dev"
        echo "  -h   Display available options"
        exit 0
        ;;
    \?)
        echo "Invalid option: -$OPTARG" >&2
        echo "Run 'install.sh -h' to check available options"
        exit 1
        ;;
  esac
done