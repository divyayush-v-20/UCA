var express = require("express");
var app = express();

app.use("/", express.static("./lect1/frontend"))

app.listen(8080);