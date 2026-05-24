export function buildLine(theta0, theta1, data) {
	let minX = Math.min(...data.map(p => p.x));
	let maxX = Math.max(...data.map(p => p.x));

	return [
		{
			x: minX,
			y: theta0 + theta1 * minX
		},
		{
			x: maxX,
			y: theta0 + theta1 * maxX
		}
	];
}