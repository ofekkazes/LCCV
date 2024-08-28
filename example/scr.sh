git fetch && git pull
cmake .
make
./takephoto
python /home/specular/transferwee/transferwee.py upload ~/testfir/LCCV/example/test.jpg
