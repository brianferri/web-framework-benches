import uvicorn
from fastapi import FastAPI
from uvicorn.config import LOG_LEVELS

app = FastAPI()

@app.get("/")
async def root():
    return "Hello World"

if __name__ == "__main__":
    uvicorn.run(
        app,
        port=3000,
        log_level=LOG_LEVELS["critical"]
    )
