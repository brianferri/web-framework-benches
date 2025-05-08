import { Elysia } from "elysia";

const _ = new Elysia()
  .get("/", () => "Hello World!")
  .listen(3000);

