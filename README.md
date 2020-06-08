# MusicBeeper
Beep... beep... beeeeeeeeeeeeeep...

## Available songs
1. GoT soundtrack
2. Imperial march
3. Soviet Anthem
4. Ode to Joy

## Build
Make sure that you made **/dev/input/by-path/platform-pcspkr-event-spkr** device available:
```sh
sudo modprobe pcspkr
```
```sh
git clone
cmake -B ./build -G ...
cd build
cmake --build .
./MusicBeeper
```
