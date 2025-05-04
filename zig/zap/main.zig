const std = @import("std");
const zap = @import("zap");

fn on_request(r: zap.Request) !void {
    r.sendBody("Hello World!") catch return;
}

pub fn main() !void {
    var listener = zap.HttpListener.init(.{
        .port = 3000,
        .on_request = on_request,
    });
    try listener.listen();
    zap.start(.{
        .threads = 1,
        .workers = 1,
    });
}
