[![build](https://img.shields.io/travis/amq/bulletin_board.svg)](https://travis-ci.org/amq/bulletin_board)

Building
```
git clone https://github.com/amq/bulletin_board.git
cd bulletin_board
mkdir build
cd build
cmake ..
make
```

Usage
```
./simple_message_client -s server -p port -u user [-i image URL] -m message [-v] [-h]
./simple_message_server -p port [-h]
```
