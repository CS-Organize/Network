import express from "express";

const app = express();

// access POST request body
app.use(express.json());

app.get("/", (req, res) => {
  res.send(req.body);
});

app.post("/", (req, res) => {
  // echo server - send back the request body
  res.send({
    headers: req.headers,
    body: req.body,
  });
});

app.listen(3000, () => {
  console.log("Server is running on http://localhost:3000");
});
