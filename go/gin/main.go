package main

import (
	"io"
	"runtime"

	"github.com/gin-gonic/gin"
)

func main() {
	runtime.GOMAXPROCS(1)

	gin.SetMode(gin.ReleaseMode)
	gin.DefaultWriter = io.Discard
	r := gin.New()
	r.GET("/", func(c *gin.Context) {
		c.Data(200, "text/plain", []byte("Hello World!"))
	})
	r.Run(":3001")
}
