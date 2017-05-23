x = 42;
y = x + 1;
let z;
if (!z && x > -y || false) {
	let x = 0;
	y = ++x || null;
	if (y--) {
		let x = "IFN";
		let y = x + 660;
		console.log("Layer 3 - IfStatement");
		console.log(x);
		console.log(y);
	} else {
		let y = 43;
		console.log("Layer 3 - ElseStatement");
		console.log(x);
		console.log(y);
	}
	console.log("Layer 2");
	console.log(x);
	console.log(y);
}
console.log("Root");
console.log(x);
console.log(y);