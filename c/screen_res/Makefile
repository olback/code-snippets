build:
	gcc -o screen_res.out screen_res.c -lX11 `pkg-config --cflags --libs gtk+-3.0`

run:
	make build
	./screen_res.out