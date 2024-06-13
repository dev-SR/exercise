import express from 'express';

const app = express();
const port = process.env.PORT || 3000;
const environment = process.env.NODE_ENV || 'development';

app.get('', async (req, res) => {
	res.json({ message: 'Hello World!' });
});

app.listen(port, () => {
	console.log(`Service running at http://localhost:${port} in ${environment} mode.`);
});
