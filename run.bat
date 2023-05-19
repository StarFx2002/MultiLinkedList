@echo off

set name=MLL
cd ./Sources && g++ -I ../Headers -o %name% *.cpp && move %name%.exe ../ && cd ../
%name%