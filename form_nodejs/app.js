const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');

const app = express();
const port = 3000;

app.use(bodyParser.urlencoded({ extended: true }));

app.get('/', (req, res) => {
	res.sendFile(__dirname + '/index.html');
});

app.post('/submit', (req, res) => {
	const formData = req.body;
	// 로컬에 데이터 저장
	fs.writeFileSync('data.txt', JSON.stringify(formData));
	res.send('Form data submitted and saved!');
});

app.listen(port, () => {
	console.log(`Server is running at http://localhost:${port}`);
});
