export async function loadCSV(path) {
	const response = await fetch(path);
	const text = await response.text();

	const lines = text.trim().split('\n');

	lines.shift();

	const data = [];

	for (const line of lines) {
		const [km, price] = line.split(',');

		data.push({
			x: Number(km),
			y: Number(price)
		});
	}

	return data;
}