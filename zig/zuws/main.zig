const zuws = @import("zuws");
const App = zuws.App;
const Request = zuws.Request;
const Response = zuws.Response;

fn handle_client(res: *Response, req: *Request) void {
    _ = req;
    res.end("Hello World!\n", false);
}

pub fn main() !void {
    const app: App = try .init();
    defer app.deinit();

    try app
        .get("/*", handle_client)
        .listen(3000, null);
}
