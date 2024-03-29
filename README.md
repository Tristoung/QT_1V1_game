QT Game 1V1

Installation instruction for Debian 12 : 

Install qmake :
  sudo apt update
  sudo apt install qt5-qmake

Install the project :
  git clone https://github.com/Tristoung/QT_1V1_game.git
  cd QT_1V1_game

Make a build folder :
  mkdir build
  cd build

Generate construction files :
  qmake ..

Compile project :
  make

Execute project :
  ./1v1
