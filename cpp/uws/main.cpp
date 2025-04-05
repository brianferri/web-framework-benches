#include "uWebSockets/src/App.h"

int main() {
    uWS::App().get("/*", [](auto *res, auto *) {
        res->end("Hello world!");
    }).listen(3000, [](auto *listen_socket) {}).run();
}
