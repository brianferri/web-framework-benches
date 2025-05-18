const std = @import("std");
const net = std.net;
const http = std.http;

pub fn main() !void {
    const addr = try net.Address.parseIp4("127.0.0.1", 3000);
    var server = try addr.listen(.{
        .reuse_address = true,
        .reuse_port = true,
    });
    try serve(&server);
}

fn serve(server: *net.Server) !void {
    while (true) {
        const connection = try server.accept();
        defer connection.stream.close();

        var buffer: [512]u8 = undefined;
        var http_server = http.Server.init(connection, &buffer);

        _ = try @constCast(&try http_server.receiveHead()).respond("Hello World!\n", .{});
    }
}
