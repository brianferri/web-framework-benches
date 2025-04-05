GXX = g++

default:
	mkdir -p "$(shell pwd)/include"
	$(MAKE) -C uWebSockets/uSockets
	mv uWebSockets/uSockets/uSockets.a "$(shell pwd)/include/"
	$(MAKE) -C uWebSockets/uSockets clean

build: default
	mkdir -p "$(shell pwd)/out"
	$(GXX) -o out/main main.cpp -O3 -pthread -IuWebSockets/src -IuWebSockets/uSockets/src -lz include/uSockets.a

clean:
	rm -rf "./include"
	rm -rf "./out"