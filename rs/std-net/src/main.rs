use std::io::{Read, Write};
use std::net::{TcpListener, TcpStream};

fn handle_client(mut stream: TcpStream) {
    let mut buffer = [0; 1024];

    if let Ok(_) = stream.read(&mut buffer) {
        let response = "HTTP/1.1 200 OK\r\n
        Content-Type: text/plain\r\n
        Content-Length: 13\r\n
        \r\n
        Hello World!";
        let _ = stream.write_all(response.as_bytes());
    }
}

fn main() {
    let listener = TcpListener::bind("127.0.0.1:3000").expect("Could not bind to port 3000");

    for stream in listener.incoming() {
        if let Ok(stream) = stream {
            handle_client(stream);
        }
    }
}
