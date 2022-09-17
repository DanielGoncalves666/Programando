use std::io;

fn main() {
	let mut a = String::new();
	let mut b = String::new();
	let mut c = String::new();

	io::stdin()
		.read_line(&mut a)
		.expect("Falha 1");
	io::stdin()
		.read_line(&mut b)
		.expect("Falha 2");
	io::stdin()
		.read_line(&mut c)
		.expect("Falha 3");

	let a: f64 = a.trim().parse().expect("Falha 4");
	let b: f64 = b.trim().parse().expect("Falha 5");
	let c: f64 = c.trim().parse().expect("Falha 6");

	let media = (a * 2.0 + b * 3.0 + c * 5.0) / 10.0;

	println!("MEDIA = {:.1}",media);
}