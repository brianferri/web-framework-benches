const uWS = require('uWebSockets.js')

const _ = uWS.App().get('/*', (res, req) => {
  res.end('Hello World!');
}).listen(3000, (_) => { });