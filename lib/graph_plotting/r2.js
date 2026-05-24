export function computeR2(data, theta0, theta1) {
	let mean = 0;

	for (const p of data)
		mean += p.y;

	mean /= data.length;

	let ssRes = 0;
	let ssTot = 0;

	for (const p of data) {
		const predicted = theta0 + theta1 * p.x;

		ssRes += (p.y - predicted) ** 2;
		ssTot += (p.y - mean) ** 2;
	}

	return 1 - (ssRes / ssTot);
}