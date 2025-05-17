GCC = gcc
CFLAGS = -O3 -std=gnu99 -D_GNU_SOURCE -pthread -lm
OUT_DIR = out
OUT_BIN = $(OUT_DIR)/main

SRC = main.c \
      $(wildcard facil.io/lib/facil/fio.c) \
      $(wildcard facil.io/lib/facil/fiobj/*.c) \
      $(wildcard facil.io/lib/facil/http/*.c)

INCLUDES = -Ifacil.io/lib/facil \
           -Ifacil.io/lib/facil/fiobj \
           -Ifacil.io/lib/facil/http \
           -Ifacil.io/lib/facil/http/parsers

build: $(OUT_BIN)

$(OUT_BIN):
	mkdir -p $(OUT_DIR)
	$(GCC) $(SRC) -o $@ $(CFLAGS) $(INCLUDES)

clean:
	rm -rf $(OUT_DIR)
