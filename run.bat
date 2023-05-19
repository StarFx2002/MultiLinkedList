@echo off

set name=MLL
cd ./Sources && g++ -o %name% *.cpp && move %name%.exe ../ && cd ../
%name%