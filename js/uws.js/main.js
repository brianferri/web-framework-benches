const uWS = require('uWebSockets.js')
const port = 3000;

const app = uWS.App().get('/*', (res, req) => {
  res.end('Hello World!');
}).listen(port, (_) => {});