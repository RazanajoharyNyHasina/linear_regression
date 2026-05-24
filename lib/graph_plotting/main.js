import { loadCSV } from "./loadCSV.js";
import { buildLine } from "./buildLine.js";
import { computeR2 } from "./r2.js";

const canvas_node = document.getElementById("Chart");

const points = await loadCSV("./data.csv");
const regression_data = await loadCSV("./training_data.csv");
const linePoints = buildLine(regression_data[0].x, regression_data[0].y, points);

new Chart(canvas_node, {
	type: 'scatter',
	data: {
		datasets: [
			{
				label: "Cars",
				data: points,

			},
			{
				label: "Price",
				data: linePoints,
				type: 'line'
			}
		]
	}
})

const r2 = computeR2(points, regression_data[0].x, regression_data[0].y);
const paragraph = document.getElementById("PrecisionText");
paragraph.innerHTML = `The precision of your algorithm are ${r2}`;